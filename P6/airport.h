#ifndef AIRPORT_H
#define AIRPORT_H
#include "city.h"
#include "list.h"
#include <iostream>


class Flight;


class Airport: public City
{
  List<Flight> flights;
  int numFlights;
public:
  void readAirline(char *line);
  void findRoute();
  int findRoute(const List<Airport> &cities, List<Flight> &route, 
                char *airline, char *dest) const;
  friend ostream& operator << (ostream &os, const Airport &rhs);
}; // 


class Flight
{
  char* airline;
  char* dest;
  friend class Airport;
public:
  bool operator < (const Flight &rhs) const;
  friend ostream& operator << (ostream &os, const Flight &rhs);
}; //



#endif
