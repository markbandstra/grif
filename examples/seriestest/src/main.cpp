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
#include "AnalysisThreadSeries.h"

#define NUM_CHANNELS 1
#define NUM_ANALYSIS_THREADS 30

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
  Q_ASSERT(p->size()==NUM_ANALYSIS_THREADS+1);
  // be careful not to remove anything
  SIMDAQThread *simdaq1  = (SIMDAQThread *)p->takeFirst();
  AnalysisThreadSeries * A[NUM_ANALYSIS_THREADS];
  for (int j=0; j < NUM_ANALYSIS_THREADS; j++) {
    A[j] = (AnalysisThreadSeries *)p->takeFirst();
  }
  p->push_back(simdaq1);
  for (int j=0; j < NUM_ANALYSIS_THREADS; j++) {
    p->push_back(A[j]);
  }

  // Analysis
  for (int j=0; j < NUM_ANALYSIS_THREADS; j++) {
    A[j]->Initialize(NUM_CHANNELS, j);
  }

  // DAQ1
  simdaq1->init_chans(NUM_CHANNELS, 0, 1000, 200);
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
  for (int j=0; j < NUM_ANALYSIS_THREADS; j++) {
    histDraw_Scroll->AddHist(A[j]->GetHistogram("Analysis "+A[j]->ThreadNumber()+" - Channel 0"));
  }
  histDraw_Scroll->SetGridMajor((NUM_ANALYSIS_THREADS+2)/3,3);
  histDraw_Scroll->SetGridMinor(3,3);
  histDraw_Scroll->SetGridMinorUpperLeft(0,0);
  histDraw_Scroll->SetXLabelAll("Channel");
  histDraw_Scroll->SetYLabelAll("Counts");
  histDraw_Scroll->SetLogScaleAll(true);

  double steps_per_color = ((double)NUM_ANALYSIS_THREADS)/5.0;
  double color_step = 255.0/steps_per_color;
  for (int j=0; j < NUM_ANALYSIS_THREADS; j++) {
    if (((int)0*steps_per_color<=j) && (j<(int)1*steps_per_color)) {
      int index = j - (int)0*steps_per_color;
      histDraw_Scroll->SetForegroundColor(A[j]->GetHistogram("Analysis "+A[j]->ThreadNumber()+" - Channel 0"),
                                          QColor(255, (int)color_step*index, 0));
    } else if ((int)(1*steps_per_color<=j) && (j<(int)2*steps_per_color)) {
      int index = j - (int)1*steps_per_color;
      histDraw_Scroll->SetForegroundColor(A[j]->GetHistogram("Analysis "+A[j]->ThreadNumber()+" - Channel 0"),
                                          QColor(255-(int)color_step*index, 255, 0));
    } else if (((int)2*steps_per_color<=j) && (j<(int)3*steps_per_color)) {
      int index = j - (int)2*steps_per_color;
      histDraw_Scroll->SetForegroundColor(A[j]->GetHistogram("Analysis "+A[j]->ThreadNumber()+" - Channel 0"),
                                          QColor(0, 255, (int)color_step*index));
    } else if (((int)3*steps_per_color<=j) && (j<(int)4*steps_per_color)) {
      int index = j - (int)3*steps_per_color;
      histDraw_Scroll->SetForegroundColor(A[j]->GetHistogram("Analysis "+A[j]->ThreadNumber()+" - Channel 0"),
                                          QColor(0, 255-(int)color_step*index, 255));
    } else if (((int)4*steps_per_color<=j) && (j<(int)5*steps_per_color)) {
      int index = j - (int)4*steps_per_color;
      histDraw_Scroll->SetForegroundColor(A[j]->GetHistogram("Analysis "+A[j]->ThreadNumber()+" - Channel 0"),
                                          QColor((int)color_step*index, 0, 255));
    }
  }
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
