//=============================================================================
// Copyright © 2004 Point Grey Research, Inc. All Rights Reserved.
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
//=============================================================================
// $Id: main.cpp,v 1.26 2009/01/05 19:32:01 hirokim Exp $
//=============================================================================

#include "LBImDAQThread.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define _HANDLE_ERROR \
   if(error != LADYBUG_OK) { \
      printf( \
	 "Error! Ladybug library reported %s\n", \
	  ::ladybugErrorToString(error)); \
      exit(1); \
   } \
\

GRIDAQBaseAccumNode* LBImDAQThread::RegisterDataOutput(QString outName) {
  return NULL;
}

void LBImDAQThread::terminationRoutines() {
  // Destroy the context
  printf("Destroying context...\n");
  LadybugError error = ::ladybugDestroyContext(&context_);
  _HANDLE_ERROR;

  // Clean up the buffers
  for(unsigned int uiCamera = 0; uiCamera < LADYBUG_NUM_CAMERAS; ++uiCamera) {
    delete arp_buffers_[uiCamera];
  }
}

int LBImDAQThread::acquireData(int n) {
  LadybugError error;
  LadybugImage image;
  char pszOutputFilePath[256];

  // Grab a single image.
  printf("Grabbing image...\n");
  error = LADYBUG_FAILED;
  for (int i = 0; i < 10 && error != LADYBUG_OK; ++i) {
    error = ::ladybugGrabImage(context_, &image);
  }
  _HANDLE_ERROR;

  // Set color processing method
  error = ::ladybugSetColorProcessingMethod(context_, LADYBUG_EDGE_SENSING);
  _HANDLE_ERROR;

  unsigned int uiCamera;
  // Allocate memory for the 6 processed images
  for(uiCamera = 0; uiCamera < LADYBUG_NUM_CAMERAS; ++uiCamera) {
    arp_buffers_[uiCamera] = new unsigned char[image.uiRows * image.uiCols * 4];
  }

  // Color-process the image
  error = ::ladybugConvertToMultipleBGRU32(context_, &image, arp_buffers_, NULL);

  // Save the image as 6 individual raw (unstitched, distorted) images
  for(uiCamera = 0; uiCamera < LADYBUG_NUM_CAMERAS; ++uiCamera) {
    LadybugProcessedImage processedImage;
    processedImage.pData = arp_buffers_[uiCamera];
    processedImage.pixelFormat = LADYBUG_BGRU;
    processedImage.uiCols = image.uiCols;
    processedImage.uiRows = image.uiRows;
    sprintf(pszOutputFilePath, "ladybug_image_camera_%02d.bmp", uiCamera);
    error = ::ladybugSaveImage(context_, &processedImage, pszOutputFilePath,
			       LADYBUG_FILEFORMAT_BMP); 
    _HANDLE_ERROR;
    printf("Output to file %s.\n", pszOutputFilePath);
  }
}

int LBImDAQThread::connectToDAQ() {
  LadybugError error;
  LadybugCameraInfo caminfo;

  // Initialize context.
  error = ::ladybugCreateContext(&context_);
  _HANDLE_ERROR;

  // Initialize the first ladybug on the bus.
  printf("Initializing...\n");
  error = ::ladybugInitializeFromIndex(context_, 0);
  _HANDLE_ERROR;

  // Get camera info
  error = ladybugGetCameraInfo(context_, &caminfo);
  _HANDLE_ERROR("ladybugGetCameraInfo()");

  // Start up the camera according to device type and data format
  printf("Starting camera %s...\n", caminfo.pszModelName);

  error = ::ladybugStart(context_, LADYBUG_RESOLUTION_ANY,
			 LADYBUG_DATAFORMAT_COLOR_SEP_SEQUENTIAL_JPEG,
			 LADYBUG_FRAMERATE_ANY);
  _HANDLE_ERROR;
}
