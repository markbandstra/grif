# Copyright (C) 2012 Gamma-ray Imaging Framework Team
# 
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 3.0 of the License, or (at your option) any later version.
# 
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
# 
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
# 
# The license can be found in the LICENSE.txt file.
# 
# Contact:
# Dr. Daniel Chivers
# dhchivers@lbl.gov

QT       += core network xml
QT       += gui

TARGET = longchain
CONFIG   += console
TEMPLATE = app

DEPENDPATH += ../../ . \
        ./src \
        ./include \
        ../../framework/source \
        ../../framework/include \
        ../../framework/source/hist \
        ../../framework/include/hist


INCLUDEPATH += ../../ . \
        ./include \
        ../../framework/include \
        ../../framework/source \
        ../../framework/source/hist \
        ../../framework/include/hist

include(../../framework/source/fsource.pri)
include(../../framework/include/finclude.pri)

# Source file and headers
SOURCES += \
    ./src/main.cpp \
    ./src/AnalysisThread01.cpp \
    ./src/AnalysisThread02.cpp \
    ./src/AnalysisThread03.cpp \
    ./src/AnalysisThread04.cpp \
    ./src/AnalysisThread05.cpp \
    ./src/AnalysisThread06.cpp \
    ./src/AnalysisThread07.cpp \
    ./src/AnalysisThread08.cpp \
    ./src/AnalysisThread09.cpp \
    ./src/AnalysisThread10.cpp \
    ./src/AnalysisThread11.cpp \
    ./src/AnalysisThread12.cpp \
    ./src/AnalysisThread13.cpp \
    ./src/AnalysisThread14.cpp \
    ./src/AnalysisThread15.cpp \
    ./src/SIMDAQThread.cpp

HEADERS += \
    ./include/AnalysisThread01.h \
    ./include/AnalysisThread02.h \
    ./include/AnalysisThread03.h \
    ./include/AnalysisThread04.h \
    ./include/AnalysisThread05.h \
    ./include/AnalysisThread06.h \
    ./include/AnalysisThread07.h \
    ./include/AnalysisThread08.h \
    ./include/AnalysisThread09.h \
    ./include/AnalysisThread10.h \
    ./include/AnalysisThread11.h \
    ./include/AnalysisThread12.h \
    ./include/AnalysisThread13.h \
    ./include/AnalysisThread14.h \
    ./include/AnalysisThread15.h \
    ./include/SIMDAQThread.h

## 
# Please fill in GRIFDIR and ROOTDIR with the appropriate paths
# Top directory of GRIF on your machine:
GRIFDIR = /Users/markbandstra/Projects/GRIF/grif
# Directory of ROOT on your machine:
ROOTDIR = /Users/markbandstra/Software/root

# run code generation
GRIFPROJECTDIR = $$GRIFDIR/examples/longchain
UTILDIR = $$GRIFDIR/util
system(cd $$UTILDIR && python setup.py $$GRIFPROJECTDIR)
QMAKE_CLEAN += $$GRIFDIR/framework/include/GCG/*

QMAKE_CXXFLAGS += -D GRIF_CODE_GENERATION=1 -O3

DEFINES += GRIFPROJECTDIR=$${GRIFPROJECTDIR}
# set up log directory
GRIF_LOG_DIR = $$GRIFPROJECTDIR/log/
win32 {
    GRIF_LOG_DIR = $$GRIFPROJECTDIR\\log
}

DEFINES += GRIF_LOG_DIR=\\\"$${GRIF_LOG_DIR}\\\"
# External libraries
INCLUDEPATH += $$GRIFDIR/external

# ROOT headers
INCLUDEPATH += $$ROOTDIR/include
# ROOT libraries
ROOTSYSLIB = $$ROOTDIR/lib
INCLUDEPATH += $$ROOTSYSLIB

# All *nix systems
unix|macx {
    LIBS += -L$$ROOTSYSLIB
    LIBS += -L$$ROOTSYS/lib -lCore -lHist -lMatrix -lMathCore -lCint
}
# All windows platforms
win32 {
    LIBS += -L$$ROOTSYSLIB
    LIBS += -L$$ROOTSYS/lib -llibCore -llibHist -llibMatrix -llibMathCore -llibCint
}
