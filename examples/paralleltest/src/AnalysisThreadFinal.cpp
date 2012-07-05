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

#include "AnalysisThreadFinal.h"

#include <QPair>


QString AnalysisThreadFinal::ThreadNumber(int index) {
  if (index<10) {
    return QString("0")+QString::number(index);
  } else {
    return QString::number(index);
  }
}

int AnalysisThreadFinal::Initialize(int nchan) {
  n_channels_ = nchan;

  // create an ADC histogram for all channels
  int nhist = 0;
  QString histname = "Analysis Final";
  if (CreateNewHistogram(histname,300,0.0,1000.0) == 0) {
    ++nhist;
    SetHistRateMode(histname,false);
  }
  std::cout << "AnalysisThreadFinal: Number of histograms created: "
            << nhist << std::endl;
  return nhist;
}


int AnalysisThreadFinal::Analyze() {
  // Read from intermediate threads
  QList<double> ADC_all;
  QList<int> CHAN_all;
  QList<qint64> TS_all;

  for (int i = 0; i < n_channels_; ++i) {
    double* ADC1;
    int* CH1;
    qint64* TS1;
    int nADC1, nCH1, nTS1;

    QPair<int, double*> pADC1 = ReadData<double>("B"+ThreadNumber(i),"ADCOutput"+ThreadNumber(i));
    nADC1 = pADC1.first;
    ADC1 = pADC1.second;
    QPair<int, int*> pCH1 = ReadData<int>("B"+ThreadNumber(i),"CHAN"+ThreadNumber(i));
    nCH1 = pCH1.first;
    CH1 = pCH1.second;
    QPair<int, qint64*> pTS1 = ReadData<qint64>("B"+ThreadNumber(i),"TS"+ThreadNumber(i));
    nTS1 = pTS1.first;
    TS1 = pTS1.second;

    for (int j=0; j<nADC1; j++) {
      ADC_all.append(ADC1[j]);
      CHAN_all.append(CH1[j]);
      TS_all.append(TS1[j]);
    }
  }

  // Update histogram
  QString histname = "Analysis Final";
  if (GetHistogram(histname)) {
    UpdateHistogram(histname, &(ADC_all[0]), ADC_all.size());
  }

  return 0;
}
