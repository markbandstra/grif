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
  A01->Initialize(1);
  A02->Initialize(1);
  A03->Initialize(1);
  A04->Initialize(1);
  A05->Initialize(1);
  A06->Initialize(1);
  A07->Initialize(1);
  A08->Initialize(1);
  A09->Initialize(1);
  A10->Initialize(1);
  A11->Initialize(1);
  A12->Initialize(1);
  A13->Initialize(1);
  A14->Initialize(1);
  A15->Initialize(1);
  A16->Initialize(1);
  A17->Initialize(1);
  A18->Initialize(1);
  A19->Initialize(1);
  A20->Initialize(1);
  A21->Initialize(1);
  A22->Initialize(1);
  A23->Initialize(1);
  A24->Initialize(1);
  A25->Initialize(1);
  A26->Initialize(1);
  A27->Initialize(1);
  A28->Initialize(1);
  A29->Initialize(1);
  A30->Initialize(1);
  A31->Initialize(1);
  A32->Initialize(1);
  A33->Initialize(1);
  A34->Initialize(1);
  A35->Initialize(1);
  A36->Initialize(1);
  A37->Initialize(1);
  A38->Initialize(1);
  A39->Initialize(1);
  A40->Initialize(1);
  A41->Initialize(1);
  A42->Initialize(1);
  A43->Initialize(1);
  A44->Initialize(1);
  A45->Initialize(1);
  A46->Initialize(1);
  A47->Initialize(1);
  A48->Initialize(1);
  A49->Initialize(1);
  A50->Initialize(1);
  // DAQ1
  simdaq1->init_chans(1, 0, 1000, 200);
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
  histDraw_Scroll->AddHist(A01->GetHistogram("Analysis 01 - Channel 0"));
  histDraw_Scroll->AddHist(A02->GetHistogram("Analysis 02 - Channel 0"));
  histDraw_Scroll->AddHist(A03->GetHistogram("Analysis 03 - Channel 0"));
  histDraw_Scroll->AddHist(A04->GetHistogram("Analysis 04 - Channel 0"));
  histDraw_Scroll->AddHist(A05->GetHistogram("Analysis 05 - Channel 0"));
  histDraw_Scroll->AddHist(A06->GetHistogram("Analysis 06 - Channel 0"));
  histDraw_Scroll->AddHist(A07->GetHistogram("Analysis 07 - Channel 0"));
  histDraw_Scroll->AddHist(A08->GetHistogram("Analysis 08 - Channel 0"));
  histDraw_Scroll->AddHist(A09->GetHistogram("Analysis 09 - Channel 0"));
  histDraw_Scroll->AddHist(A10->GetHistogram("Analysis 10 - Channel 0"));
  histDraw_Scroll->AddHist(A11->GetHistogram("Analysis 11 - Channel 0"));
  histDraw_Scroll->AddHist(A12->GetHistogram("Analysis 12 - Channel 0"));
  histDraw_Scroll->AddHist(A13->GetHistogram("Analysis 13 - Channel 0"));
  histDraw_Scroll->AddHist(A14->GetHistogram("Analysis 14 - Channel 0"));
  histDraw_Scroll->AddHist(A15->GetHistogram("Analysis 15 - Channel 0"));
  histDraw_Scroll->AddHist(A16->GetHistogram("Analysis 16 - Channel 0"));
  histDraw_Scroll->AddHist(A17->GetHistogram("Analysis 17 - Channel 0"));
  histDraw_Scroll->AddHist(A18->GetHistogram("Analysis 18 - Channel 0"));
  histDraw_Scroll->AddHist(A19->GetHistogram("Analysis 19 - Channel 0"));
  histDraw_Scroll->AddHist(A20->GetHistogram("Analysis 20 - Channel 0"));
  histDraw_Scroll->AddHist(A21->GetHistogram("Analysis 21 - Channel 0"));
  histDraw_Scroll->AddHist(A22->GetHistogram("Analysis 22 - Channel 0"));
  histDraw_Scroll->AddHist(A23->GetHistogram("Analysis 23 - Channel 0"));
  histDraw_Scroll->AddHist(A24->GetHistogram("Analysis 24 - Channel 0"));
  histDraw_Scroll->AddHist(A25->GetHistogram("Analysis 25 - Channel 0"));
  histDraw_Scroll->AddHist(A26->GetHistogram("Analysis 26 - Channel 0"));
  histDraw_Scroll->AddHist(A27->GetHistogram("Analysis 27 - Channel 0"));
  histDraw_Scroll->AddHist(A28->GetHistogram("Analysis 28 - Channel 0"));
  histDraw_Scroll->AddHist(A29->GetHistogram("Analysis 29 - Channel 0"));
  histDraw_Scroll->AddHist(A30->GetHistogram("Analysis 30 - Channel 0"));
  histDraw_Scroll->AddHist(A31->GetHistogram("Analysis 31 - Channel 0"));
  histDraw_Scroll->AddHist(A32->GetHistogram("Analysis 32 - Channel 0"));
  histDraw_Scroll->AddHist(A33->GetHistogram("Analysis 33 - Channel 0"));
  histDraw_Scroll->AddHist(A34->GetHistogram("Analysis 34 - Channel 0"));
  histDraw_Scroll->AddHist(A35->GetHistogram("Analysis 35 - Channel 0"));
  histDraw_Scroll->AddHist(A36->GetHistogram("Analysis 36 - Channel 0"));
  histDraw_Scroll->AddHist(A37->GetHistogram("Analysis 37 - Channel 0"));
  histDraw_Scroll->AddHist(A38->GetHistogram("Analysis 38 - Channel 0"));
  histDraw_Scroll->AddHist(A39->GetHistogram("Analysis 39 - Channel 0"));
  histDraw_Scroll->AddHist(A40->GetHistogram("Analysis 40 - Channel 0"));
  histDraw_Scroll->AddHist(A41->GetHistogram("Analysis 41 - Channel 0"));
  histDraw_Scroll->AddHist(A42->GetHistogram("Analysis 42 - Channel 0"));
  histDraw_Scroll->AddHist(A43->GetHistogram("Analysis 43 - Channel 0"));
  histDraw_Scroll->AddHist(A44->GetHistogram("Analysis 44 - Channel 0"));
  histDraw_Scroll->AddHist(A45->GetHistogram("Analysis 45 - Channel 0"));
  histDraw_Scroll->AddHist(A46->GetHistogram("Analysis 46 - Channel 0"));
  histDraw_Scroll->AddHist(A47->GetHistogram("Analysis 47 - Channel 0"));
  histDraw_Scroll->AddHist(A48->GetHistogram("Analysis 48 - Channel 0"));
  histDraw_Scroll->AddHist(A49->GetHistogram("Analysis 49 - Channel 0"));
  histDraw_Scroll->AddHist(A50->GetHistogram("Analysis 50 - Channel 0"));
  histDraw_Scroll->SetGridMajor(13,4);
  histDraw_Scroll->SetGridMinor(3,4);
  histDraw_Scroll->SetGridMinorUpperLeft(0,0);
  histDraw_Scroll->SetXLabelAll("Channel");
  histDraw_Scroll->SetYLabelAll("Counts");
  histDraw_Scroll->SetLogScaleAll(true);
  histDraw_Scroll->SetForegroundColor(A01->GetHistogram("Analysis 01 - Channel 0"), QColor(255,  0,  0));
  histDraw_Scroll->SetForegroundColor(A02->GetHistogram("Analysis 02 - Channel 0"), QColor(255, 25,  0));
  histDraw_Scroll->SetForegroundColor(A03->GetHistogram("Analysis 03 - Channel 0"), QColor(255, 50,  0));
  histDraw_Scroll->SetForegroundColor(A04->GetHistogram("Analysis 04 - Channel 0"), QColor(255, 75,  0));
  histDraw_Scroll->SetForegroundColor(A05->GetHistogram("Analysis 05 - Channel 0"), QColor(255,100,  0));
  histDraw_Scroll->SetForegroundColor(A06->GetHistogram("Analysis 06 - Channel 0"), QColor(255,125,  0));
  histDraw_Scroll->SetForegroundColor(A07->GetHistogram("Analysis 07 - Channel 0"), QColor(255,150,  0));
  histDraw_Scroll->SetForegroundColor(A08->GetHistogram("Analysis 08 - Channel 0"), QColor(255,175,  0));
  histDraw_Scroll->SetForegroundColor(A09->GetHistogram("Analysis 09 - Channel 0"), QColor(255,200,  0));
  histDraw_Scroll->SetForegroundColor(A10->GetHistogram("Analysis 10 - Channel 0"), QColor(255,225,  0));
  histDraw_Scroll->SetForegroundColor(A11->GetHistogram("Analysis 11 - Channel 0"), QColor(255,255,  0));
  histDraw_Scroll->SetForegroundColor(A12->GetHistogram("Analysis 12 - Channel 0"), QColor(225,255,  0));
  histDraw_Scroll->SetForegroundColor(A13->GetHistogram("Analysis 13 - Channel 0"), QColor(200,255,  0));
  histDraw_Scroll->SetForegroundColor(A14->GetHistogram("Analysis 14 - Channel 0"), QColor(175,255,  0));
  histDraw_Scroll->SetForegroundColor(A15->GetHistogram("Analysis 15 - Channel 0"), QColor(150,255,  0));
  histDraw_Scroll->SetForegroundColor(A16->GetHistogram("Analysis 16 - Channel 0"), QColor(125,255,  0));
  histDraw_Scroll->SetForegroundColor(A17->GetHistogram("Analysis 17 - Channel 0"), QColor(100,255,  0));
  histDraw_Scroll->SetForegroundColor(A18->GetHistogram("Analysis 18 - Channel 0"), QColor( 75,255,  0));
  histDraw_Scroll->SetForegroundColor(A19->GetHistogram("Analysis 19 - Channel 0"), QColor( 50,255,  0));
  histDraw_Scroll->SetForegroundColor(A20->GetHistogram("Analysis 20 - Channel 0"), QColor( 25,255,  0));
  histDraw_Scroll->SetForegroundColor(A21->GetHistogram("Analysis 21 - Channel 0"), QColor(  0,255,  0));
  histDraw_Scroll->SetForegroundColor(A22->GetHistogram("Analysis 22 - Channel 0"), QColor(  0,255, 25));
  histDraw_Scroll->SetForegroundColor(A23->GetHistogram("Analysis 23 - Channel 0"), QColor(  0,255, 50));
  histDraw_Scroll->SetForegroundColor(A24->GetHistogram("Analysis 24 - Channel 0"), QColor(  0,255, 75));
  histDraw_Scroll->SetForegroundColor(A25->GetHistogram("Analysis 25 - Channel 0"), QColor(  0,255,100));
  histDraw_Scroll->SetForegroundColor(A26->GetHistogram("Analysis 26 - Channel 0"), QColor(  0,255,125));
  histDraw_Scroll->SetForegroundColor(A27->GetHistogram("Analysis 27 - Channel 0"), QColor(  0,255,150));
  histDraw_Scroll->SetForegroundColor(A28->GetHistogram("Analysis 28 - Channel 0"), QColor(  0,255,175));
  histDraw_Scroll->SetForegroundColor(A29->GetHistogram("Analysis 29 - Channel 0"), QColor(  0,255,200));
  histDraw_Scroll->SetForegroundColor(A30->GetHistogram("Analysis 30 - Channel 0"), QColor(  0,255,225));
  histDraw_Scroll->SetForegroundColor(A31->GetHistogram("Analysis 31 - Channel 0"), QColor(  0,255,255));
  histDraw_Scroll->SetForegroundColor(A32->GetHistogram("Analysis 32 - Channel 0"), QColor(  0,225,255));
  histDraw_Scroll->SetForegroundColor(A33->GetHistogram("Analysis 33 - Channel 0"), QColor(  0,200,255));
  histDraw_Scroll->SetForegroundColor(A34->GetHistogram("Analysis 34 - Channel 0"), QColor(  0,175,255));
  histDraw_Scroll->SetForegroundColor(A35->GetHistogram("Analysis 35 - Channel 0"), QColor(  0,150,255));
  histDraw_Scroll->SetForegroundColor(A36->GetHistogram("Analysis 36 - Channel 0"), QColor(  0,125,255));
  histDraw_Scroll->SetForegroundColor(A37->GetHistogram("Analysis 37 - Channel 0"), QColor(  0,100,255));
  histDraw_Scroll->SetForegroundColor(A38->GetHistogram("Analysis 38 - Channel 0"), QColor(  0, 75,255));
  histDraw_Scroll->SetForegroundColor(A39->GetHistogram("Analysis 39 - Channel 0"), QColor(  0, 50,255));
  histDraw_Scroll->SetForegroundColor(A40->GetHistogram("Analysis 40 - Channel 0"), QColor(  0, 25,255));
  histDraw_Scroll->SetForegroundColor(A41->GetHistogram("Analysis 41 - Channel 0"), QColor(  0,  0,255));
  histDraw_Scroll->SetForegroundColor(A42->GetHistogram("Analysis 42 - Channel 0"), QColor( 25,  0,255));
  histDraw_Scroll->SetForegroundColor(A43->GetHistogram("Analysis 43 - Channel 0"), QColor( 50,  0,255));
  histDraw_Scroll->SetForegroundColor(A44->GetHistogram("Analysis 44 - Channel 0"), QColor( 75,  0,255));
  histDraw_Scroll->SetForegroundColor(A45->GetHistogram("Analysis 45 - Channel 0"), QColor(100,  0,255));
  histDraw_Scroll->SetForegroundColor(A46->GetHistogram("Analysis 46 - Channel 0"), QColor(125,  0,255));
  histDraw_Scroll->SetForegroundColor(A47->GetHistogram("Analysis 47 - Channel 0"), QColor(150,  0,255));
  histDraw_Scroll->SetForegroundColor(A48->GetHistogram("Analysis 48 - Channel 0"), QColor(175,  0,255));
  histDraw_Scroll->SetForegroundColor(A49->GetHistogram("Analysis 49 - Channel 0"), QColor(200,  0,255));
  histDraw_Scroll->SetForegroundColor(A50->GetHistogram("Analysis 50 - Channel 0"), QColor(255,  0,255));
  win7->resize(800,600);
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
