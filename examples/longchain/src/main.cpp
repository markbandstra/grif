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
  histDraw_Scroll->SetGridMajor(8,2);
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
