#ifndef TaxFormD_h
   #define TaxFormD_h
#include <map>
#include "TaxForm.h"
using namespace std;
typedef map<string, double> DedMap;

class TaxFormD: public TaxForm
{
  DedMap dedmap;
public:
  TaxFormD(istream &is);
  ~TaxFormD();
  void check() const;
}; //TaxFormD

#endif
