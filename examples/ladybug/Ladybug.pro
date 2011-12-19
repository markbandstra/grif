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
    ./include/LBAnalysisThread.h \
    ./include/LBDAQThread.h
SOURCES += \
    ./src/main.cpp \
    ./src/LBAnalysisThread.cpp \
    ./src/LBDAQThread.cpp

# GRIFDIR is the head directory of GRIF on your machine
# ***You must set GRIFDIR as an environment variable***
GRIFDIR=/Users/benson/Desktop/grif

# root headers
ROOTDIR=/Users/benson/Desktop/root_x86_64
INCLUDEPATH += $$ROOTDIR/include

ROOTSYSLIB += $$ROOTDIR/lib
INCLUDEPATH += $$ROOTSYSLIB
LIBS += $$ROOTSYSLIB/libCint.so
LIBS += $$ROOTSYSLIB/libMatrix.so
LIBS += $$ROOTSYSLIB/libMathCore.so
LIBS += -L/$$ROOTSYSLIB
LIBS += -L$$ROOTSYS/lib -lCore -lHist

EXTDIR = $$GRIFDIR/external
INCLUDEPATH += EXTDIR

# run code generation
macx|unix {
    system(cd $$GRIFPROJECTDIR; ./setup.py)
}
win32 {
    system(cd $$GRIFPROJECTDIR; python setup.py)
}

QMAKE_CXXFLAGS += -D GRIF_CODE_GENERATION=1 -O3
