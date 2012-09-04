
// Include the header:
#include "EventClassArray.h"

EventClassArray::EventClassArray() {
  //  energy_.clear();
  //  chan_.clear();
  //  ts_.clear();
  energy_size_ = 0;
  chan_size_ = 0;
  ts_size_ = 0;
}

EventClassArray::~EventClassArray() {
  //  energy_.clear();
  //  chan_.clear();
  //  ts_.clear();
  energy_size_ = 0;
  chan_size_ = 0;
  ts_size_ = 0;
}

void EventClassArray::energy_append(double energy) {
  if (this->energy_size() < MAX_LENGTH) {
    //  energy_.push_back(energy);
    energy_[energy_size_] = energy;
    energy_size_++;
  }
}

double EventClassArray::energy(int i) {
  if (i < this->energy_size())
    return energy_[i];
//  Q_ASSERT(false);
  return -1000000.0;
}

void EventClassArray::chan_append(int chan) {
  if (this->chan_size() < MAX_LENGTH) {
    //  chan_.push_back(chan);
    chan_[chan_size_] = chan;
    chan_size_++;
  }
}

int EventClassArray::chan(int i) {
  if (i < this->chan_size())
    return chan_[i];
//  Q_ASSERT(false);
  return -1000000;
}

void EventClassArray::ts_append(qint64 ts) {
  if (this->ts_size() < MAX_LENGTH) {
    //  ts_.push_back(ts);
    ts_[ts_size_] = ts;
    ts_size_++;
  }
}

qint64 EventClassArray::ts(int i) {
  if (i < this->ts_size())
    return ts_[i];
//  Q_ASSERT(false);
  return qint64(-1000000);
}
