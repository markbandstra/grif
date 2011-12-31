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

# root headers
INCLUDEPATH += $$(ROOTDIR)/include

ROOTSYSLIB += $$(ROOTDIR)/lib
INCLUDEPATH += $$ROOTSYSLIB
LIBS += $$ROOTSYSLIB/libCint.so
LIBS += $$ROOTSYSLIB/libMatrix.so
LIBS += $$ROOTSYSLIB/libMathCore.so
LIBS += -L/$$ROOTSYSLIB
LIBS += -L$$ROOTSYS/lib -lCore -lHist

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

QMAKE_CXXFLAGS += -D GRIF_CODE_GENERATION=1 -O3
