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

  // Start the recording
  int startDataAcquisition();

  // Get frames and write to disk
  int acquireData(int n);

  // Stop the recording
  int stopDataAcquisition();

  int loadConfiguration() { return 0; }
  int initialize() { return 0; }

 private:
  int StartCamera();

  LadybugContext context_;
  unsigned char* arp_buffers_[LADYBUG_NUM_CAMERAS];
};

#endif // LBDAQTHREAD_H
