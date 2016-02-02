#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "TaxPayers.h"
using namespace std;

TaxPayers::TaxPayers(): head(NULL) {}

void TaxPayers::read(const char *filename)
{ 
  ifstream inf(filename);
  string line;

 // while(inf)
  while (getline(inf, line))
  {
    stringstream l;
    l << line; 
    TaxFormD tfd(l);
    if(head)
    {
      head->prev = new ListNode(tfd, NULL, head);
      head = head->prev;
    }
    else
      head = new ListNode(tfd, NULL, NULL);
  }


  inf.close();
}//read

void TaxPayers::checkDeductions(const string &SSN) const
{
  ListNode *ptr;
  for(ptr = head; ptr && ptr->taxFormD.getSSN() != SSN; ptr = ptr->next);

  if(ptr)
    ptr->taxFormD.check();
  else
    cout << SSN << " not found\n";
}
