#ifndef TaxForm_h
   #define TaxForm_h
#include <string>
#include <fstream>
using namespace std;

class TaxForm
{
  string SSN;
protected:
  double deductions;
  istream& read(istream &is);
public:
  TaxForm(const string &S, double ded);
  virtual ~TaxForm();
  virtual void check() const = 0;
  const string& getSSN() const;
}; //TaxForm





#endif
