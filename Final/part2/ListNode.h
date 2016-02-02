#ifndef LISTNODE_H
   #define LISTNODE_H
using namespace std;

template <typename T>
class ListNode
{
  T *data;
  ListNode <T> *next;
  ListNode <T> *prev;
public:
  ListNode<T> (T *d, ListNode *n, ListNode *p ):data(d), next(n), prev(p) {}
  void setNext(ListNode<T> *n){}
  void setPrev(ListNode<T> *p){}
  ListNode<T>* getPrev() {return prev;}
};

#endif
