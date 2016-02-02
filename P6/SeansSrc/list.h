#ifndef CITYLIST_H
  #define	CITYLIST_H

#include <iostream>
#include "list.h"

using namespace std;

template <typename T>
class List;

template <typename T>
ostream& operator << (ostream &os, const List <T> &rhs );

template <typename T>
class ListNode
{
  T data;
  ListNode<T> *next;
  ListNode<T>(T c, ListNode<T> *node);
  friend class List <T>;
  friend ostream& operator << <T>(ostream &os, const List <T> &rhs );
};  // class ListNode<T>

template <typename T>
class List 
{
  ListNode<T> *head;
  int count;
public:
  List <T>();
//  List <T>(const List <T>& orig);
  ~List <T>();
  int getCount() const;
  T& find(const T &orig);
  List <T>&  operator += (const T &rhs);
  List <T>& operator -= (const T &rhs);
  const T& operator [] (int index) const;
  T& operator [] (int index);
  friend ostream& operator << <T>(ostream &os, const List <T> &rhs ); 

}; // class List <T> 

#include "list.cpp"
#endif	// CITYLIST_H 

