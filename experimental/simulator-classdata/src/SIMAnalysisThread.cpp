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

#include <QPair>
#include "SIMAnalysisThread.h"

SIMAnalysisThread::SIMAnalysisThread() {
  nread_ = 0;
  CreateNewHistogram("ADCHist",200,0,1000);
  SetHistRateMode("ADCHist",true);
  SetHistPacketScaleFactor("ADCHist",0.01);
}

SIMAnalysisThread::~SIMAnalysisThread() {
}

int SIMAnalysisThread::Analyze() {
  std::cout << "SIMAnalysisThread::Analyze:  Now reading array Events from SIMDAQ" << std::endl;
  EventClassArray* Event1;
  int nEvent1;
  QPair<int, EventClassArray*> pEvent1 = ReadData<EventClassArray>("SIMDAQ","EventClassArray");
  Event1 = pEvent1.second; nEvent1 = pEvent1.first;
  std::cout << "SIMAnalysisThread::Analyze:  Finished reading array Events from SIMDAQ" << std::endl;

  std::cout << "SIMAnalysisThread::Analyze:  Now reading vector Events from SIMDAQ" << std::endl;
  EventClassVector* Event2;
  int nEvent2;
  QPair<int, EventClassVector*> pEvent2 = ReadData<EventClassVector>("SIMDAQ","EventClassVector");
  Event2 = pEvent2.second; nEvent2 = pEvent2.first;
  std::cout << "SIMAnalysisThread::Analyze:  Finished reading vector Events from SIMDAQ" << std::endl;

  Q_ASSERT(nEvent1 == nEvent2);
  std::cout << "SIMDAQThread::AcquireData:  Comparing array to vector events" << std::endl;
  for (int i=0; i<nEvent1; i++) {
    std::cout << std::endl;
    std::cout << "  Event # " << i << std::endl;
    std::cout << QString("Data").rightJustified(11).toStdString()
              << QString("Array").rightJustified(11).toStdString()
              << QString("Vector").rightJustified(11).toStdString()
              << QString("Array[0]").rightJustified(11).toStdString()
              << QString("Vector[0]").rightJustified(11).toStdString()
              << std::endl;
    std::cout << QString("").rightJustified(55,'-').toStdString() << std::endl;
    std::cout << QString("Energy").rightJustified(11).toStdString()
              << QString::number(Event1[i].energy_size()).rightJustified(11).toStdString()
              << QString::number(Event2[i].energy_size()).rightJustified(11).toStdString()
              << QString::number(Event1[i].energy(0)).rightJustified(11).toStdString();
    if (Event2[i].energy_size()==1) {
      std::cout << QString::number(Event2[i].energy(0)).rightJustified(11).toStdString();
    } else {
      std::cout << QString("corrupted").rightJustified(11).toStdString();
    }
    std::cout << std::endl;
    std::cout << QString("Chan").rightJustified(11).toStdString()
              << QString::number(Event1[i].chan_size()).rightJustified(11).toStdString()
              << QString::number(Event2[i].chan_size()).rightJustified(11).toStdString()
              << QString::number(Event1[i].chan(0)).rightJustified(11).toStdString();
    if (Event2[i].chan_size()==1) {
      std::cout << QString::number(Event2[i].chan(0)).rightJustified(11).toStdString();
    } else {
      std::cout << QString("corrupted").rightJustified(11).toStdString();
    }
    std::cout << std::endl;
    std::cout << QString("TS").rightJustified(11).toStdString()
              << QString::number(Event1[i].ts_size()).rightJustified(11).toStdString()
              << QString::number(Event2[i].ts_size()).rightJustified(11).toStdString()
              << QString::number(Event1[i].ts(0)).rightJustified(11).toStdString();
    if (Event2[i].ts_size()==1) {
      std::cout << QString::number(Event2[i].ts(0)).rightJustified(11).toStdString();
    } else {
      std::cout << QString("corrupted").rightJustified(11).toStdString();
    }
    std::cout << std::endl;
  }

  ++nread_;

//  UpdateHistogram("ADCHist",ADC,nADC);
//  UpdateHistogram("ADCHist",ADC2,nADC2);

  return 0;
}

