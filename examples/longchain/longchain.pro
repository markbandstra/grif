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
    ./src/AnalysisThread00.cpp \
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
    ./src/AnalysisThread16.cpp \
    ./src/AnalysisThread17.cpp \
    ./src/AnalysisThread18.cpp \
    ./src/AnalysisThread19.cpp \
    ./src/AnalysisThread20.cpp \
    ./src/AnalysisThread21.cpp \
    ./src/AnalysisThread22.cpp \
    ./src/AnalysisThread23.cpp \
    ./src/AnalysisThread24.cpp \
    ./src/AnalysisThread25.cpp \
    ./src/AnalysisThread26.cpp \
    ./src/AnalysisThread27.cpp \
    ./src/AnalysisThread28.cpp \
    ./src/AnalysisThread29.cpp \
    ./src/AnalysisThread30.cpp \
    ./src/AnalysisThread31.cpp \
    ./src/AnalysisThread32.cpp \
    ./src/AnalysisThread33.cpp \
    ./src/AnalysisThread34.cpp \
    ./src/AnalysisThread35.cpp \
    ./src/AnalysisThread36.cpp \
    ./src/AnalysisThread37.cpp \
    ./src/AnalysisThread38.cpp \
    ./src/AnalysisThread39.cpp \
    ./src/AnalysisThread40.cpp \
    ./src/AnalysisThread41.cpp \
    ./src/AnalysisThread42.cpp \
    ./src/AnalysisThread43.cpp \
    ./src/AnalysisThread44.cpp \
    ./src/AnalysisThread45.cpp \
    ./src/AnalysisThread46.cpp \
    ./src/AnalysisThread47.cpp \
    ./src/AnalysisThread48.cpp \
    ./src/AnalysisThread49.cpp \
    ./src/AnalysisThread50.cpp \
    ./src/AnalysisThread51.cpp \
    ./src/AnalysisThread52.cpp \
    ./src/AnalysisThread53.cpp \
    ./src/AnalysisThread54.cpp \
    ./src/AnalysisThread55.cpp \
    ./src/AnalysisThread56.cpp \
    ./src/AnalysisThread57.cpp \
    ./src/AnalysisThread58.cpp \
    ./src/AnalysisThread59.cpp \
    ./src/AnalysisThread60.cpp \
    ./src/AnalysisThread61.cpp \
    ./src/AnalysisThread62.cpp \
    ./src/AnalysisThread63.cpp \
    ./src/AnalysisThread64.cpp \
    ./src/AnalysisThread65.cpp \
    ./src/AnalysisThread66.cpp \
    ./src/AnalysisThread67.cpp \
    ./src/AnalysisThread68.cpp \
    ./src/AnalysisThread69.cpp \
    ./src/AnalysisThread70.cpp \
    ./src/AnalysisThread71.cpp \
    ./src/AnalysisThread72.cpp \
    ./src/AnalysisThread73.cpp \
    ./src/AnalysisThread74.cpp \
    ./src/AnalysisThread75.cpp \
    ./src/AnalysisThread76.cpp \
    ./src/AnalysisThread77.cpp \
    ./src/AnalysisThread78.cpp \
    ./src/AnalysisThread79.cpp \
    ./src/AnalysisThread80.cpp \
    ./src/AnalysisThread81.cpp \
    ./src/AnalysisThread82.cpp \
    ./src/AnalysisThread83.cpp \
    ./src/AnalysisThread84.cpp \
    ./src/AnalysisThread85.cpp \
    ./src/AnalysisThread86.cpp \
    ./src/AnalysisThread87.cpp \
    ./src/AnalysisThread88.cpp \
    ./src/AnalysisThread89.cpp \
    ./src/AnalysisThread90.cpp \
    ./src/AnalysisThread91.cpp \
    ./src/AnalysisThread92.cpp \
    ./src/AnalysisThread93.cpp \
    ./src/AnalysisThread94.cpp \
    ./src/AnalysisThread95.cpp \
    ./src/AnalysisThread96.cpp \
    ./src/AnalysisThread97.cpp \
    ./src/AnalysisThread98.cpp \
    ./src/AnalysisThread99.cpp \
    ./src/SIMDAQThread.cpp

HEADERS += \
    ./include/AnalysisThread00.h \
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
    ./include/AnalysisThread16.h \
    ./include/AnalysisThread17.h \
    ./include/AnalysisThread18.h \
    ./include/AnalysisThread19.h \
    ./include/AnalysisThread20.h \
    ./include/AnalysisThread21.h \
    ./include/AnalysisThread22.h \
    ./include/AnalysisThread23.h \
    ./include/AnalysisThread24.h \
    ./include/AnalysisThread25.h \
    ./include/AnalysisThread26.h \
    ./include/AnalysisThread27.h \
    ./include/AnalysisThread28.h \
    ./include/AnalysisThread29.h \
    ./include/AnalysisThread30.h \
    ./include/AnalysisThread31.h \
    ./include/AnalysisThread32.h \
    ./include/AnalysisThread33.h \
    ./include/AnalysisThread34.h \
    ./include/AnalysisThread35.h \
    ./include/AnalysisThread36.h \
    ./include/AnalysisThread37.h \
    ./include/AnalysisThread38.h \
    ./include/AnalysisThread39.h \
    ./include/AnalysisThread40.h \
    ./include/AnalysisThread41.h \
    ./include/AnalysisThread42.h \
    ./include/AnalysisThread43.h \
    ./include/AnalysisThread44.h \
    ./include/AnalysisThread45.h \
    ./include/AnalysisThread46.h \
    ./include/AnalysisThread47.h \
    ./include/AnalysisThread48.h \
    ./include/AnalysisThread49.h \
    ./include/AnalysisThread50.h \
    ./include/AnalysisThread51.h \
    ./include/AnalysisThread52.h \
    ./include/AnalysisThread53.h \
    ./include/AnalysisThread54.h \
    ./include/AnalysisThread55.h \
    ./include/AnalysisThread56.h \
    ./include/AnalysisThread57.h \
    ./include/AnalysisThread58.h \
    ./include/AnalysisThread59.h \
    ./include/AnalysisThread60.h \
    ./include/AnalysisThread61.h \
    ./include/AnalysisThread62.h \
    ./include/AnalysisThread63.h \
    ./include/AnalysisThread64.h \
    ./include/AnalysisThread65.h \
    ./include/AnalysisThread66.h \
    ./include/AnalysisThread67.h \
    ./include/AnalysisThread68.h \
    ./include/AnalysisThread69.h \
    ./include/AnalysisThread70.h \
    ./include/AnalysisThread71.h \
    ./include/AnalysisThread72.h \
    ./include/AnalysisThread73.h \
    ./include/AnalysisThread74.h \
    ./include/AnalysisThread75.h \
    ./include/AnalysisThread76.h \
    ./include/AnalysisThread77.h \
    ./include/AnalysisThread78.h \
    ./include/AnalysisThread79.h \
    ./include/AnalysisThread80.h \
    ./include/AnalysisThread81.h \
    ./include/AnalysisThread82.h \
    ./include/AnalysisThread83.h \
    ./include/AnalysisThread84.h \
    ./include/AnalysisThread85.h \
    ./include/AnalysisThread86.h \
    ./include/AnalysisThread87.h \
    ./include/AnalysisThread88.h \
    ./include/AnalysisThread89.h \
    ./include/AnalysisThread90.h \
    ./include/AnalysisThread91.h \
    ./include/AnalysisThread92.h \
    ./include/AnalysisThread93.h \
    ./include/AnalysisThread94.h \
    ./include/AnalysisThread95.h \
    ./include/AnalysisThread96.h \
    ./include/AnalysisThread97.h \
    ./include/AnalysisThread98.h \
    ./include/AnalysisThread99.h \
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
