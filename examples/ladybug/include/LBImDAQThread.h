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
  int ConnectToDAQ();

  // Get frames and write to disk
  int AcquireData(int n);

  // Clean up
  int TerminationRoutines();

  int StartDataAcquisition() { return 0; }
  int StopDataAcquisition() { return 0; }
  int LoadConfiguration() { return 0; }
  int Initialize() { return 0; }

 private:
  int StartCamera();

  LadybugContext context_;
  unsigned char* arp_buffers_[LADYBUG_NUM_CAMERAS];
};

#endif // LBDAQTHREAD_H
