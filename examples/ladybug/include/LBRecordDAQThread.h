#ifndef LBDAQTHREAD_H
#define LBDAQTHREAD_H

#include <ladybug/include/ladybug.h>
#include "GRIDAQAccumulator.h"
#include "GRIDAQBaseAccumNode.h"
#include "GRIDataDefines.h"
#include "GRIDAQThread.h"

class LBDAQThread : public GRIDAQThread {
 public:
  LBDAQThread();
  ~LBAQThread();
  
  GRIDAQBaseAccumNode *RegisterDataOutput(QString outName);

  // Load initialization file and start camera
  int connectToDAQ();

  // Configure ladybug output format
  int loadConfiguration();

  // Start the recording
  int startDataAcquisition();

  // Get frames and write to disk
  int acquireData(int n);

  // Stop the recording
  int stopDataAcquisition();

  int initialize() { return 0; }

 private:
  int StartCamera();
};

#endif // LBDAQTHREAD_H
