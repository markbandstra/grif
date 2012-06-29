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
#include "AnalysisThread00.h"
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
#include "AnalysisThread51.h"
#include "AnalysisThread52.h"
#include "AnalysisThread53.h"
#include "AnalysisThread54.h"
#include "AnalysisThread55.h"
#include "AnalysisThread56.h"
#include "AnalysisThread57.h"
#include "AnalysisThread58.h"
#include "AnalysisThread59.h"
#include "AnalysisThread60.h"
#include "AnalysisThread61.h"
#include "AnalysisThread62.h"
#include "AnalysisThread63.h"
#include "AnalysisThread64.h"
#include "AnalysisThread65.h"
#include "AnalysisThread66.h"
#include "AnalysisThread67.h"
#include "AnalysisThread68.h"
#include "AnalysisThread69.h"
#include "AnalysisThread70.h"
#include "AnalysisThread71.h"
#include "AnalysisThread72.h"
#include "AnalysisThread73.h"
#include "AnalysisThread74.h"
#include "AnalysisThread75.h"
#include "AnalysisThread76.h"
#include "AnalysisThread77.h"
#include "AnalysisThread78.h"
#include "AnalysisThread79.h"
#include "AnalysisThread80.h"
#include "AnalysisThread81.h"
#include "AnalysisThread82.h"
#include "AnalysisThread83.h"
#include "AnalysisThread84.h"
#include "AnalysisThread85.h"
#include "AnalysisThread86.h"
#include "AnalysisThread87.h"
#include "AnalysisThread88.h"
#include "AnalysisThread89.h"
#include "AnalysisThread90.h"
#include "AnalysisThread91.h"
#include "AnalysisThread92.h"
#include "AnalysisThread93.h"
#include "AnalysisThread94.h"
#include "AnalysisThread95.h"
#include "AnalysisThread96.h"
#include "AnalysisThread97.h"
#include "AnalysisThread98.h"
#include "AnalysisThread99.h"

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
  AnalysisThread00 *A00 = (AnalysisThread00 *)p->takeFirst();
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
  AnalysisThread51 *A51 = (AnalysisThread51 *)p->takeFirst();
  AnalysisThread52 *A52 = (AnalysisThread52 *)p->takeFirst();
  AnalysisThread53 *A53 = (AnalysisThread53 *)p->takeFirst();
  AnalysisThread54 *A54 = (AnalysisThread54 *)p->takeFirst();
  AnalysisThread55 *A55 = (AnalysisThread55 *)p->takeFirst();
  AnalysisThread56 *A56 = (AnalysisThread56 *)p->takeFirst();
  AnalysisThread57 *A57 = (AnalysisThread57 *)p->takeFirst();
  AnalysisThread58 *A58 = (AnalysisThread58 *)p->takeFirst();
  AnalysisThread59 *A59 = (AnalysisThread59 *)p->takeFirst();
  AnalysisThread60 *A60 = (AnalysisThread60 *)p->takeFirst();
  AnalysisThread61 *A61 = (AnalysisThread61 *)p->takeFirst();
  AnalysisThread62 *A62 = (AnalysisThread62 *)p->takeFirst();
  AnalysisThread63 *A63 = (AnalysisThread63 *)p->takeFirst();
  AnalysisThread64 *A64 = (AnalysisThread64 *)p->takeFirst();
  AnalysisThread65 *A65 = (AnalysisThread65 *)p->takeFirst();
  AnalysisThread66 *A66 = (AnalysisThread66 *)p->takeFirst();
  AnalysisThread67 *A67 = (AnalysisThread67 *)p->takeFirst();
  AnalysisThread68 *A68 = (AnalysisThread68 *)p->takeFirst();
  AnalysisThread69 *A69 = (AnalysisThread69 *)p->takeFirst();
  AnalysisThread70 *A70 = (AnalysisThread70 *)p->takeFirst();
  AnalysisThread71 *A71 = (AnalysisThread71 *)p->takeFirst();
  AnalysisThread72 *A72 = (AnalysisThread72 *)p->takeFirst();
  AnalysisThread73 *A73 = (AnalysisThread73 *)p->takeFirst();
  AnalysisThread74 *A74 = (AnalysisThread74 *)p->takeFirst();
  AnalysisThread75 *A75 = (AnalysisThread75 *)p->takeFirst();
  AnalysisThread76 *A76 = (AnalysisThread76 *)p->takeFirst();
  AnalysisThread77 *A77 = (AnalysisThread77 *)p->takeFirst();
  AnalysisThread78 *A78 = (AnalysisThread78 *)p->takeFirst();
  AnalysisThread79 *A79 = (AnalysisThread79 *)p->takeFirst();
  AnalysisThread80 *A80 = (AnalysisThread80 *)p->takeFirst();
  AnalysisThread81 *A81 = (AnalysisThread81 *)p->takeFirst();
  AnalysisThread82 *A82 = (AnalysisThread82 *)p->takeFirst();
  AnalysisThread83 *A83 = (AnalysisThread83 *)p->takeFirst();
  AnalysisThread84 *A84 = (AnalysisThread84 *)p->takeFirst();
  AnalysisThread85 *A85 = (AnalysisThread85 *)p->takeFirst();
  AnalysisThread86 *A86 = (AnalysisThread86 *)p->takeFirst();
  AnalysisThread87 *A87 = (AnalysisThread87 *)p->takeFirst();
  AnalysisThread88 *A88 = (AnalysisThread88 *)p->takeFirst();
  AnalysisThread89 *A89 = (AnalysisThread89 *)p->takeFirst();
  AnalysisThread90 *A90 = (AnalysisThread90 *)p->takeFirst();
  AnalysisThread91 *A91 = (AnalysisThread91 *)p->takeFirst();
  AnalysisThread92 *A92 = (AnalysisThread92 *)p->takeFirst();
  AnalysisThread93 *A93 = (AnalysisThread93 *)p->takeFirst();
  AnalysisThread94 *A94 = (AnalysisThread94 *)p->takeFirst();
  AnalysisThread95 *A95 = (AnalysisThread95 *)p->takeFirst();
  AnalysisThread96 *A96 = (AnalysisThread96 *)p->takeFirst();
  AnalysisThread97 *A97 = (AnalysisThread97 *)p->takeFirst();
  AnalysisThread98 *A98 = (AnalysisThread98 *)p->takeFirst();
  AnalysisThread99 *A99 = (AnalysisThread99 *)p->takeFirst();
  p->push_back(simdaq1);
  p->push_back(A00);
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
  p->push_back(A51);
  p->push_back(A52);
  p->push_back(A53);
  p->push_back(A54);
  p->push_back(A55);
  p->push_back(A56);
  p->push_back(A57);
  p->push_back(A58);
  p->push_back(A59);
  p->push_back(A60);
  p->push_back(A61);
  p->push_back(A62);
  p->push_back(A63);
  p->push_back(A64);
  p->push_back(A65);
  p->push_back(A66);
  p->push_back(A67);
  p->push_back(A68);
  p->push_back(A69);
  p->push_back(A70);
  p->push_back(A71);
  p->push_back(A72);
  p->push_back(A73);
  p->push_back(A74);
  p->push_back(A75);
  p->push_back(A76);
  p->push_back(A77);
  p->push_back(A78);
  p->push_back(A79);
  p->push_back(A80);
  p->push_back(A81);
  p->push_back(A82);
  p->push_back(A83);
  p->push_back(A84);
  p->push_back(A85);
  p->push_back(A86);
  p->push_back(A87);
  p->push_back(A88);
  p->push_back(A89);
  p->push_back(A90);
  p->push_back(A91);
  p->push_back(A92);
  p->push_back(A93);
  p->push_back(A94);
  p->push_back(A95);
  p->push_back(A96);
  p->push_back(A97);
  p->push_back(A98);
  p->push_back(A99);

  // Analysis
  A00->Initialize(1);
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
  A51->Initialize(1);
  A52->Initialize(1);
  A53->Initialize(1);
  A54->Initialize(1);
  A55->Initialize(1);
  A56->Initialize(1);
  A57->Initialize(1);
  A58->Initialize(1);
  A59->Initialize(1);
  A60->Initialize(1);
  A61->Initialize(1);
  A62->Initialize(1);
  A63->Initialize(1);
  A64->Initialize(1);
  A65->Initialize(1);
  A66->Initialize(1);
  A67->Initialize(1);
  A68->Initialize(1);
  A69->Initialize(1);
  A70->Initialize(1);
  A71->Initialize(1);
  A72->Initialize(1);
  A73->Initialize(1);
  A74->Initialize(1);
  A75->Initialize(1);
  A76->Initialize(1);
  A77->Initialize(1);
  A78->Initialize(1);
  A79->Initialize(1);
  A80->Initialize(1);
  A81->Initialize(1);
  A82->Initialize(1);
  A83->Initialize(1);
  A84->Initialize(1);
  A85->Initialize(1);
  A86->Initialize(1);
  A87->Initialize(1);
  A88->Initialize(1);
  A89->Initialize(1);
  A90->Initialize(1);
  A91->Initialize(1);
  A92->Initialize(1);
  A93->Initialize(1);
  A94->Initialize(1);
  A95->Initialize(1);
  A96->Initialize(1);
  A97->Initialize(1);
  A98->Initialize(1);
  A99->Initialize(1);
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
  histDraw_Scroll->AddHist(A00->GetHistogram("Analysis 00 - Channel 0"));
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
  histDraw_Scroll->AddHist(A51->GetHistogram("Analysis 51 - Channel 0"));
  histDraw_Scroll->AddHist(A52->GetHistogram("Analysis 52 - Channel 0"));
  histDraw_Scroll->AddHist(A53->GetHistogram("Analysis 53 - Channel 0"));
  histDraw_Scroll->AddHist(A54->GetHistogram("Analysis 54 - Channel 0"));
  histDraw_Scroll->AddHist(A55->GetHistogram("Analysis 55 - Channel 0"));
  histDraw_Scroll->AddHist(A56->GetHistogram("Analysis 56 - Channel 0"));
  histDraw_Scroll->AddHist(A57->GetHistogram("Analysis 57 - Channel 0"));
  histDraw_Scroll->AddHist(A58->GetHistogram("Analysis 58 - Channel 0"));
  histDraw_Scroll->AddHist(A59->GetHistogram("Analysis 59 - Channel 0"));
  histDraw_Scroll->AddHist(A60->GetHistogram("Analysis 60 - Channel 0"));
  histDraw_Scroll->AddHist(A61->GetHistogram("Analysis 61 - Channel 0"));
  histDraw_Scroll->AddHist(A62->GetHistogram("Analysis 62 - Channel 0"));
  histDraw_Scroll->AddHist(A63->GetHistogram("Analysis 63 - Channel 0"));
  histDraw_Scroll->AddHist(A64->GetHistogram("Analysis 64 - Channel 0"));
  histDraw_Scroll->AddHist(A65->GetHistogram("Analysis 65 - Channel 0"));
  histDraw_Scroll->AddHist(A66->GetHistogram("Analysis 66 - Channel 0"));
  histDraw_Scroll->AddHist(A67->GetHistogram("Analysis 67 - Channel 0"));
  histDraw_Scroll->AddHist(A68->GetHistogram("Analysis 68 - Channel 0"));
  histDraw_Scroll->AddHist(A69->GetHistogram("Analysis 69 - Channel 0"));
  histDraw_Scroll->AddHist(A70->GetHistogram("Analysis 70 - Channel 0"));
  histDraw_Scroll->AddHist(A71->GetHistogram("Analysis 71 - Channel 0"));
  histDraw_Scroll->AddHist(A72->GetHistogram("Analysis 72 - Channel 0"));
  histDraw_Scroll->AddHist(A73->GetHistogram("Analysis 73 - Channel 0"));
  histDraw_Scroll->AddHist(A74->GetHistogram("Analysis 74 - Channel 0"));
  histDraw_Scroll->AddHist(A75->GetHistogram("Analysis 75 - Channel 0"));
  histDraw_Scroll->AddHist(A76->GetHistogram("Analysis 76 - Channel 0"));
  histDraw_Scroll->AddHist(A77->GetHistogram("Analysis 77 - Channel 0"));
  histDraw_Scroll->AddHist(A78->GetHistogram("Analysis 78 - Channel 0"));
  histDraw_Scroll->AddHist(A79->GetHistogram("Analysis 79 - Channel 0"));
  histDraw_Scroll->AddHist(A80->GetHistogram("Analysis 80 - Channel 0"));
  histDraw_Scroll->AddHist(A81->GetHistogram("Analysis 81 - Channel 0"));
  histDraw_Scroll->AddHist(A82->GetHistogram("Analysis 82 - Channel 0"));
  histDraw_Scroll->AddHist(A83->GetHistogram("Analysis 83 - Channel 0"));
  histDraw_Scroll->AddHist(A84->GetHistogram("Analysis 84 - Channel 0"));
  histDraw_Scroll->AddHist(A85->GetHistogram("Analysis 85 - Channel 0"));
  histDraw_Scroll->AddHist(A86->GetHistogram("Analysis 86 - Channel 0"));
  histDraw_Scroll->AddHist(A87->GetHistogram("Analysis 87 - Channel 0"));
  histDraw_Scroll->AddHist(A88->GetHistogram("Analysis 88 - Channel 0"));
  histDraw_Scroll->AddHist(A89->GetHistogram("Analysis 89 - Channel 0"));
  histDraw_Scroll->AddHist(A90->GetHistogram("Analysis 90 - Channel 0"));
  histDraw_Scroll->AddHist(A91->GetHistogram("Analysis 91 - Channel 0"));
  histDraw_Scroll->AddHist(A92->GetHistogram("Analysis 92 - Channel 0"));
  histDraw_Scroll->AddHist(A93->GetHistogram("Analysis 93 - Channel 0"));
  histDraw_Scroll->AddHist(A94->GetHistogram("Analysis 94 - Channel 0"));
  histDraw_Scroll->AddHist(A95->GetHistogram("Analysis 95 - Channel 0"));
  histDraw_Scroll->AddHist(A96->GetHistogram("Analysis 96 - Channel 0"));
  histDraw_Scroll->AddHist(A97->GetHistogram("Analysis 97 - Channel 0"));
  histDraw_Scroll->AddHist(A98->GetHistogram("Analysis 98 - Channel 0"));
  histDraw_Scroll->AddHist(A99->GetHistogram("Analysis 99 - Channel 0"));
  histDraw_Scroll->SetGridMajor(25,4);
  histDraw_Scroll->SetGridMinor(3,4);
  histDraw_Scroll->SetGridMinorUpperLeft(0,0);
  histDraw_Scroll->SetXLabelAll("Channel");
  histDraw_Scroll->SetYLabelAll("Counts");
  histDraw_Scroll->SetLogScaleAll(true);
  histDraw_Scroll->SetForegroundColor(A00->GetHistogram("Analysis 00 - Channel 0"), QColor(255,  0,  0));
  histDraw_Scroll->SetForegroundColor(A01->GetHistogram("Analysis 01 - Channel 0"), QColor(255, 13,  0));
  histDraw_Scroll->SetForegroundColor(A02->GetHistogram("Analysis 02 - Channel 0"), QColor(255, 26,  0));
  histDraw_Scroll->SetForegroundColor(A03->GetHistogram("Analysis 03 - Channel 0"), QColor(255, 39,  0));
  histDraw_Scroll->SetForegroundColor(A04->GetHistogram("Analysis 04 - Channel 0"), QColor(255, 52,  0));
  histDraw_Scroll->SetForegroundColor(A05->GetHistogram("Analysis 05 - Channel 0"), QColor(255, 65,  0));
  histDraw_Scroll->SetForegroundColor(A06->GetHistogram("Analysis 06 - Channel 0"), QColor(255, 78,  0));
  histDraw_Scroll->SetForegroundColor(A07->GetHistogram("Analysis 07 - Channel 0"), QColor(255, 91,  0));
  histDraw_Scroll->SetForegroundColor(A08->GetHistogram("Analysis 08 - Channel 0"), QColor(255,104,  0));
  histDraw_Scroll->SetForegroundColor(A09->GetHistogram("Analysis 09 - Channel 0"), QColor(255,117,  0));
  histDraw_Scroll->SetForegroundColor(A10->GetHistogram("Analysis 10 - Channel 0"), QColor(255,130,  0));
  histDraw_Scroll->SetForegroundColor(A11->GetHistogram("Analysis 11 - Channel 0"), QColor(255,143,  0));
  histDraw_Scroll->SetForegroundColor(A12->GetHistogram("Analysis 12 - Channel 0"), QColor(255,156,  0));
  histDraw_Scroll->SetForegroundColor(A13->GetHistogram("Analysis 13 - Channel 0"), QColor(255,169,  0));
  histDraw_Scroll->SetForegroundColor(A14->GetHistogram("Analysis 14 - Channel 0"), QColor(255,182,  0));
  histDraw_Scroll->SetForegroundColor(A15->GetHistogram("Analysis 15 - Channel 0"), QColor(255,195,  0));
  histDraw_Scroll->SetForegroundColor(A16->GetHistogram("Analysis 16 - Channel 0"), QColor(255,208,  0));
  histDraw_Scroll->SetForegroundColor(A17->GetHistogram("Analysis 17 - Channel 0"), QColor(255,221,  0));
  histDraw_Scroll->SetForegroundColor(A18->GetHistogram("Analysis 18 - Channel 0"), QColor(255,234,  0));
  histDraw_Scroll->SetForegroundColor(A19->GetHistogram("Analysis 19 - Channel 0"), QColor(255,247,  0));
  histDraw_Scroll->SetForegroundColor(A20->GetHistogram("Analysis 20 - Channel 0"), QColor(255,255,  0));
  histDraw_Scroll->SetForegroundColor(A21->GetHistogram("Analysis 21 - Channel 0"), QColor(247,255,  0));
  histDraw_Scroll->SetForegroundColor(A22->GetHistogram("Analysis 22 - Channel 0"), QColor(234,255,  0));
  histDraw_Scroll->SetForegroundColor(A23->GetHistogram("Analysis 23 - Channel 0"), QColor(221,255,  0));
  histDraw_Scroll->SetForegroundColor(A24->GetHistogram("Analysis 24 - Channel 0"), QColor(208,255,  0));
  histDraw_Scroll->SetForegroundColor(A25->GetHistogram("Analysis 25 - Channel 0"), QColor(195,255,  0));
  histDraw_Scroll->SetForegroundColor(A26->GetHistogram("Analysis 26 - Channel 0"), QColor(182,255,  0));
  histDraw_Scroll->SetForegroundColor(A27->GetHistogram("Analysis 27 - Channel 0"), QColor(169,255,  0));
  histDraw_Scroll->SetForegroundColor(A28->GetHistogram("Analysis 28 - Channel 0"), QColor(156,255,  0));
  histDraw_Scroll->SetForegroundColor(A29->GetHistogram("Analysis 29 - Channel 0"), QColor(143,255,  0));
  histDraw_Scroll->SetForegroundColor(A30->GetHistogram("Analysis 30 - Channel 0"), QColor(130,255,  0));
  histDraw_Scroll->SetForegroundColor(A31->GetHistogram("Analysis 31 - Channel 0"), QColor(117,255,  0));
  histDraw_Scroll->SetForegroundColor(A32->GetHistogram("Analysis 32 - Channel 0"), QColor(104,255,  0));
  histDraw_Scroll->SetForegroundColor(A33->GetHistogram("Analysis 33 - Channel 0"), QColor( 91,255,  0));
  histDraw_Scroll->SetForegroundColor(A34->GetHistogram("Analysis 34 - Channel 0"), QColor( 78,255,  0));
  histDraw_Scroll->SetForegroundColor(A35->GetHistogram("Analysis 35 - Channel 0"), QColor( 65,255,  0));
  histDraw_Scroll->SetForegroundColor(A36->GetHistogram("Analysis 36 - Channel 0"), QColor( 52,255,  0));
  histDraw_Scroll->SetForegroundColor(A37->GetHistogram("Analysis 37 - Channel 0"), QColor( 39,255,  0));
  histDraw_Scroll->SetForegroundColor(A38->GetHistogram("Analysis 38 - Channel 0"), QColor( 26,255,  0));
  histDraw_Scroll->SetForegroundColor(A39->GetHistogram("Analysis 39 - Channel 0"), QColor( 13,255,  0));
  histDraw_Scroll->SetForegroundColor(A40->GetHistogram("Analysis 40 - Channel 0"), QColor(  0,255,  0));
  histDraw_Scroll->SetForegroundColor(A41->GetHistogram("Analysis 41 - Channel 0"), QColor(  0,255, 13));
  histDraw_Scroll->SetForegroundColor(A42->GetHistogram("Analysis 42 - Channel 0"), QColor(  0,255, 26));
  histDraw_Scroll->SetForegroundColor(A43->GetHistogram("Analysis 43 - Channel 0"), QColor(  0,255, 39));
  histDraw_Scroll->SetForegroundColor(A44->GetHistogram("Analysis 44 - Channel 0"), QColor(  0,255, 52));
  histDraw_Scroll->SetForegroundColor(A45->GetHistogram("Analysis 45 - Channel 0"), QColor(  0,255, 65));
  histDraw_Scroll->SetForegroundColor(A46->GetHistogram("Analysis 46 - Channel 0"), QColor(  0,255, 78));
  histDraw_Scroll->SetForegroundColor(A47->GetHistogram("Analysis 47 - Channel 0"), QColor(  0,255, 91));
  histDraw_Scroll->SetForegroundColor(A48->GetHistogram("Analysis 48 - Channel 0"), QColor(  0,255,104));
  histDraw_Scroll->SetForegroundColor(A49->GetHistogram("Analysis 49 - Channel 0"), QColor(  0,255,117));
  histDraw_Scroll->SetForegroundColor(A50->GetHistogram("Analysis 50 - Channel 0"), QColor(  0,255,130));
  histDraw_Scroll->SetForegroundColor(A51->GetHistogram("Analysis 51 - Channel 0"), QColor(  0,255,143));
  histDraw_Scroll->SetForegroundColor(A52->GetHistogram("Analysis 52 - Channel 0"), QColor(  0,255,156));
  histDraw_Scroll->SetForegroundColor(A53->GetHistogram("Analysis 53 - Channel 0"), QColor(  0,255,169));
  histDraw_Scroll->SetForegroundColor(A54->GetHistogram("Analysis 54 - Channel 0"), QColor(  0,255,182));
  histDraw_Scroll->SetForegroundColor(A55->GetHistogram("Analysis 55 - Channel 0"), QColor(  0,255,195));
  histDraw_Scroll->SetForegroundColor(A56->GetHistogram("Analysis 56 - Channel 0"), QColor(  0,255,208));
  histDraw_Scroll->SetForegroundColor(A57->GetHistogram("Analysis 57 - Channel 0"), QColor(  0,255,221));
  histDraw_Scroll->SetForegroundColor(A58->GetHistogram("Analysis 58 - Channel 0"), QColor(  0,255,234));
  histDraw_Scroll->SetForegroundColor(A59->GetHistogram("Analysis 59 - Channel 0"), QColor(  0,255,247));
  histDraw_Scroll->SetForegroundColor(A60->GetHistogram("Analysis 60 - Channel 0"), QColor(  0,255,255));
  histDraw_Scroll->SetForegroundColor(A61->GetHistogram("Analysis 61 - Channel 0"), QColor(  0,247,255));
  histDraw_Scroll->SetForegroundColor(A62->GetHistogram("Analysis 62 - Channel 0"), QColor(  0,234,255));
  histDraw_Scroll->SetForegroundColor(A63->GetHistogram("Analysis 63 - Channel 0"), QColor(  0,221,255));
  histDraw_Scroll->SetForegroundColor(A64->GetHistogram("Analysis 64 - Channel 0"), QColor(  0,208,255));
  histDraw_Scroll->SetForegroundColor(A65->GetHistogram("Analysis 65 - Channel 0"), QColor(  0,195,255));
  histDraw_Scroll->SetForegroundColor(A66->GetHistogram("Analysis 66 - Channel 0"), QColor(  0,182,255));
  histDraw_Scroll->SetForegroundColor(A67->GetHistogram("Analysis 67 - Channel 0"), QColor(  0,169,255));
  histDraw_Scroll->SetForegroundColor(A68->GetHistogram("Analysis 68 - Channel 0"), QColor(  0,156,255));
  histDraw_Scroll->SetForegroundColor(A69->GetHistogram("Analysis 69 - Channel 0"), QColor(  0,143,255));
  histDraw_Scroll->SetForegroundColor(A70->GetHistogram("Analysis 70 - Channel 0"), QColor(  0,130,255));
  histDraw_Scroll->SetForegroundColor(A71->GetHistogram("Analysis 71 - Channel 0"), QColor(  0,117,255));
  histDraw_Scroll->SetForegroundColor(A72->GetHistogram("Analysis 72 - Channel 0"), QColor(  0,104,255));
  histDraw_Scroll->SetForegroundColor(A73->GetHistogram("Analysis 73 - Channel 0"), QColor(  0, 91,255));
  histDraw_Scroll->SetForegroundColor(A74->GetHistogram("Analysis 74 - Channel 0"), QColor(  0, 78,255));
  histDraw_Scroll->SetForegroundColor(A75->GetHistogram("Analysis 75 - Channel 0"), QColor(  0, 65,255));
  histDraw_Scroll->SetForegroundColor(A76->GetHistogram("Analysis 76 - Channel 0"), QColor(  0, 52,255));
  histDraw_Scroll->SetForegroundColor(A77->GetHistogram("Analysis 77 - Channel 0"), QColor(  0, 39,255));
  histDraw_Scroll->SetForegroundColor(A78->GetHistogram("Analysis 78 - Channel 0"), QColor(  0, 26,255));
  histDraw_Scroll->SetForegroundColor(A79->GetHistogram("Analysis 79 - Channel 0"), QColor(  0, 13,255));
  histDraw_Scroll->SetForegroundColor(A80->GetHistogram("Analysis 80 - Channel 0"), QColor(  0,  0,255));
  histDraw_Scroll->SetForegroundColor(A81->GetHistogram("Analysis 81 - Channel 0"), QColor( 13,  0,255));
  histDraw_Scroll->SetForegroundColor(A82->GetHistogram("Analysis 82 - Channel 0"), QColor( 26,  0,255));
  histDraw_Scroll->SetForegroundColor(A83->GetHistogram("Analysis 83 - Channel 0"), QColor( 39,  0,255));
  histDraw_Scroll->SetForegroundColor(A84->GetHistogram("Analysis 84 - Channel 0"), QColor( 52,  0,255));
  histDraw_Scroll->SetForegroundColor(A85->GetHistogram("Analysis 85 - Channel 0"), QColor( 65,  0,255));
  histDraw_Scroll->SetForegroundColor(A86->GetHistogram("Analysis 86 - Channel 0"), QColor( 78,  0,255));
  histDraw_Scroll->SetForegroundColor(A87->GetHistogram("Analysis 87 - Channel 0"), QColor( 91,  0,255));
  histDraw_Scroll->SetForegroundColor(A88->GetHistogram("Analysis 88 - Channel 0"), QColor(104,  0,255));
  histDraw_Scroll->SetForegroundColor(A89->GetHistogram("Analysis 89 - Channel 0"), QColor(117,  0,255));
  histDraw_Scroll->SetForegroundColor(A90->GetHistogram("Analysis 90 - Channel 0"), QColor(130,  0,255));
  histDraw_Scroll->SetForegroundColor(A91->GetHistogram("Analysis 91 - Channel 0"), QColor(143,  0,255));
  histDraw_Scroll->SetForegroundColor(A92->GetHistogram("Analysis 92 - Channel 0"), QColor(156,  0,255));
  histDraw_Scroll->SetForegroundColor(A93->GetHistogram("Analysis 93 - Channel 0"), QColor(169,  0,255));
  histDraw_Scroll->SetForegroundColor(A94->GetHistogram("Analysis 94 - Channel 0"), QColor(182,  0,255));
  histDraw_Scroll->SetForegroundColor(A95->GetHistogram("Analysis 95 - Channel 0"), QColor(195,  0,255));
  histDraw_Scroll->SetForegroundColor(A96->GetHistogram("Analysis 96 - Channel 0"), QColor(208,  0,255));
  histDraw_Scroll->SetForegroundColor(A97->GetHistogram("Analysis 97 - Channel 0"), QColor(221,  0,255));
  histDraw_Scroll->SetForegroundColor(A98->GetHistogram("Analysis 98 - Channel 0"), QColor(234,  0,255));
  histDraw_Scroll->SetForegroundColor(A99->GetHistogram("Analysis 99 - Channel 0"), QColor(255,  0,255));
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
