
// Include the header:
#include "EventClassVector.h"

EventClassVector::EventClassVector() {
  energy_.clear();
  chan_.clear();
  ts_.clear();
//  energy_size_ = 0;
//  chan_size_ = 0;
//  ts_size_ = 0;
}

EventClassVector::~EventClassVector() {
  energy_.clear();
  chan_.clear();
  ts_.clear();
//  energy_size_ = 0;
//  chan_size_ = 0;
//  ts_size_ = 0;
}

void EventClassVector::energy_append(double energy) {
  if (this->energy_size() < MAX_LENGTH) {
    energy_.push_back(energy);
//    energy_[energy_size_] = energy;
//    energy_size_++;
  }
}

double EventClassVector::energy(int i) {
  if (i < this->energy_size())
    return energy_[i];
//  Q_ASSERT(false);
  return -1000000.0;
}

void EventClassVector::chan_append(int chan) {
  if (this->chan_size() < MAX_LENGTH) {
    chan_.push_back(chan);
//    chan_[num_chan_] = chan;
//    chan_size_++;
  }
}

int EventClassVector::chan(int i) {
  if (i < this->chan_size())
    return chan_[i];
//  Q_ASSERT(false);
  return -1000000;
}

void EventClassVector::ts_append(qint64 ts) {
  if (this->ts_size() < MAX_LENGTH) {
    ts_.push_back(ts);
//    ts_[ts_size_] = ts;
//    ts_size_++;
  }
}

qint64 EventClassVector::ts(int i) {
  if (i < this->ts_size())
    return ts_[i];
//  Q_ASSERT(false);
  return qint64(-1000000);
}
