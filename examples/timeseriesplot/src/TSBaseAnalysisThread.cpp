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

#include "TSBaseAnalysisThread.h"

TSBaseAnalysisThread::TSBaseAnalysisThread() {
    raw_data_ = new QList<point*>();
    computed_data_ = new QList<QPair<qint64, double>* >();
}

TSBaseAnalysisThread::~TSBaseAnalysisThread() {
    delete raw_data_;
    delete computed_data_;
}

int TSBaseAnalysisThread::Analyze() {
    // get next data
    QPair<int, point*> nxtpt = ReadData<point>("DAQ", "points");
    raw_data_.push_back(nxtpt.second);
    computed_data_.push_back(compute(raw_data_));
    return 0;
}