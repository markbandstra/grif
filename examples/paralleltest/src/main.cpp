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
#include "AnalysisThreadInitial.h"
#include "AnalysisThreadFinal.h"
#include "AnalysisThreadParallel.h"

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
  Q_ASSERT(p->size()==NUM_ANALYSIS_THREADS+3);
  // be careful not to remove anything
  SIMDAQThread *simdaq  = (SIMDAQThread *)p->takeFirst();
  AnalysisThreadInitial *A  = (AnalysisThreadInitial *)p->takeFirst();
  AnalysisThreadParallel *B[NUM_ANALYSIS_THREADS];
  for (int j=0; j < NUM_ANALYSIS_THREADS; j++) {
    B[j] = (AnalysisThreadParallel *)p->takeFirst();
  }
  AnalysisThreadFinal *C  = (AnalysisThreadFinal *)p->takeFirst();
  p->push_back(simdaq);
  p->push_back(A);
  for (int j=0; j < NUM_ANALYSIS_THREADS; j++) {
    p->push_back(B[j]);
  }
  p->push_back(C);

  // Analysis
  A->Initialize(NUM_ANALYSIS_THREADS);
  for (int j=0; j < NUM_ANALYSIS_THREADS; j++) {
    B[j]->Initialize(j);
  }
  C->Initialize(NUM_ANALYSIS_THREADS);

  // DAQ
  simdaq->init_chans(NUM_ANALYSIS_THREADS, 0, 1000, 200);
  // remove the peaks that each SIMDAQ is initialized with
  while (simdaq->get_npk() > 0) {
      simdaq->removePeak(0);
  }
  // add new peaks
  for (int j=0; j < NUM_ANALYSIS_THREADS; j++) {
    simdaq->addPeak(100 + 20*j, 5, 100, j);
  }

  QMainWindow *win1 = new QMainWindow();
  GRIHist1DGridWidget *histDraw = new GRIHist1DGridWidget(win1);
  win1->setCentralWidget(histDraw);
  win1->setWindowTitle("Initial and Final Analysis Threads");
  histDraw->AddHist(A->GetHistogram("Analysis Initial"));
  histDraw->AddHist(C->GetHistogram("Analysis Final"));
  histDraw->SetGridNx(1);
  histDraw->SetXLabelAll("Channel");
  histDraw->SetYLabelAll("Counts");
  histDraw->SetLogScaleAll(true);
  histDraw->SetForegroundColor(A->GetHistogram("Analysis Initial"), QColor(255,0,0));
  histDraw->SetForegroundColor(C->GetHistogram("Analysis Final"), QColor(255,0,255));
  win1->resize(400,600);
  win1->show();

  QMainWindow *win7 = new QMainWindow();
  GRIHist1DGridScrollWidget *histDraw_Scroll = new GRIHist1DGridScrollWidget(win7);
  win7->setCentralWidget(histDraw_Scroll);
  win7->setWindowTitle("Parallel Analysis Threads");
  for (int j=0; j < NUM_ANALYSIS_THREADS; j++) {
    histDraw_Scroll->AddHist(B[j]->GetHistogram("Analysis Parallel "+B[j]->ThreadNumber()));
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
      histDraw_Scroll->SetForegroundColor(B[j]->GetHistogram("Analysis Parallel "+B[j]->ThreadNumber()),
                                          QColor(255, (int)color_step*index, 0));
    } else if (((int)1*steps_per_color<=j) && (j<(int)2*steps_per_color)) {
      int index = j - (int)1*steps_per_color;
      histDraw_Scroll->SetForegroundColor(B[j]->GetHistogram("Analysis Parallel "+B[j]->ThreadNumber()),
                                          QColor(255-(int)color_step*index, 255, 0));
    } else if (((int)2*steps_per_color<=j) && (j<(int)3*steps_per_color)) {
      int index = j - (int)2*steps_per_color;
      histDraw_Scroll->SetForegroundColor(B[j]->GetHistogram("Analysis Parallel "+B[j]->ThreadNumber()),
                                          QColor(0, 255, (int)color_step*index));
    } else if (((int)3*steps_per_color<=j) && (j<(int)4*steps_per_color)) {
      int index = j - (int)3*steps_per_color;
      histDraw_Scroll->SetForegroundColor(B[j]->GetHistogram("Analysis Parallel "+B[j]->ThreadNumber()),
                                          QColor(0, 255-(int)color_step*index, 255));
    } else if (((int)4*steps_per_color<=j) && (j<(int)5*steps_per_color)) {
      int index = j - (int)4*steps_per_color;
      histDraw_Scroll->SetForegroundColor(B[j]->GetHistogram("Analysis Parallel "+B[j]->ThreadNumber()),
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

  delete(win1);
  delete(win7);

  return 0;
}
