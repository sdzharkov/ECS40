#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include "TaxFormD.h"
using namespace std;

TaxFormD::TaxFormD(istream &is): TaxForm("", 0) 
{
  string reason;
  double amount;
  read(is);
  
  while(is >> reason >> amount)
    dedmap.insert(DedMap::value_type(reason, amount));
  
}

TaxFormD::~TaxFormD()
{}

void TaxFormD::check() const
{
  double total = 0;
  DedMap::const_iterator itr;
  for(itr = dedmap.begin(); itr != dedmap.end(); itr++)
  {
    total += itr->second;
    cout << setiosflags(ios::fixed | ios::showpoint) << left << setw(13)
         << itr->first << right << setw(7) << setprecision(2) << itr->second << endl;
  }
  cout << setw(13) << left << "Total:" << total << endl;

  if (deductions >= total)
    cout << "Deductions OK\n";
  else
    cout << "Deductions not OK\n";
}
