#ifndef LIST_H
  #define  LIST_H

#include "city.h"
//#include "airport.h"
#include <iostream>
template <typename T>
class List;

template <typename T>
  ostream& operator << (ostream &os, const List<T> &rhs);

template <typename T>
class ListNode
{
  T data;
  ListNode<T> *next;
public:
  ListNode(const T &data, ListNode *node);
  friend class List<T>;
  friend ostream& operator << <T>(ostream &os, const List<T> &rhs);
  
};  // class CityNode

template <typename T>
class List
{
  ListNode<T> *head;
  int count;
public:
  List<T>();
  ~List<T>();
  int getCount() const;
  List<T>& operator += (const T &rhs);
  List<T>& operator -= (const T &rhs);
  const T& operator [] (int index) const;
  T& operator [] (int index);  
  friend ostream& operator << <T>(ostream &os, const List<T> &rhs);


}; // class 

#include "list.cpp"
#endif  // 

