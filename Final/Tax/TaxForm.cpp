#include <fstream>
#include <iostream>
#include <string>
#include "TaxForm.h"
using namespace std;


TaxForm::TaxForm(const string &S, double ded): SSN(S), deductions(ded) {}

TaxForm::~TaxForm()
{}

istream& TaxForm::read(istream &is)
{
  is >> SSN >> deductions;
  return is;
}
const string& TaxForm::getSSN()const {return SSN; }

