#include <iostream>
#include <string>
#include "TaxPayers.h"
using namespace std;

int main(int argc, char *argv[])
{
  string SSN;
  TaxPayers payers;
  payers.read(argv[1]);
  cout << "SSN to check (0 to end) : ";
  cin >> SSN;

  while(SSN != "0")
  {
    payers.checkDeductions(SSN);
    cout << "SSN to check (0 to end) : ";
    cin >> SSN;
  } //while

  return 0;
}//main

 
