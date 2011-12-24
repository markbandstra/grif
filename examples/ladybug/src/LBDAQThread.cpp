//=============================================================================
// Copyright © 2007 Point Grey Research, Inc. All Rights Reserved.
// 
// This software is the confidential and proprietary information of Point
// Grey Research, Inc. ("Confidential Information").  You shall not
// disclose such Confidential Information and shall use it only in
// accordance with the terms of the license agreement you entered into
// with Point Grey Research, Inc. (PGR).
// 
// PGR MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF THE
// SOFTWARE, EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
// PURPOSE, OR NON-INFRINGEMENT. PGR SHALL NOT BE LIABLE FOR ANY DAMAGES
// SUFFERED BY LICENSEE AS A RESULT OF USING, MODIFYING OR DISTRIBUTING
// THIS SOFTWARE OR ITS DERIVATIVES.
//=============================================================================

#include "LBDAQThread.h"

#include <iostream>
#include "util.h"

GRIDAQBaseAccumNode* LBDAQThread::RegisterDataOutput(QString outName) {
  return NULL;
}

//=============================================================================
// Clean up
//=============================================================================
void LBDAQThread::terminationRoutines() {
  printf("Destroying context...\n");
  if (context != NULL) {
    error = ladybugDestroyContext(&context);
    _HANDLE_ERROR;
    context = NULL;
  }
   
  if (streamContext != NULL) {
    error = ladybugDestroyStreamContext(&streamContext);
    _HANDLE_ERROR;
    streamContext = NULL;
  }
  return;
}

//=============================================================================
// Initializing recording on the camera
//=============================================================================
int LBDAQThread::startDataAcquisition() {
  uiLast_Idle_Time = GetTickCount();
  uiFrameCounter = 0;   
  // Get file name 
  ReadINIFile iniFile;
  ReadINIFile::Error iniFileError; 
  char pszStreamNameOpened[_MAX_PATH];
         
  // Open the ini file
  iniFile.open(INI_FILENAME);
         
  // Get stream file base name from ini file
  iniFileError = iniFile.getString(INI_RECORDING_FILE_BASE_NAME,
				   pszStreamBaseName, _MAX_PATH,
				   "pgrLadybugStream");

  iniFile.close();

  if (streamContext == NULL) {
    error = ladybugCreateStreamContext(&streamContext);
    _HANDLE_ERROR;      
  } 
         
  // Used to track image/frame stats
  dTotalMBWritten = 0;
  ulTotalNumberOfImageWritten = 0;
  uiLostFrameCount = 0;
         
  error = ladybugInitializeStreamForWriting(streamContext, pszStreamBaseName,
					    context, pszStreamNameOpened);
  bRecordingInProgress = (error == LADYBUG_OK);
  if (bRecordingInProgress) {
    printf("Recording to %s\n", pszStreamNameOpened);
  } else {
    error = ladybugStopStream (streamContext);
  }
  _DISPLAY_ERROR_MSG_AND_RETURN;  
}

int LBDAQThread::stopDataAcquisition() {
  error = ladybugStopStream(streamContext);
  bRecordingInProgress = false;
  _DISPLAY_ERROR_MSG_AND_RETURN;
}

//=============================================================================
// Start the first Ladybug2 camera the bus
//=============================================================================
int LBDAQThread::StartCamera() {
  // Initialize context.
  error = ::ladybugCreateContext(&context);
  _HANDLE_ERROR;
   
  // Initialize the first ladybug on the bus.
  printf("Initializing...\n");
  error = ladybugInitializePlus(context, 0, iNumberOfBuffers, NULL);
  _HANDLE_ERROR;
   
  // Start Ladybug with the specified data format
  printf("Starting camera...\n");
  error = ::ladybugStartLockNext(context, LADYBUG_RESOLUTION_ANY,
                                 ladybugDataFormat, LADYBUG_FRAMERATE_ANY);
  _HANDLE_ERROR;
   
  // Set color processing method
  error = ::ladybugSetColorProcessingMethod(context, colorProcessingMethod);
  _HANDLE_ERROR;

  int iTryTimes = 0;
  do {
    ladybugUnlockAll(context);
    Sleep(100);
    error = ladybugLockNext(context, &image_Prev);
  } while ((error != LADYBUG_OK)  && (iTryTimes++ < 10));
  _HANDLE_ERROR;

  // Set the size of the image to be processed
  if (colorProcessingMethod == LADYBUG_DOWNSAMPLE4 || 
      colorProcessingMethod == LADYBUG_MONO) {
    uiRawCols = image_Prev.uiCols / 2;
    uiRawRows = image_Prev.uiRows / 2;
  } else {
    uiRawCols = image_Prev.uiCols;
    uiRawRows = image_Prev.uiRows;
  }
   
  // Load config file from the head
  printf("Loading config info...\n");
  error = ladybugLoadConfig(context, NULL);
  _HANDLE_ERROR;
   
  // Initialize alpha mask
  printf("Initializing Alpha mask...\n");
  error = ladybugInitializeAlphaMasks(context, uiRawCols, uiRawRows);
  _HANDLE_ERROR;
  ladybugSetAlphaMasking(context, true);

  // we will use auto buffer usage feature
  printf("Using Auto JPEG Quality control...\n");
  error = ladybugSetAutoJPEGQualityControlFlag(context, true);
  _HANDLE_ERROR;

  // Set the timeout value for grab function to zero.
  // Do not wait if there is no image waiting. 
  ladybugSetGrabTimeout(context, 0);

  return 0;
}

//=============================================================================
// Grab and save images. Display an image only if no image waiting for writing
//=============================================================================
int LBDAQThread::acquireData(int n) {
  char     pszTimeString[128];
  double   dTimeDiff = 0;
   
  error = ladybugLockNext(context, &image_Current);

  if (error == LADYBUG_OK) {
    // Save the image to disk
    if (streamContext != NULL  && bRecordingInProgress) {
      error = ladybugWriteImageToStream(streamContext, &image_Current,
                                        &dTotalMBWritten, 
                                        &ulTotalNumberOfImageWritten);
      if (error == LADYBUG_OK) {  
	uiLostFrameCount += image_Current.uiSeqNum - image_Prev.uiSeqNum - 1;

	// Calculate frame rate
	dTimeDiff = ((image_Current.timeStamp.ulCycleSeconds * 8000.0 + 
		      image_Current.timeStamp.ulCycleCount) -  
		     (image_Prev.timeStamp.ulCycleSeconds * 8000.0 + 
		      image_Prev.timeStamp.ulCycleCount)) / 8000.0;
	dFrameRate =  1.0 / dTimeDiff; 
	sprintf(pszTimeString, 
                "Grab and Save:%4.1ffps TotalData:%.1fMB Frames:%d Lost:%d", 
		dFrameRate, dTotalMBWritten, ulTotalNumberOfImageWritten,
                uiLostFrameCount);
      } else {
	// stop recording
        return -1;
      }
    }
    ladybugUnlock(context, image_Prev.uiBufferIndex);
    image_Prev = image_Current;
    _DISPLAY_ERROR_MSG_AND_RETURN; 
  } else {
    ladybugUnlockAll(context);
    _DISPLAY_ERROR_MSG_AND_RETURN; 
  }
}

int LBDAQThread::connectToDAQ() {
  loadIniFile();
  StartCamera();
}

int LBDAQThread::loadConfiguration() {
  error = ladybugConfigureOutputImages(context,
                                       LADYBUG_PANORAMIC | LADYBUG_DOME);
  _HANDLE_ERROR;
}

