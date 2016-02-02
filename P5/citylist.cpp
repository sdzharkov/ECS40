#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "citylist.h"

int CityList::count = 0;

CityList::CityList()
{
  head = NULL;
  tail = NULL;
} //

CityNode::CityNode(const City& rhs, CityNode *ptr) :city(rhs), next(ptr)
{
  
} //

CityList::~CityList()
{
  CityNode *temp;  
  
  while (head != NULL)
    {
    temp = head;
    head = head->next;
    delete temp;
    } //
} //

int CityList::getCount()
{
  return count;
} //

CityList& CityList::operator += (const City& rhs) 
{

  CityNode* ptr;
  ptr = new CityNode(rhs, NULL);
  
  if (head)
    {
    tail->next = ptr;
    tail = ptr;
    } //
  else //
    head = tail = ptr;

  count ++;
  return *this;
} //

CityList& CityList::operator -= (const City& rhs)
{
  CityNode *ptr;
  CityNode *prev = NULL;
  
  for (ptr = head; ptr && !(ptr->city == rhs); ptr = ptr->next)
    {
    prev = ptr;
    } //
    
  if (prev == NULL)
    {
    head = ptr->next;
    delete ptr;
    } //
    
  if (ptr)
    {
    prev->next = ptr->next;
    delete ptr;
    count --;
    } //
    
  return *this;
} //

const City& CityList::operator[] (int index) const
{
  CityNode* ptr;
  ptr = head;
  
  for (int i = 0; i < index; i++)
    ptr = ptr->next;
    
  return ptr->city;

} //

City& CityList::operator[] (int index)
{
  CityNode* ptr;
  ptr = head;
  
  for (int i = 0; i < index; i++)
    ptr = ptr->next;
    
  return ptr->city;
} //


