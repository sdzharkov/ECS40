#ifndef RESULTS_H
   #define RESULTS_H
#include <map>
#include "ListNode.h"
#include "normal.h"
using namespace std;
typedef map <string, Normal*> ResultsMap;

class Results
{
  ListNode <Normal> *head;
  ResultsMap map;
public:
  Results(): head(NULL){}
  ~Results();
  void print(const string &directory) const;
  Results& operator+= (Normal *n);
  friend istream& operator>> (istream &is, Results &result);
};

#endif
