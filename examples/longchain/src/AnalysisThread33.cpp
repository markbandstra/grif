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

#include "AnalysisThread33.h"

#include <QPair>

int AnalysisThread33::Initialize(int nchan) {
  // create an ADC histogram for each channel
  int nhist = 0;
  for (int i = 0; i < nchan; ++i) {
    QString histname = "Analysis 33 - ADC Channel " + QString::number(i);
    if (CreateNewHistogram(histname,300,0.0,1000.0) == 0) {
      ++nhist;
      SetHistRateMode(histname,false);
    }
  }
  std::cout << "AnalysisThread33: Number of histograms created: "
            << nhist << std::endl;
  return nhist;
}


int AnalysisThread33::Analyze() {
  // Read SIMDAQ
  double* ADC1;
  int* CH1;
  qint64* TS1;
  int nADC1, nCH1, nTS1;

  QPair<int, double*> pADC1 = ReadData<double>("A32","ADCOutput");
  nADC1 = pADC1.first;
  ADC1 = pADC1.second;
  QPair<int, int*> pCH1 = ReadData<int>("A32","CHAN");
  nCH1 = pCH1.first;
  CH1 = pCH1.second;
  QPair<int, qint64*> pTS1 = ReadData<qint64>("A32","TS");
  nTS1 = pTS1.first;
  TS1 = pTS1.second;

  // these should all be the same
  for (int i = 0; i < nADC1; ++i) {
    QString histname = "Analysis 33 - ADC Channel "+QString::number(CH1[i]);
    if (GetHistogram(histname)) {
      UpdateHistogram(histname, &(ADC1[i]),1);
    } else {
      std::cerr << "AnalysisThread33::Analyze: ADC1 channel out of range!  ch="
    << CH1[i] << std::endl;
    }
  }

  PostData<double>(nADC1, "ADCOutput", ADC1);
  PostData<int>(nCH1, "CHAN", CH1);
  PostData<qint64>(nTS1, "TS", TS1);

  return 0;
}
