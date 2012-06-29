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

#include "AnalysisThreadInitial.h"

#include <QPair>
#include <QList>

int AnalysisThreadInitial::Initialize(int nchan) {
  n_channels_ = nchan;

  // create an ADC histogram for each channel
  int nhist = 0;
  for (int i = 0; i < n_channels_; ++i) {
    QString histname = "Analysis Initial - Channel " + QString::number(i);
    if (CreateNewHistogram(histname,300,0.0,1000.0) == 0) {
      ++nhist;
      SetHistRateMode(histname,false);
    }
  }
  std::cout << "AnalysisThreadInitial: Number of histograms created: "
            << nhist << std::endl;
  return nhist;
}


int AnalysisThreadInitial::Analyze() {
  // Read SIMDAQ
  double* ADC1;
  int* CH1;
  qint64* TS1;
  int nADC1, nCH1, nTS1;

  QPair<int, double*> pADC1 = ReadData<double>("SIMDAQ1","ADCOutput");
  nADC1 = pADC1.first;
  ADC1 = pADC1.second;
  QPair<int, int*> pCH1 = ReadData<int>("SIMDAQ1","CHAN");
  nCH1 = pCH1.first;
  CH1 = pCH1.second;
  QPair<int, qint64*> pTS1 = ReadData<qint64>("SIMDAQ1","TS");
  nTS1 = pTS1.first;
  TS1 = pTS1.second;

  for (int i = 0; i < n_channels_; ++i) {
    QString histname = "Analysis Initial - Channel "+QString::number(CH1[i]);
    if (GetHistogram(histname)) {
      UpdateHistogram(histname, &(ADC1[i]),1);
    } else {
      std::cerr << "AnalysisThreadInitial::Analyze: ADC1 channel out of range!  ch="
                << CH1[i] << std::endl;
    }
    QList<double> ADC_channel;
    QList<int> CHAN_channel;
    QList<qint64> TS_channel;
    for (int j=0; j<nADC1; j++) {
      if (CH1[j]==i) {
        ADC_channel.append(ADC1[j]);
        CHAN_channel.append(CH1[j]);
        TS_channel.append(TS1[j]);
      }
    }
    if (ADC_channel.size()>0) {
      QString channel_name = QString::number(i);
      cout << "Channel name: " << channel_name.toStdString().c_str() << std::endl;
      PostData<double>(nADC1, "ADCOutput"+channel_name, ADC1);
      PostData<int>(nCH1, "CHAN"+channel_name, CH1);
      PostData<qint64>(nTS1, "TS"+channel_name, TS1);
    }
  }

  return 0;
}
