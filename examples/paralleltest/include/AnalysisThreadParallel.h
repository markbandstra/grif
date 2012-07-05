// Copyright (C) 2012 Gamma-ray Imaging Framework Team
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 3.0 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
// 
// The license can be found in the LICENSE.txt file.
//
// Contact:
// Dr. Daniel Chivers
// dhchivers@lbl.gov

#ifndef GRIF_EXAMPLES_PARALLELTEST_ANALYSISTHREADPARALLEL_H_
#define GRIF_EXAMPLES_PARALLELTEST_ANALYSISTHREADPARALLEL_H_

// AnalysisThreadParallel:
//    Passes along data that it reads and keeps a histogram.
//
//    Be sure to modify GRIUserProcesses.h and GRIUserLoader.cpp
//    before you try to use this analysis thread class!

#include <QList>
#include <QString>

#include <core/GRIAnalysisThread.h>

class AnalysisThreadParallel : public GRIAnalysisThread {

public:
  AnalysisThreadParallel() {}
  ~AnalysisThreadParallel() {}

  int Initialize(int thread_number);
  int Analyze();
  QString ThreadNumber();

  int thread_number_;
};

#endif  // GRIF_EXAMPLES_PARALLEL_ANALYSISTHREADPARALLEL_H_
