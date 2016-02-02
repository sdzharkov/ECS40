#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstring>
#include "itemList.h"

using namespace std;

class Persh;

class Item {
  char* name;
  float price;
  static int count;
public:
  Item (const char *n, float price);
  char* getName() {return name;}
  int getCount() {return count;}
  friend ostream& operator << (ostream& os, Item *rhs);
  //friend class itemList;
  ~Item () {delete []name;}
};

class Persh: public Item{
  char date[9];
public:
  Persh (const char *n, float pr, char *d) : Item(n,pr)
  {
    	strcpy(date, d);
  }
  
  };

#endif
