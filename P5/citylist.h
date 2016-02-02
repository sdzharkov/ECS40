#ifndef CITYLIST_H
#define CITYLIST_H
#include "city.h"

class CityList;
class CityNode;

class CityList
{
  CityNode* head;
  CityNode* tail;
  static int count;
  public:
  CityList();
  ~CityList();
  static int getCount();
  CityList& operator += (const City& rhs);
  CityList& operator -= (const City& rhs);
  const City& operator[] (int index) const;
  City& operator[] (int index);
}; //

class CityNode
{
  City city;
  CityNode* next;
  friend class CityList;
public:
  CityNode(const City& rhs, CityNode *tail);

}; //

#endif
