#ifndef LBANALYSISTHREAD_H
#define LBANALYSISTHREAD_H

#include "GRIAnalysisThread.h"

class SIMAnalysisThread : public GRIAnalysisThread {
 public:
  SIMAnalysisThread() {}
  ~SIMAnalysisThread() {}

  int Analyze() { sleep(10); }
};

#endif // LBANALYSISTHREAD_H
