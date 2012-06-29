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

int AnalysisThreadFinal::Initialize(int nchan) {
  n_channels_ = nchan;

  // create an ADC histogram for each channel
  int nhist = 0;
  for (int i = 0; i < n_channels_; ++i) {
    QString histname = "Analysis Final - Channel " + QString::number(i);
    if (CreateNewHistogram(histname,300,0.0,1000.0) == 0) {
      ++nhist;
      SetHistRateMode(histname,false);
    }
  }
  std::cout << "AnalysisThreadFinal: Number of histograms created: "
            << nhist << std::endl;
  return nhist;}


int AnalysisThreadFinal::Analyze() {
  // Read from all of the middle threads
  for (int i = 0; i < n_channels_; ++i) {
    double* ADC1;
    int* CH1;
    qint64* TS1;
    int nADC1, nCH1, nTS1;

    QString channel_name = QString::number(i);
    cout << "Channel name: " << channel_name.toStdString().c_str() << std::endl;

    QPair<int, double*> pADC1 = ReadData<double>("Middle"+channel_name,"ADCOutput"+channel_name);
    nADC1 = pADC1.first;
    ADC1 = pADC1.second;
    QPair<int, int*> pCH1 = ReadData<int>("Middle"+channel_name,"CHAN"+channel_name);
    nCH1 = pCH1.first;
    CH1 = pCH1.second;
    QPair<int, qint64*> pTS1 = ReadData<qint64>("Middle"+channel_name,"TS"+channel_name);
    nTS1 = pTS1.first;
    TS1 = pTS1.second;

    QString histname = "Analysis Final - Channel "+QString::number(CH1[i]);
    if (GetHistogram(histname)) {
      UpdateHistogram(histname, ADC1, nADC1);
    } else {
      std::cerr << "AnalysisThreadFinal::Analyze: Histogram not found " << histname.toStdString().c_str() << std::endl;
    }

  }

  return 0;
}
