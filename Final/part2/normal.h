#ifndef NORMAL_H
   #define NORMAL_H
#include <set>
#include <vector>
#include "trial.h"
using namespace std;

class Normal
{
protected:
  string name;
  multiset <Trial> trials;
public:
  Normal(const string &n, const vector <bool> &v, const vector <float> &t);
  void print () const;
  virtual float getTime() const;
  const string& getName() const {return name;}
};

class Multiple: public Normal
{
public:
  Multiple(const string &n, const vector <bool> &v, const vector <float> &t);
  float getTime() const;
};

#endif
