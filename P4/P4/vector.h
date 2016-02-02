/* 
 * File:   vector.h
 * Author: stepa
 *
 * Created on May 1, 2015, 4:31 PM
 */

#ifndef VECTOR_H
#define	VECTOR_H

#include "city.h"

class Vector
{
  City *cityArray;
  int size;
  int count;
  void resize();
public:
  Vector();
  ~Vector();
  void calcAirportTraffic(int index) const;
  void calcDistance(int index1, int index2) const;
  void cleanCities();
  int findAirport(const char *airport) const;
  void readAirports();
  void readCities();
};  // class Vector
#endif	/* VECTOR_H */

