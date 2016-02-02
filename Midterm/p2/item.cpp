#include <iostream>
#include <fstream>
#include <iomanip>
#include "item.h"

Item::Item (const char *n, float pr) : price(pr)
{
  name = new char[strlen(n) + 1];
	strcpy(name, n);
}


ostream& operator << (ostream& os, Item *rhs)
{
  for (int i = 0; i < rhs->getCount();i++)
    {
    //if (ptr)
      //os << setw(15) << rhs.ptr << setw(5) << rhs.price << setw(12) << rhs.name;
    //else
      os << setw(15) << rhs->price << setw(5) << rhs->getName();
    }
  return os;
}


