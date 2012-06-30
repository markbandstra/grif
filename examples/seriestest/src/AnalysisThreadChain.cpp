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

#include "AnalysisThreadChain.h"

#include <QPair>
#include <QList>

int AnalysisThreadChain::Initialize(int n_channels, int thread_number) {
  n_channels_ = n_channels;
  thread_number_ = thread_number;

  // create an ADC histogram for each channel
  int nhist = 0;
  for (int i = 0; i < n_channels_; ++i) {
    QString histname = "Analysis " + ThreadNumber() + " - Channel " + QString::number(i);
    if (CreateNewHistogram(histname,300,0.0,1000.0) == 0) {
      ++nhist;
      SetHistRateMode(histname,false);
    }
  }
  std::cout << "AnalysisThreadChain: Number of histograms created: "
            << nhist << std::endl;
  return nhist;
}


QString AnalysisThreadChain::ThreadNumber() {
  if (thread_number_<10) {
    return QString("0")+QString::number(thread_number_);
  } else {
    return QString::number(thread_number_);
  }
}


QString AnalysisThreadChain::XmlName() {
  return QString("A")+ThreadNumber();
}


QString AnalysisThreadChain::XmlNamePrevious() {
  int thread_previous = thread_number_ - 1;
  if (thread_previous==-1) {
    return QString("SIMDAQ1");
  } else if (thread_previous<10) {
    return QString("A")+QString("0")+QString::number(thread_previous);
  } else {
    return QString("A")+QString::number(thread_previous);
  }
}


int AnalysisThreadChain::Analyze() {
  // Read SIMDAQ
  double* ADC1;
  int* CH1;
  qint64* TS1;
  int nADC1, nCH1, nTS1;

  QPair<int, double*> pADC1 = ReadData<double>(XmlNamePrevious(),"ADCOutput");
  nADC1 = pADC1.first;
  ADC1 = pADC1.second;
  QPair<int, int*> pCH1 = ReadData<int>(XmlNamePrevious(),"CHAN");
  nCH1 = pCH1.first;
  CH1 = pCH1.second;
  QPair<int, qint64*> pTS1 = ReadData<qint64>(XmlNamePrevious(),"TS");
  nTS1 = pTS1.first;
  TS1 = pTS1.second;

  // Loop over channels
  for (int channel=0; channel<n_channels_; channel++) {
    // Loop over all events and pull out those from this channel
    QList<double> ADCs_from_channel;
    for (int j=0; j<nADC1; j++) {
      if (CH1[j]==channel) {
        ADCs_from_channel.append(ADC1[j]);
      }
    }
    // Add array of ADCs from this channel to the channel's histogram
    QString histname = "Analysis " + ThreadNumber() + " - Channel "+QString::number(channel);
    if (GetHistogram(histname) and ADCs_from_channel.size()>0) {
      UpdateHistogram(histname, &(ADCs_from_channel[0]),ADCs_from_channel.size());
    }
  }

  PostData<double>(nADC1, "ADCOutput", ADC1);
  PostData<int>(nCH1, "CHAN", CH1);
  PostData<qint64>(nTS1, "TS", TS1);

  return 0;
}
