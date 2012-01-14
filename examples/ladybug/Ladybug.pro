QT       += core network xml
QT       -= gui

TARGET = Ladybug

TEMPLATE = app

DEPENDPATH += ../../ . \
        ./src \
        ./include \
        ../../framework/source \
        ../../framework/include

INCLUDEPATH += ../../ . \
        ./include \
        ../../framework/include \
        ../../framework/source

include(../../framework/source/fsource.pri)
include(../../framework/include/finclude.pri)

# Your application files
HEADERS += \
    ./include/LBImAnalysisThread.h \
    ./include/LBImDAQThread.h \
    ./include/util.h
SOURCES += \
    ./src/main.cpp \
    ./src/LBImAnalysisThread.cpp \
    ./src/LBImDAQThread.cpp

# Ladybug headers
INCLUDEPATH += $$LBDIR/include

# ROOT headers
INCLUDEPATH += $$(ROOTDIR)/include

LADYBUGPATH = "H:/Program Files/Point Grey Research/PGR Ladybug"

macx|unix {
  ROOTSYSLIB += $$(ROOTDIR)/lib
  LIBS += -L$$ROOTSYS/lib -lCore -lHist
}

win32 {
  INCLUDEPATH += LADYBUG_PATH\include
  ROOTSYSLIB += $$(ROOTDIR)\lib
  LIBS += -L$$ROOTSYSLIB -llibCore -llibHist
  LIBS += -L$$LADYBUGPATH\lib -lladybug
}

INCLUDEPATH += $$ROOTSYSLIB

# Head GRIF directory
GRIF = $$(PWD)/../..

# External files
EXTDIR = $$(GRIF)/external
INCLUDEPATH += $$EXTDIR

GRIFPROJECTDIR = $$(GRIF)/examples/ladybug

# run code generation
macx|unix {
  system(cd $$GRIFPROJECTDIR; ./setup.py)
}
win32 {
  system(cd $$GRIFPROJECTDIR; python setup.py)
}

QMAKE_CXXFLAGS += -D GRIF_CODE_GENERATION=1

macx|unix {
 QMAKE_CXXFLAGS +=  -O3
}
