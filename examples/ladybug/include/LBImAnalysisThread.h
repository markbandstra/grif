#ifndef LBANALYSISTHREAD_H
#define LBANALYSISTHREAD_H

#include "GRIAnalysisThread.h"

class SIMAnalysisThread : public GRIAnalysisThread {
 public:
  SIMAnalysisThread() {}
  ~SIMAnalysisThread() {}

  int Analyze();
};

#endif // LBANALYSISTHREAD_H
