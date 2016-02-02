#ifindef CITYLIST_H
#define CITYLIST_H
#include "city.h"

class CityList
{
  CityNode* head;
  CityNode* tail;
  static int count;
};

class CityNode
{
  City city;
  CityNode* next;
  friend class CityList;
}; 

#endif
