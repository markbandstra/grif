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

#include "AnalysisThreadMiddle00.h"

#include <QPair>

int AnalysisThreadMiddle00::Initialize() {
  // create an ADC histogram
  QString histname = "Analysis Middle00";
  if (CreateNewHistogram(histname,300,0.0,1000.0) == 0) {
    SetHistRateMode(histname,false);
    std::cout << "AnalysisThreadMiddle00: Histogram created: " << histname << std::endl;
  }
  return 1;
}


int AnalysisThreadMiddle00::Analyze() {
  // Read SIMDAQ
  double* ADC1;
  int* CH1;
  qint64* TS1;
  int nADC1, nCH1, nTS1;

  QPair<int, double*> pADC1 = ReadData<double>("Initial","ADCOutput00");
  nADC1 = pADC1.first;
  ADC1 = pADC1.second;
  QPair<int, int*> pCH1 = ReadData<int>("Initial","CHAN00");
  nCH1 = pCH1.first;
  CH1 = pCH1.second;
  QPair<int, qint64*> pTS1 = ReadData<qint64>("Initial","TS00");
  nTS1 = pTS1.first;
  TS1 = pTS1.second;

  // these should all be the same
  QString histname = "Analysis Middle00";
  if (GetHistogram(histname)) {
    UpdateHistogram(histname, ADC1, nADC1);
  } else {
    std::cerr << "AnalysisThreadMiddle00::Analyze: Histogram not found" << std::endl;
  }

  PostData<double>(nADC1, "ADCOutput00", ADC1);
  PostData<int>(nCH1, "CHAN00", CH1);
  PostData<qint64>(nTS1, "TS00", TS1);

  return 0;
}
