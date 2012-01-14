#ifndef LBDAQTHREAD_H
#define LBDAQTHREAD_H

#include "H:\Program Files\Point Grey Research\PGR Ladybug\include\ladybug.h"
#include "GRIDAQAccumulator.h"
#include "GRIDAQBaseAccumNode.h"
#include "GRIDataDefines.h"
#include "GRIDAQThread.h"

class LBImDAQThread : public GRIDAQThread {
 public:
  LBImDAQThread() {}
  ~LBImDAQThread() {}
  
  GRIDAQBaseAccumNode *RegisterDataOutput(QString outName);

  // Load initialization file and start camera
  int connectToDAQ();

  // Get frames and write to disk
  int acquireData(int n);

  // Clean up
  int terminationRoutines();

  int startDataAcquisition() { return 0; }
  int stopDataAcquisition() { return 0; }
  int loadConfiguration() { return 0; }
  int initialize() { return 0; }

 private:
  int StartCamera();

  LadybugContext context_;
  unsigned char* arp_buffers_[LADYBUG_NUM_CAMERAS];
};

#endif // LBDAQTHREAD_H
