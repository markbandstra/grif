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

#include "AnalysisThreadParallel.h"

#include <QPair>


int AnalysisThreadParallel::Initialize(int thread_number) {
  thread_number_ = thread_number;
  // create an ADC histogram for this channel
  int nhist = 0;
  QString histname = "Analysis Parallel " + ThreadNumber();
  if (CreateNewHistogram(histname,300,0.0,1000.0) == 0) {
    ++nhist;
    SetHistRateMode(histname,false);
  }
  std::cout << "AnalysisThreadParallel: Number of histograms created: "
            << nhist << std::endl;
  return nhist;
}


QString AnalysisThreadParallel::ThreadNumber() {
  if (thread_number_<10) {
    return QString("0")+QString::number(thread_number_);
  } else {
    return QString::number(thread_number_);
  }
}


int AnalysisThreadParallel::Analyze() {
  // Read from initial thread
  double* ADC1;
  int* CH1;
  qint64* TS1;
  int nADC1, nCH1, nTS1;

  QPair<int, double*> pADC1 = ReadData<double>("A","ADCOutput"+ThreadNumber());
  nADC1 = pADC1.first;
  ADC1 = pADC1.second;
  QPair<int, int*> pCH1 = ReadData<int>("A","CHAN"+ThreadNumber());
  nCH1 = pCH1.first;
  CH1 = pCH1.second;
  QPair<int, qint64*> pTS1 = ReadData<qint64>("A","TS"+ThreadNumber());
  nTS1 = pTS1.first;
  TS1 = pTS1.second;

  QString histname = "Analysis Parallel " + ThreadNumber();
  if (GetHistogram(histname)) {
    UpdateHistogram(histname, ADC1, nADC1);
  } else {
    std::cerr << "AnalysisThreadParallel::Analyze: Histogram not found" << std::endl;
  }

  PostData<double>(nADC1, "ADCOutput"+ThreadNumber(), ADC1);
  PostData<int>(nCH1, "CHAN"+ThreadNumber(), CH1);
  PostData<qint64>(nTS1, "TS"+ThreadNumber(), TS1);

  return 0;
}
