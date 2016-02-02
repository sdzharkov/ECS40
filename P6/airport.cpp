//airport.cpp
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "airport.h"

int Airport::findRoute(const List<Airport> &cities, List<Flight> &route, 
                       char *airline, char *dest) const
{
  Flight fly; 
  City city; 
  int index = 0, found = -1;
  fly.airline = new char[strlen(airline) + 1];
  strcpy(fly.airline, airline);
  
  if (strcmp(airport, dest) == 0)
  {
    fly.dest = new char[strlen(dest) + 1];
    strcpy(fly.dest, dest);
    route += fly;
    return 0;
  } //if
  else //else
  {
    fly.dest = new char[strlen(airport) + 1];
    strcpy(fly.dest, airport);
    
    for (int i = 0; i < flights.getCount(); i++)
    {
      if (strcmp(fly.airline, flights[i].airline) == 0)
      {
        city.setAirport(flights[i].dest);
    
        for (int j = 0; j < cities.getCount(); j++) 
        {
          if (cities[j] == city)
          {
            index = j;
            break;
          } //if
        } //for

        found = cities[index].findRoute(cities, route, airline, dest);

        if (found == 0)
        { 
          route += fly;
          return 0;
        } //if
      } //if
    } //for

    return -1;
  }//else 
} //findRoute()


void Airport::readAirline(char *line)
{
  char *ptr;
  Flight flight;
  int numFlights = atof(strtok(NULL, " "));

  for (int i = 0; i < numFlights; i++)
    {
    ptr = strtok(NULL, " "); 
    flight.airline = new char[strlen(ptr) + 1];
    strcpy(flight.airline, ptr);
    ptr = strtok(NULL, " ");
    flight.dest = new char[strlen(ptr) + 1];
    strcpy(flight.dest, ptr);
    flights += flight;
    } //
} //


bool Flight::operator < (const Flight &rhs) const
{
  return false;
} //

ostream& operator << (ostream &os, const Flight &rhs)
{
  os << rhs.airline[0] << rhs.airline[1] << "-" << rhs.dest << " ";
  
  return os;
} //

ostream& operator << (ostream &os, const Airport &rhs)
{
  os << rhs.airport << ": " << rhs.flights << endl;
  
  return os;
} //

void Airport::findRoute()
{

} //

