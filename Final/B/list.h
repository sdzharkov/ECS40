#ifndef LIST_H
  #define  LIST_H

#include <iostream>

template <typename T>
class ListNode
{
  T data;
  ListNode<T> *next;
public:
  ListNode(const T &c, ListNode *node) : data(c), next(node) {;};
};  // class CityNode

#endif  // 