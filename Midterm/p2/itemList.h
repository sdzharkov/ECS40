#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>
#include "item.h"

using namespace std;

class itemList;

class ListNode {
	Item *data;
	ListNode *prev; // this maybe be on the midterm
	ListNode *next;
public:
	ListNode(Item *d, ListNode *p, ListNode *n) : data(d), prev(p), next(n) {}
	Item* getData() {return data;}
	ListNode* getNext() {return next;}
	bool operator < (const Item &rhs) const;
	friend class itemList;
}; // class ListNode

class itemList {
  ListNode *head;
  ListNode *tail;
  static int count;
public:
  itemList() : head(NULL), tail(NULL) {}
  void read(char *line);
  static int getCount() {return count;}
  ~itemList() {
    ListNode *ptr; 
    for (ptr = head; ptr; ptr= head)
    	{
    	head = ptr->next;
    	delete ptr;
      }
    }
  itemList &operator += (Item *data);
  //Item &operator < (const Item &rhs) const;
};

#endif 
