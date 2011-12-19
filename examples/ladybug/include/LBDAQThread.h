#ifndef LBDAQTHREAD_H
#define LBDAQTHREAD_H

#include <assert.h>
#include <ladybug/include/ladybug.h>
#include "GRIDAQAccumulator.h"
#include "GRIDAQBaseAccumNode.h"
#include "GRIDataDefines.h"
#include "GRIDAQThread.h"

class LBDAQThread : public GRIDAQThread {
 public:
  LBDAQThread();
  ~LBAQThread();
  
  // Open the video, get a number of frames, write to file, close the video
  int acquireData(int n);

  GRIDAQBaseAccumNode *RegisterDataOutput(QString outName);

  // Create a Ladybug video context
  int connectToDAQ();

  int initialize() { return 0; }
  int loadConfiguration() { return 0; }
  int startDataAcquisition() {return 0; }
  int stopDataAcquisition() { return 0; }

 private:
  LadybugVideoContext context_;
};

#endif // LBDAQTHREAD_H
