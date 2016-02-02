#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "itemList.h"
#include <cstdlib>
#include <stdio.h>
using namespace std;

void itemList::read(char *file)
{
	char *ptr;
	char name[15];
		float price;
  char line[1000];
  ifstream inf(file);
  while (inf.getline(line, 1000))
    {
    strcpy(name,strtok(line, ","));
  	price = atof(strtok(NULL, ","));
  	ptr = strtok(NULL, ",");
  	//if (ptr)
  	  Item *item = new Persh(name, price, ptr);
    //else
    //  Item *item = new Item(name, price);
      
    *this += item;
    }
  inf.close();
}

itemList& itemList::operator += (Item *data) 
{
ListNode *ptr, *prev = NULL;

  for (ptr = head; ptr && strcmp(data->getName(), ptr->getData()->getName())<0; ptr = ptr->getNext())
  	{
  	prev = ptr;
  	}
  	if (ptr)
  	  ptr->prev = prev->next;
  	
  	if (prev)
  		prev->next = new ListNode(data, prev, ptr);
    else
      {
      head = new ListNode(data,NULL,ptr);
      if (ptr)
        ptr->prev = head;
      }

 return *this;
}

