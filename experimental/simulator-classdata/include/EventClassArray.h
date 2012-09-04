#ifndef __EVENTCLASSARRAY__
#define __EVENTCLASSARRAY__


////////////////////////////////////////////////////////////////////////////////

#define MAX_LENGTH 20

#include <Qt>
#include <QVector>

// ROOT libs:

// MEGAlib libs:

// Forward declarations:


////////////////////////////////////////////////////////////////////////////////


class EventClassArray {
 // public interface:
 public:
  // Standard constructor
  EventClassArray();
  // Default destructor
  ~EventClassArray();

  void energy_append(double energy);
//  int energy_size() { return energy_.size(); }
  int energy_size() { return energy_size_; }
  double energy(int i);

  void chan_append(int chan);
//  int chan_size() { return chan_.size(); }
  int chan_size() { return chan_size_; }
  int chan(int i);

  void ts_append(qint64 ts);
//  int ts_size() { return ts_.size(); }
  int ts_size() { return ts_size_; }
  qint64 ts(int i);

 private:
//  QVector<double> energy_;
  double energy_[MAX_LENGTH];
  int energy_size_;
//  QVector<int> chan_;
  int chan_[MAX_LENGTH];
  int chan_size_;
//  QVector<qint64> ts_;
  qint64 ts_[MAX_LENGTH];
  int ts_size_;

};

#endif
