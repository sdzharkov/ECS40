#ifndef AIRPORT_H
#define	AIRPORT_H

#include "city.h"
#include "list.h"

class Airport;

class Flight 
{
  char destination[4];
  char airline[20];
public:
  bool operator< (const Flight & flight) const;
  friend ostream& operator << (ostream &os, const Flight &rhs);
  friend class Airport;
};  // class Flight


class Airport : public City
{
  List <Flight> flights;
public:
  Airport();
  Airport(const char *airpor);
  void readAirlines(ifstream &inf);
  void findRoute(const List <Airport> &cities, List <Flight> &route, 
                 const char *airline, const char *destination, 
                 bool *found) const;
  ostream& write(ostream &os) const;
  bool operator != (const Airport &rhs) const;
  friend ostream& operator << (ostream &os, const Airport &rhs );
}; // class Airport 

#endif	// AIRPORT_H

