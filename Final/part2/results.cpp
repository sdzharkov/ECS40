#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include "ListNode.h"
#include "results.h"
#include "normal.h"
#include "multiple.h"
using namespace std;

Results::~Results() {}

void Results::print(const string &directory) const
{
  for(ResultsMap::const_iterator itr = map.begin(); itr != map.end(); itr++)
  {
    if(directory.find(itr->first) != string::npos)
      itr->second->print();
  }
}

Results& Results::operator+= (Normal *n)
{
//  ListNode <Normal> ptr = new ListNode <Normal> (n, NULL);
  ListNode<Normal> *ptr, *prev = NULL;

  for (ptr = head; ptr && (ptr->data.trials < n.trials); ptr = ptr->next)
    prev = ptr;
  if (ptr)
    ptr->prev = prev->next;

  if (prev)
    prev->next = new ListNode<Normal>(n, prev, ptr);
  else
    head = new ListNode<Normal>(n, NULL, head);
    if (ptr)
      ptr->prev = head;
  

//  multiset<Trial>::const_itereator itr;
  string dir;
  size_t pos=0;
//  for(itr = n->name.begin(); itr != n->name.end(); itr++)
  pos = n->getName().find(" ");
  dir = n->getName().substr(pos+(size_t)2, min((n->getName().length()), (size_t)7));
  map.insert(ResultsMap::value_type(dir, n));

  return *this;
}

istream& operator>> (istream &is, Results &result)
{
  string name, dir, YN;
  float t;
  Normal *n;
  vector <bool> valid;
  vector <float> time;
  char line[1000], dline[1000];

  is.getline(dline,1000);

  while(is.getline(line,1000))
  {
  
    dir = strtok(line, ",");
    name = strtok(NULL, ",");
  
    for(int i = 0; i < 5; i++)
    {
      YN = strtok(NULL, ",");
      t = atof(strtok(NULL, ","));

      if(YN == "Yes")
        valid.push_back(true);
      else
        valid.push_back(false);

      time.push_back(t);
    }
 
    if(valid[0] == true)
      n = new Normal(name, valid, time);
    else
      n = new Multiple(name, valid, time);

    result += n;  
  }
  return is;
}
