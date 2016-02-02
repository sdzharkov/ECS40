#ifndef TaxPayers_h
   #define TaxPayers_h
#include <string>
#include "TaxFormD.h"
using namespace std;

class TaxPayers;

class ListNode {
  TaxFormD taxFormD;
  ListNode *prev;
  ListNode *next;
  ListNode(const TaxFormD &tf, ListNode *p, ListNode *n): taxFormD(tf), prev(p), next(n) {}
  friend class TaxPayers;
}; //ListNode

class TaxPayers
{
  ListNode *head;
public:
  TaxPayers();
  void read(const char *filename);
  void checkDeductions(const string &SSN) const;
}; //TaxPayers

#endif
