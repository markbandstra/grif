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

#include <QtGui/QApplication>
#include <QtCore/QCoreApplication>
#include <QtGui/QtGui>
#include <QtCore>
#include <Qt>
#include <QMainWindow>
#include <QWidget>
#include <QColor>

#include <config/GRILoader.h>
#include <config/GRIUserLoader.h>
#include <core/GRIDefines.h>
#include <core/GRIMemoryManager.h>
#include <core/GRIRegulator.h>
#include <hist/GRIHistWidget.h>
#include <hist/GRIHist1DWidget.h>
#include <hist/GRIHist2DWidget.h>
#include <hist/GRIHist1DGridWidget.h>
#include <hist/GRIHist1DGridScrollWidget.h>

#include "SIMDAQThread.h"
#include "AnalysisThread01.h"
#include "AnalysisThread02.h"
#include "AnalysisThread03.h"
#include "AnalysisThread04.h"
#include "AnalysisThread05.h"
#include "AnalysisThread06.h"
#include "AnalysisThread07.h"
#include "AnalysisThread08.h"
#include "AnalysisThread09.h"
#include "AnalysisThread10.h"
#include "AnalysisThread11.h"
#include "AnalysisThread12.h"
#include "AnalysisThread13.h"
#include "AnalysisThread14.h"
#include "AnalysisThread15.h"
#include "AnalysisThread16.h"
#include "AnalysisThread17.h"
#include "AnalysisThread18.h"
#include "AnalysisThread19.h"
#include "AnalysisThread20.h"
#include "AnalysisThread21.h"
#include "AnalysisThread22.h"
#include "AnalysisThread23.h"
#include "AnalysisThread24.h"
#include "AnalysisThread25.h"
#include "AnalysisThread26.h"
#include "AnalysisThread27.h"
#include "AnalysisThread28.h"
#include "AnalysisThread29.h"
#include "AnalysisThread30.h"
#include "AnalysisThread31.h"
#include "AnalysisThread32.h"
#include "AnalysisThread33.h"
#include "AnalysisThread34.h"
#include "AnalysisThread35.h"
#include "AnalysisThread36.h"
#include "AnalysisThread37.h"
#include "AnalysisThread38.h"
#include "AnalysisThread39.h"
#include "AnalysisThread40.h"
#include "AnalysisThread41.h"
#include "AnalysisThread42.h"
#include "AnalysisThread43.h"
#include "AnalysisThread44.h"
#include "AnalysisThread45.h"
#include "AnalysisThread46.h"
#include "AnalysisThread47.h"
#include "AnalysisThread48.h"
#include "AnalysisThread49.h"
#include "AnalysisThread50.h"

int main(int argc, char* argv[]) {
  // the following will be included for all programs
  QApplication app(argc, argv);
  GRIMemoryManager *mm = new GRIMemoryManager();
  GRIRegulator *reg = new GRIRegulator(mm);

  // the following will be included for all programs
  GRILoader *loader = new GRIUserLoader(reg);
  loader->InitRegulatorDetails();

  // get the processes
  QLinkedList<GRIProcessThread*> *p = reg->get_processes();
  // be careful not to remove anything
  SIMDAQThread *simdaq1  = (SIMDAQThread *)p->takeFirst();
  AnalysisThread01 *A01 = (AnalysisThread01 *)p->takeFirst();
  AnalysisThread02 *A02 = (AnalysisThread02 *)p->takeFirst();
  AnalysisThread03 *A03 = (AnalysisThread03 *)p->takeFirst();
  AnalysisThread04 *A04 = (AnalysisThread04 *)p->takeFirst();
  AnalysisThread05 *A05 = (AnalysisThread05 *)p->takeFirst();
  AnalysisThread06 *A06 = (AnalysisThread06 *)p->takeFirst();
  AnalysisThread07 *A07 = (AnalysisThread07 *)p->takeFirst();
  AnalysisThread08 *A08 = (AnalysisThread08 *)p->takeFirst();
  AnalysisThread09 *A09 = (AnalysisThread09 *)p->takeFirst();
  AnalysisThread10 *A10 = (AnalysisThread10 *)p->takeFirst();
  AnalysisThread11 *A11 = (AnalysisThread11 *)p->takeFirst();
  AnalysisThread12 *A12 = (AnalysisThread12 *)p->takeFirst();
  AnalysisThread13 *A13 = (AnalysisThread13 *)p->takeFirst();
  AnalysisThread14 *A14 = (AnalysisThread14 *)p->takeFirst();
  AnalysisThread15 *A15 = (AnalysisThread15 *)p->takeFirst();
  AnalysisThread16 *A16 = (AnalysisThread16 *)p->takeFirst();
  AnalysisThread17 *A17 = (AnalysisThread17 *)p->takeFirst();
  AnalysisThread18 *A18 = (AnalysisThread18 *)p->takeFirst();
  AnalysisThread19 *A19 = (AnalysisThread19 *)p->takeFirst();
  AnalysisThread20 *A20 = (AnalysisThread20 *)p->takeFirst();
  AnalysisThread21 *A21 = (AnalysisThread21 *)p->takeFirst();
  AnalysisThread22 *A22 = (AnalysisThread22 *)p->takeFirst();
  AnalysisThread23 *A23 = (AnalysisThread23 *)p->takeFirst();
  AnalysisThread24 *A24 = (AnalysisThread24 *)p->takeFirst();
  AnalysisThread25 *A25 = (AnalysisThread25 *)p->takeFirst();
  AnalysisThread26 *A26 = (AnalysisThread26 *)p->takeFirst();
  AnalysisThread27 *A27 = (AnalysisThread27 *)p->takeFirst();
  AnalysisThread28 *A28 = (AnalysisThread28 *)p->takeFirst();
  AnalysisThread29 *A29 = (AnalysisThread29 *)p->takeFirst();
  AnalysisThread30 *A30 = (AnalysisThread30 *)p->takeFirst();
  AnalysisThread31 *A31 = (AnalysisThread31 *)p->takeFirst();
  AnalysisThread32 *A32 = (AnalysisThread32 *)p->takeFirst();
  AnalysisThread33 *A33 = (AnalysisThread33 *)p->takeFirst();
  AnalysisThread34 *A34 = (AnalysisThread34 *)p->takeFirst();
  AnalysisThread35 *A35 = (AnalysisThread35 *)p->takeFirst();
  AnalysisThread36 *A36 = (AnalysisThread36 *)p->takeFirst();
  AnalysisThread37 *A37 = (AnalysisThread37 *)p->takeFirst();
  AnalysisThread38 *A38 = (AnalysisThread38 *)p->takeFirst();
  AnalysisThread39 *A39 = (AnalysisThread39 *)p->takeFirst();
  AnalysisThread40 *A40 = (AnalysisThread40 *)p->takeFirst();
  AnalysisThread41 *A41 = (AnalysisThread41 *)p->takeFirst();
  AnalysisThread42 *A42 = (AnalysisThread42 *)p->takeFirst();
  AnalysisThread43 *A43 = (AnalysisThread43 *)p->takeFirst();
  AnalysisThread44 *A44 = (AnalysisThread44 *)p->takeFirst();
  AnalysisThread45 *A45 = (AnalysisThread45 *)p->takeFirst();
  AnalysisThread46 *A46 = (AnalysisThread46 *)p->takeFirst();
  AnalysisThread47 *A47 = (AnalysisThread47 *)p->takeFirst();
  AnalysisThread48 *A48 = (AnalysisThread48 *)p->takeFirst();
  AnalysisThread49 *A49 = (AnalysisThread49 *)p->takeFirst();
  AnalysisThread50 *A50 = (AnalysisThread50 *)p->takeFirst();
  p->push_back(simdaq1);
  p->push_back(A01);
  p->push_back(A02);
  p->push_back(A03);
  p->push_back(A04);
  p->push_back(A05);
  p->push_back(A06);
  p->push_back(A07);
  p->push_back(A08);
  p->push_back(A09);
  p->push_back(A10);
  p->push_back(A11);
  p->push_back(A12);
  p->push_back(A13);
  p->push_back(A14);
  p->push_back(A15);
  p->push_back(A16);
  p->push_back(A17);
  p->push_back(A18);
  p->push_back(A19);
  p->push_back(A20);
  p->push_back(A21);
  p->push_back(A22);
  p->push_back(A23);
  p->push_back(A24);
  p->push_back(A25);
  p->push_back(A26);
  p->push_back(A27);
  p->push_back(A28);
  p->push_back(A29);
  p->push_back(A30);
  p->push_back(A31);
  p->push_back(A32);
  p->push_back(A33);
  p->push_back(A34);
  p->push_back(A35);
  p->push_back(A36);
  p->push_back(A37);
  p->push_back(A38);
  p->push_back(A39);
  p->push_back(A40);
  p->push_back(A41);
  p->push_back(A42);
  p->push_back(A43);
  p->push_back(A44);
  p->push_back(A45);
  p->push_back(A46);
  p->push_back(A47);
  p->push_back(A48);
  p->push_back(A49);
  p->push_back(A50);

  // Analysis
  int nchan = 1;
  A01->Initialize(nchan);
  A02->Initialize(nchan);
  A03->Initialize(nchan);
  A04->Initialize(nchan);
  A05->Initialize(nchan);
  A06->Initialize(nchan);
  A07->Initialize(nchan);
  A08->Initialize(nchan);
  A09->Initialize(nchan);
  A10->Initialize(nchan);
  A11->Initialize(nchan);
  A12->Initialize(nchan);
  A13->Initialize(nchan);
  A14->Initialize(nchan);
  A15->Initialize(nchan);
  A16->Initialize(nchan);
  A17->Initialize(nchan);
  A18->Initialize(nchan);
  A19->Initialize(nchan);
  A20->Initialize(nchan);
  A21->Initialize(nchan);
  A22->Initialize(nchan);
  A23->Initialize(nchan);
  A24->Initialize(nchan);
  A25->Initialize(nchan);
  A26->Initialize(nchan);
  A27->Initialize(nchan);
  A28->Initialize(nchan);
  A29->Initialize(nchan);
  A30->Initialize(nchan);
  A31->Initialize(nchan);
  A32->Initialize(nchan);
  A33->Initialize(nchan);
  A34->Initialize(nchan);
  A35->Initialize(nchan);
  A36->Initialize(nchan);
  A37->Initialize(nchan);
  A38->Initialize(nchan);
  A39->Initialize(nchan);
  A40->Initialize(nchan);
  A41->Initialize(nchan);
  A42->Initialize(nchan);
  A43->Initialize(nchan);
  A44->Initialize(nchan);
  A45->Initialize(nchan);
  A46->Initialize(nchan);
  A47->Initialize(nchan);
  A48->Initialize(nchan);
  A49->Initialize(nchan);
  A50->Initialize(nchan);
  // DAQ1
  simdaq1->init_chans(nchan, 0, 1000, 200);
  // remove the peaks that each SIMDAQ is initialized with
  while (simdaq1->get_npk() > 0) {
      simdaq1->removePeak(0);
  }
  // add new peaks
  simdaq1->addPeak(300, 25, 100, 0);
  simdaq1->addPeak(800, 30, 100, 0);

  QMainWindow *win7 = new QMainWindow();
  GRIHist1DGridScrollWidget *histDraw_Scroll = new GRIHist1DGridScrollWidget(win7);
  win7->setCentralWidget(histDraw_Scroll);
  win7->setWindowTitle("Scrolling Grid");
  histDraw_Scroll->AddHist(A01->GetHistogram("Analysis 01 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A02->GetHistogram("Analysis 02 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A03->GetHistogram("Analysis 03 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A04->GetHistogram("Analysis 04 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A05->GetHistogram("Analysis 05 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A06->GetHistogram("Analysis 06 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A07->GetHistogram("Analysis 07 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A08->GetHistogram("Analysis 08 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A09->GetHistogram("Analysis 09 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A10->GetHistogram("Analysis 10 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A11->GetHistogram("Analysis 11 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A12->GetHistogram("Analysis 12 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A13->GetHistogram("Analysis 13 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A14->GetHistogram("Analysis 14 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A15->GetHistogram("Analysis 15 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A16->GetHistogram("Analysis 16 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A17->GetHistogram("Analysis 17 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A18->GetHistogram("Analysis 18 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A19->GetHistogram("Analysis 19 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A20->GetHistogram("Analysis 20 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A21->GetHistogram("Analysis 21 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A22->GetHistogram("Analysis 22 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A23->GetHistogram("Analysis 23 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A24->GetHistogram("Analysis 24 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A25->GetHistogram("Analysis 25 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A26->GetHistogram("Analysis 26 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A27->GetHistogram("Analysis 27 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A28->GetHistogram("Analysis 28 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A29->GetHistogram("Analysis 29 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A30->GetHistogram("Analysis 30 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A31->GetHistogram("Analysis 31 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A32->GetHistogram("Analysis 32 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A33->GetHistogram("Analysis 33 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A34->GetHistogram("Analysis 34 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A35->GetHistogram("Analysis 35 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A36->GetHistogram("Analysis 36 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A37->GetHistogram("Analysis 37 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A38->GetHistogram("Analysis 38 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A39->GetHistogram("Analysis 39 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A40->GetHistogram("Analysis 40 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A41->GetHistogram("Analysis 41 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A42->GetHistogram("Analysis 42 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A43->GetHistogram("Analysis 43 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A44->GetHistogram("Analysis 44 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A45->GetHistogram("Analysis 45 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A46->GetHistogram("Analysis 46 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A47->GetHistogram("Analysis 47 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A48->GetHistogram("Analysis 48 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A49->GetHistogram("Analysis 49 - ADC Channel 0"));
  histDraw_Scroll->AddHist(A50->GetHistogram("Analysis 50 - ADC Channel 0"));
  histDraw_Scroll->SetGridMajor(25,2);
  histDraw_Scroll->SetGridMinor(2,2);
  histDraw_Scroll->SetGridMinorUpperLeft(0,0);
  histDraw_Scroll->SetXLabelAll("Channel");
  histDraw_Scroll->SetYLabelAll("Counts");
  histDraw_Scroll->SetLogScaleAll(true);
  histDraw_Scroll->SetForegroundColorAll(Qt::yellow);
  histDraw_Scroll->SetBackgroundColorAll(Qt::black);
  histDraw_Scroll->SetOutlineColorAll(Qt::yellow);
  win7->resize(640,480);
  win7->show();

  // make sure the app exits when all GUI windows are closed
  QObject::connect(qApp, SIGNAL(lastWindowClosed()), qApp, SLOT(quit()));

  std::cout << "Running Now" << std::endl;
  reg->Start();

  app.exec();

  GRISleep::msleep(5000);

  reg->Stop();

  GRISleep::msleep(5000);

  delete(win7);

  return 0;
}
