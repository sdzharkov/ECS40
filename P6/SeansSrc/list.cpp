// Author: Sean Davis
#include <iostream>
#include <cstdlib>
#include "list.h"

using namespace std;


template <typename T>
ListNode<T>::ListNode(T c, ListNode<T> *node) : data(c), next(node)
{
  
}  // ListNode<T>())

template <typename T>
List <T>::List() : head(NULL), count(0)
{
} // List <T>()

template <typename T>
List <T>::~List() 
{
  for (ListNode<T> *ptr = head; ptr; ptr = head)
  {
    head = ptr->next;
    delete ptr;
  }  // for each node
} // ~List <T>()


template <typename T>
int List <T>::getCount() const
{
  return count;
}  // getCount()


template <typename T>
List <T>&  List <T>::operator += (const T &rhs)
{
  ListNode <T> *ptr, *prev = NULL;
  
  for (ptr = head; ptr  && ptr->data < rhs; ptr = ptr->next )
    prev = ptr;
  
  if (!prev)
    head = new ListNode<T> (rhs, ptr);
  else // prev, so after first node
    prev->next = new ListNode<T> (rhs, ptr);
    
  count++;
  return *this;
}  // operator+=


template <typename T>
List <T>& List <T>::operator -= (const T &rhs)
{
  ListNode<T> *ptr, *prev = NULL;
  
  for (ptr = head; ptr && ! (ptr->data == rhs); ptr = ptr->next)
    prev = ptr;
  
  if (ptr)
  {
    count--;
    
    if (!prev)  // found at front of list
      head = ptr->next;
    else // removing node after the first
      prev->next = ptr->next;
    
    delete ptr;
  }  // if found 

  return *this;
}  // operator -=


template <typename T>
const T& List <T>::operator [] (int index) const
{
  int pos = 0;
  ListNode<T> *ptr;
  
  for (ptr = head; ptr && pos != index; ptr = ptr->next, pos++);
   
  if (!ptr)
  {
     cout << "Error in array indexing!  Index: " << index << "\n";
     exit(1);
  }  // if index beyond end of list

  return ptr->data; 
}  // const operator[]
 
 
template <typename T>
T& List <T>::operator [] (int index)
{
  int pos = 0;
  ListNode<T> *ptr;
   
  for (ptr = head; ptr && pos != index; ptr = ptr->next, pos++);
   
  if (!ptr)
  {
    cout << "Error in array indexing!\n";
    exit(1);
  } // if index beyond end of the array.

  return ptr->data; 
}  // non-const operator[]



template <typename T>
ostream& operator << (ostream &os, const List <T> &rhs )
{
  for (ListNode <T> *ptr = rhs.head; ptr; ptr = ptr->next)
    os << ptr->data;
  
  return os;
}  // operator<<
