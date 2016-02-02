#ifndef TRIAL_H
   #define TRIAL_H
#include <iostream>
using namespace std;

class Trial
{
  bool valid;
  float time;
public:
  Trial (bool v, float t): valid (v), time(t){}
  void print() const {if(valid) cout << "Y "; else cout << "N "; cout << time <<" ";}
  bool operator<(const Trial &t2)const {return time < t2.time;}
  bool getValid()const {return valid;}
  float getTime()const {return time;}
};

#endif

