#include <iostream>
#include <vector>
#include "normal.h"
#include "trial.h"
using namespace std;

Normal::Normal(const string &n, const vector <bool> &v, const vector <float> &t): name(n)
{ 
  for(int i = 0; i < 5; i++)
  {
    Trial trial(v[i], t[i]);
    trials.insert(trial);
  }
}

void Normal::print() const
{
  float time = getTime();
  multiset<Trial>::const_iterator it;
  cout << name << " Time: " << time << " Runs:";

  for(it = trials.begin(); it != trials.end(); it++)
  {
    if(it->getValid() == true)
      cout << " Y " << it->getTime();
    else
      cout << " N 0";
  }
  cout << endl;
}

float Normal::getTime() const
{ 
  if(trials.begin()->getValid() == true)
  {
    float minT = trials.begin()->getTime();
    multiset<Trial>::const_iterator itr;
    for( itr = trials.begin(); itr != trials.end(); itr++)
    {
      if(itr->getTime() < minT)
        minT = itr->getTime();
    }
    return minT;
  }
  else
  {
    bool right = true;
    float maxT = 0;
    multiset<Trial>::const_iterator xtr;
    for(xtr = (trials.begin()++); xtr != trials.end(); xtr++)
    {
      if(maxT < xtr->getTime())
        maxT = xtr->getTime();

      if(xtr->getValid() == false)
        right = false;
    }
    
    if(right)
      return maxT;
    else
      return 10000;
  }
}

Multiple::Multiple(const string &n, const vector <bool> &v, const vector <float> &t): Normal(n, v, t) {}

float Multiple::getTime() const {return 0;}