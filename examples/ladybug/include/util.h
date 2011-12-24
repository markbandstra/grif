#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <assert.h>

#include <ladybug.h>
#include <ladybuggeom.h>
#include <ladybugRenderer.h>
#include <ladybugStream.h>

// Macros to check, report on, and handle Ladybug API error codes.
#define _HANDLE_ERROR \
  if (error != LADYBUG_OK) { \
      printf("Error! Ladybug library reported %s\n", \
	     ::ladybugErrorToString(error)); \
      assert(false); \
      exit(1); \
    } \

#define _DISPLAY_ERROR_MSG_AND_RETURN \
  if (error != LADYBUG_OK) { \
      printf("Ladybug library reported %s\n", \
	     ::ladybugErrorToString(error)); \
      return; \
    } \
  
// INI file name
#define  INI_FILENAME "ladybugSimpleRecording.ini"

// INI file keys
#define INI_RECORDING_FILE_BASE_NAME   "BaseStreamName"
#define INI_WINDOW_POSITION_X          "WindowPositionX"
#define INI_WINDOW_POSITION_Y          "WindowPositionY"
#define INI_WINDOW_SIZE_WIDTH          "WindowSizeWidth"
#define INI_WINDOW_SIZE_HEIGHT         "WindowSizeHeight"
#define INI_NUMBER_OF_BUFFERS          "NumberOfBuffers"
#define INI_RECORDING_AUTO_START       "RecordingAutoStart"
#define INI_LADYBUG_RESOLUTION         "LadybugResolution"
#define INI_DATA_FORMAT                "DataFormat"
#define INI_FRAME_RATE                 "FrameRate"
#define INI_COLOR_PROCESSING_METHOD    "ColorProcessingMethod"
#define INI_INITIAL_DISPLAY_TYPE       "InitialDisplayType"
#define INI_JPEG_COMPRESSION_QUALITY   "JPEGCompressionQuality"

// Values in INI file
char                          pszStreamBaseName[_MAX_PATH];
int                           iWindowPositionX;
int                           iWindowPositionY;
int                           iWindowSizeWidth;
int                           iWindowSizeHeight;
int                           iNumberOfBuffers;
bool                          bRecordingAutoStart;
LadybugDataFormat             ladybugDataFormat;
LadybugColorProcessingMethod  colorProcessingMethod;

// Define display mode
enum {
  MENU_PANORAMIC = 1,	      // Display Pamoramic 
  MENU_ALL_CAMERAS,	      // Display all camera images in one view
  MENU_DOME,		      // Display dome view
};

static unsigned long	uiLast_Idle_Time;
unsigned int	        uiFrameCounter = 0;
unsigned int            uiLostFrameCount = 0;
double                  dFrameRate = 0;
double                  dTotalMBWritten = 0;
unsigned long           ulTotalNumberOfImageWritten = 0;
unsigned int            uiRawCols = 0;
unsigned int            uiRawRows = 0;
bool                    bFullScreenMode = false;
bool			bTextureUpdated = false;

LadybugOutputImage      uiDisplayMode = LADYBUG_PANORAMIC;

LadybugContext          context = NULL;            // Ladybug context
LadybugStreamContext    streamContext = NULL;      // Ladybug stream context
LadybugError            error;	                   // Ladybug error message
LadybugImage            image_Current, image_Prev; // Ladybug image
bool                    b[256];                    // keyboard state
bool                    bRecordingInProgress = false;

//=============================================================================
// A class for reading INI file.  
// The "default" value passed to "get" arguments will be returned 
// if the key is not found in the .ini file.
//=============================================================================
class ReadINIFile {
public:
  // Error codes returned by methods of this class.
  enum Error {
    OK,
    FILE_NOT_FOUND,
    FILE_ERROR,
    KEY_NOT_FOUND,
  };

  ReadINIFile() {
    m_pfile = NULL;
  }

  virtual ~ReadINIFile() {
    close();
  };

  // Open an .ini file.  This must be done before any other operation.  
  Error open(const char* pszFilename) {
    m_pfile = ::fopen(pszFilename, "r");
    if (m_pfile == NULL) {
      return FILE_ERROR;
    } else {
      return OK;
    }
  }

  // Close the current .ini file.
  void close() {
    if (m_pfile != NULL) {
      ::fclose(m_pfile);
      m_pfile = NULL;
    }
  }

  // Get a string value.
  Error getString(const char* pszKey, char* pszValue, int iSize,
                  const char* pszDefault) {
    if (m_pfile == NULL) {
      strncpy(pszValue, pszDefault, iSize);
      return FILE_NOT_FOUND;
    }
      
    char pszTempVal[ _MAX_PATH ];
    Error error = readKey(pszKey, pszTempVal);
      
    if (error == OK) {
      strncpy(pszValue, pszTempVal, iSize);
    } else {
      strncpy(pszValue, pszDefault, iSize);      
    }
      
    return error;
  }

  // Get an integer value.
  Error getInt(const char* pszKey, int* piValue, const int iDefault) {
    if (m_pfile == NULL) {
      *piValue = iDefault;
      return FILE_NOT_FOUND;
    }
      
    char pszTempVal[_MAX_PATH];
    Error error = readKey(pszKey, pszTempVal);
      
    if (error == OK) {
      *piValue = ::atoi(pszTempVal);
    } else {
      *piValue = iDefault;
    }
      
    return error;
  }
   
  // Get a double value.
  Error getDouble(const char* pszKey, double* pdValue, const double dDefault) {
    if (m_pfile == NULL) {
      *pdValue = dDefault;
      return FILE_NOT_FOUND;
    }

    char pszTempVal[ _MAX_PATH ];
    Error error = readKey(pszKey, pszTempVal);

    if (error == OK) {
      *pdValue = ::atof(pszTempVal);
    }
    else {
      *pdValue = dDefault;
    }

    return error;
  }

  // Get a boolean value.
  Error getBool(const char* pszKey, bool* pbValue, const bool bDefault) {
    if (m_pfile == NULL) {
      *pbValue = bDefault;
      return FILE_NOT_FOUND;
    }
    
    char pszTempVal[ _MAX_PATH ];
    Error error = readKey(pszKey, pszTempVal);
      
    if (error == OK) {
      // True is nonzero or non-"false".
      *pbValue =
	!(pszTempVal[ 0 ] == '0' || 
	  pszTempVal[ 0 ] == 'F' || 
	  pszTempVal[ 0 ] == 'f');
    } else {
      *pbValue = bDefault;
    }
      
    return error;
  }

private:
  // Handle to the .ini file to open
  FILE* m_pfile;

  // Finds the specified key 
  Error readKey(const char* pszKeyName, char* pszValue) {
    char pszLineBuffer[ _MAX_PATH ];
    bool bKeyFound = false;

    assert(m_pfile != NULL);
    assert(pszKeyName != NULL);
    assert(pszValue != NULL);
      
    ::rewind(m_pfile);
      
    while(!bKeyFound && 
	  (fgets(pszLineBuffer, _MAX_PATH, m_pfile) != NULL)) {      
      if (strchr("#;", pszLineBuffer[0]) != NULL) {
	continue; // Skip comment lines
      }
	
      if (pszLineBuffer[ 0 ] == '[') {
	return KEY_NOT_FOUND;
      }
         
      char* pPos;
      if ((pPos = strchr(pszLineBuffer, '=')) != NULL) {
	if (strstr(pszLineBuffer, pszKeyName) != NULL) {
	  strncpy(pszValue, pPos + 1, _MAX_PATH);
               
	  if ((pPos = strrchr(pszValue, '\n')) != NULL)
	    *pPos = '\0';

	  if ((pPos = strrchr(pszValue, '\r')) != NULL)
	    *pPos = '\0';
               
	  return OK;
	}
      }
    }
      
    if (!bKeyFound) {
      return KEY_NOT_FOUND;
    }

    return OK;
  }
};


//=============================================================================
// Load parameters from the INI file
//=============================================================================
bool loadIniFile(const char* pszINIFilename) {
  ReadINIFile          iniFile;
  ReadINIFile::Error   iniFileError;
  bool                 bErrorFound = false;
  int                  iItemIndex;
   
  // Open the ini file
  iniFile.open(pszINIFilename);

  // Read data from ini file
  iniFileError = iniFile.getInt(INI_WINDOW_POSITION_X, &iWindowPositionX, 100);
  if (iniFileError != ReadINIFile::OK) bErrorFound = true;

  iniFileError = iniFile.getInt(INI_WINDOW_POSITION_Y, &iWindowPositionY, 100);
  if (iniFileError != ReadINIFile::OK) bErrorFound = true;

  iniFileError = iniFile.getInt(INI_WINDOW_SIZE_WIDTH, &iWindowSizeWidth, 1000);
  if (iniFileError != ReadINIFile::OK) bErrorFound = true;

  iniFileError = iniFile.getInt(INI_WINDOW_SIZE_HEIGHT, &iWindowSizeHeight, 500);
  if (iniFileError != ReadINIFile::OK) bErrorFound = true;

  iniFileError = iniFile.getInt(INI_NUMBER_OF_BUFFERS, &iNumberOfBuffers, 30);
  if (iniFileError != ReadINIFile::OK) bErrorFound = true;

  iniFileError = iniFile.getBool(INI_RECORDING_AUTO_START, &bRecordingAutoStart,
                                 false);
  if (iniFileError != ReadINIFile::OK) bErrorFound = true;

  iniFileError = iniFile.getInt(INI_DATA_FORMAT, &iItemIndex, 1);
  if (iniFileError != ReadINIFile::OK) bErrorFound = true;
  switch (iItemIndex) {
  case 0:
    ladybugDataFormat = LADYBUG_DATAFORMAT_SEQUENTIAL;
    break;
  case 1:
    ladybugDataFormat = LADYBUG_DATAFORMAT_COLOR_SEP_SEQUENTIAL_JPEG;
    break;
  case 2:
    ladybugDataFormat = LADYBUG_DATAFORMAT_SEQUENTIAL_HALF_HEIGHT;
    break;
  case 3:
    ladybugDataFormat = LADYBUG_DATAFORMAT_COLOR_SEP_SEQUENTIAL_HALF_HEIGHT_JPEG;
    break;
  default:
    ladybugDataFormat = LADYBUG_DATAFORMAT_COLOR_SEP_SEQUENTIAL_JPEG;
  }
  
  iniFileError = iniFile.getInt(INI_COLOR_PROCESSING_METHOD, &iItemIndex, 4);
  if (iniFileError != ReadINIFile::OK) bErrorFound = true;
  switch (iItemIndex) {
  case 0:
    colorProcessingMethod = LADYBUG_EDGE_SENSING;
    break;
  case 1:
    colorProcessingMethod = LADYBUG_NEAREST_NEIGHBOR;
    break;
  case 2:
    colorProcessingMethod = LADYBUG_NEAREST_NEIGHBOR_FAST;
    break;
  case 3:
    colorProcessingMethod = LADYBUG_RIGOROUS;
    break;
  case 4:
    colorProcessingMethod = LADYBUG_DOWNSAMPLE4;
    break;
  case 5:
    colorProcessingMethod = LADYBUG_MONO;
    break;
  case 6:
    colorProcessingMethod = LADYBUG_HQLINEAR;
    break;
  default:
    colorProcessingMethod = LADYBUG_NEAREST_NEIGHBOR_FAST;
  }

  iniFileError = iniFile.getInt(INI_INITIAL_DISPLAY_TYPE, &iItemIndex, 0);
  if (iniFileError != ReadINIFile::OK) bErrorFound = true;
  switch (iItemIndex) {
  case 0:
    uiDisplayMode = LADYBUG_PANORAMIC;
    break;
  case 1:
    uiDisplayMode = LADYBUG_ALL_CAMERAS_VIEW;
    break;
  case 2:
    uiDisplayMode = LADYBUG_DOME;
    break;
  default:
    uiDisplayMode = LADYBUG_PANORAMIC;
  }
   
  // Close ini file
  iniFile.close();

  return !bErrorFound;
}
