#include <iostream>
#include <cstdlib>
#include "list.h"
using namespace std;

//template <typename T>
//int List<T>::count = 0;

template <typename T>
ListNode<T>::ListNode(const T &c, ListNode<T> *node) : data(c), next(node)
{
  
}  // 
template <typename T>
List<T>::List() : head(NULL), count(0)
{
} // 
template <typename T>
List<T>::~List() 
{
  for (ListNode<T> *ptr = head; ptr; ptr = head)
  {
    head = ptr->next;
    delete ptr;
  }  // for each node
} // 

template <typename T>
int List<T>::getCount() const
{
  return count;
}  // getCount()

template <typename T>
List<T>& List<T>::operator += (const T &rhs)
{
  ListNode<T> *ptr, *prev = NULL;
  ListNode<T> *cityNode;
  cityNode = new ListNode<T>(rhs, NULL);
  
  if (head)
    {
    
    for (ptr = head; ptr &&  (ptr->data < rhs); ptr = ptr->next)
      prev = ptr;

    if (prev == NULL)
      {
      cityNode->next = head;
      head = cityNode;
      } //
    else //
      {
      prev->next = cityNode;
      cityNode->next = ptr;
      } //
    } //
  else //
    head = cityNode;
    
  count++;
  return *this;
}  // operator+=

template <typename T>
List<T>& List<T>::operator -= (const T &rhs)
{
  ListNode<T> *ptr, *prev = NULL;
  
  for (ptr = head; ptr && ! (ptr->data == rhs); ptr = ptr->next)
    prev = ptr;
  
  if (ptr)
  {
    count--;
    
    if (!prev)  // found at front of
    {
      head = ptr->next;
    }  // if removing first node
    else // removing node after the 
    {
      prev->next = ptr->next;
    }  // else removing after the first node
    
    delete ptr;
  }  // if found 

  return *this;
}  // operator -=

template <typename T>
const T& List<T>::operator [] (int index) const
{
  int pos = 0;
  ListNode<T> *ptr;
  
  for (ptr = head; ptr && pos != index; ptr = ptr->next, pos++);
   
  if (!ptr)
  {
     cout << "Error in array indexing!\n";
     exit(1);
  }  // if index beyond end of 

  return ptr->data; 
}  // const operator[]
 
template <typename T>
T& List<T>::operator [] (int index)
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
ostream& operator << (ostream &os, const List<T> &rhs)
{
  ListNode<T> *node = rhs.head;
  
  while (node != NULL)
  {
    os << node->data;
    node = node->next;
  } //
  
  return os;
} //

