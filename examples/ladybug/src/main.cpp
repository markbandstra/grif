#include <stdio.h>
#include <stdlib.h>
#include <QtGui/QApplication>
#include <QtCore/QCoreApplication>
#include <QtGui/QtGui>
#include <QtCore>
#include <QLinkedList>
#include <Qt>
#include "GRICLI.h"
#include "GRIDefines.h"
#include "GRILoader.h"
#include "GRIUserLoader.h"
#include "GRIMemoryManager.h"
#include "GRIRegulator.h"
#ifdef Q_OS_WIN
  //#include <windows.h>
#endif

int main(int argc, char* argv[]) {
  // the following will be included for all programs
  QCoreApplication app(argc, argv);
  GRIMemoryManager *mm = new GRIMemoryManager();
  GRIRegulator *reg = new GRIRegulator(mm);

  // the following will be included for all programs
  GRILoader *loader = new GRIUserLoader(reg);
  loader->initRegulatorDetails();
  reg->Start();
#ifdef Q_OS_WIN
  //Sleep(5);
#else
  sleep(5);
#endif
  reg->Stop();
#ifdef Q_OS_WIN
  //Sleep(5);
#else
  sleep(5);
#endif
  std::cout << "done..." << std::endl;
  return app.exec();
}
