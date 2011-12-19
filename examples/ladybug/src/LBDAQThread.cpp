#include "LBDAQThread.h"
#include <iostream>

const char *LB_FILE_BASE = "/fill/this/in"

  GRIDAQBaseAccumNode* LBDAQThread::RegisterDataOutput(QString outName) {
  GRIDAQBaseAccumNode* p = NULL;
  if (outName == "ADCOutput") {
    p = new GRIDAQAccumulator<double>(outName,1e8,5,250);
  } else if (outName == "CHAN") {
    p = new GRIDAQAccumulator<int>(outName,1e8,5,250);
  } else if (outName == "TS") {
    p = new GRIDAQAccumulator<qint64>(outName,1e8,5,250);
  }
  return p;
}

  int LBDAQThread::connectToDAQ() {
    LADYBUGDLL_API LadybugError error = ladybugCreateVideoContext(context_);
    assert(error == LADYBUG_OK);
  }

int LBDAQThread::acquireData(int n) {
  InitCamera();
  StartRecording();
}

int LBDAQThread::InitCamera() {
  // Initialize context.
  error = ladybugCreateContext(&context_);
  _HANDLE_ERROR;
   
  // Initialize the first ladybug on the bus.
  std::cout << "Initializing..." << std::endl;
  error = ladybugInitializePlus(context_, 0, iNumberOfBuffers, NULL);
  _HANDLE_ERROR;
   
  // Start Ladybug with the specified data format
  std::cout << "Starting camera..." << std::endl;
  error = ladybugStartLockNext(context, LADYBUG_RESOLUTION_ANY,
			       ladybugDataFormat, LADYBUG_FRAMERATE_ANY);
  _HANDLE_ERROR;
   
  // Set color processing method
  error = ladybugSetColorProcessingMethod(context, colorProcessingMethod);
  _HANDLE_ERROR;

  int num_tries = 0;
  do {
    ladybugUnlockAll( context );
    Sleep( 100 );
    error = ladybugLockNext( context, &image_Prev );
  } while ( ( error != LADYBUG_OK )  && ( num_tries++ < 10) );    
  _HANDLE_ERROR;

  // Set the size of the image to be processed
  if(colorProcessingMethod == LADYBUG_DOWNSAMPLE4 || 
     colorProcessingMethod == LADYBUG_MONO ) {
    uiRawCols = image_Prev.uiCols / 2;
    uiRawRows = image_Prev.uiRows / 2;
  } else {
    uiRawCols = image_Prev.uiCols;
    uiRawRows = image_Prev.uiRows;
  }
   
  // Load config file from the head
  printf( "Loading config info...\n" );
  error = ladybugLoadConfig( context, NULL );
  _HANDLE_ERROR;
   
  // Initialize alpha mask
  printf( "Initializing Alpha mask...\n" );
  error = ladybugInitializeAlphaMasks(context, uiRawCols, uiRawRows);
  _HANDLE_ERROR;
  ladybugSetAlphaMasking( context, true );

  // we will use auto buffer usage feature
  printf( "Using Auto JPEG Quality control...\n");
  error = ladybugSetAutoJPEGQualityControlFlag( context, true);
  _HANDLE_ERROR;

  // Set the timeout value for grab function to five seconds.
  ladybugSetGrabTimeout(context, 5000);

  // Allocate memory for the 6 processed images
  for( unsigned int uiCamera = 0; uiCamera < LADYBUG_NUM_CAMERAS; uiCamera++ ) {
    arpBuffers[ uiCamera ] = new unsigned char[ uiRawCols * uiRawRows * 4 ];
  }
   
  return 0;
}

int LBDAQThread::StartRecording() {
  // Start recording
  uiLast_Idle_Time = GetTickCount();
  uiFrameCounter = 0; 
  // Get file name 
  ReadINIFile iniFile;
  ReadINIFile::Error iniFileError; 
  char pszStreamNameOpened[ _MAX_PATH ];
  
  // Open the ini file
  iniFile.open(INI_FILENAME);
         
  // Get stream file base name from ini file
  iniFileError = iniFile.getString(INI_RECORDING_FILE_BASE_NAME,
                                   pszStreamBaseName, _MAX_PATH,
                                   "pgrLadybugStream" );

  iniFile.close();

  if (streamContext == NULL) {
    error = ladybugCreateStreamContext( &streamContext );
    _HANDLE_ERROR;      
  } 
         
  // Used to track image/frame stats
  dTotalMBWritten = 0;
  ulTotalNumberOfImageWritten = 0;
  uiLostFrameCount = 0;
         
  error = ladybugInitializeStreamForWriting(streamContext, pszStreamBaseName, 
                                            context, pszStreamNameOpened);

  if (error != LADYBUG_OK ) {
    error = ladybugStopStream (streamContext);
  }
  _DISPLAY_ERROR_MSG_AND_RETURN;
}
