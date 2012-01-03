#ifndef LBANALYSISTHREAD_H
#define LBANALYSISTHREAD_H

#include "GRIAnalysisThread.h"

class LBImAnalysisThread : public GRIAnalysisThread {
 public:
  LBImAnalysisThread() {}
  ~LBImAnalysisThread() {}

  int Analyze();
};

#endif // LBANALYSISTHREAD_H
