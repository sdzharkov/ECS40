// Author: Sean Davis

#include <cstring>
#include "city.h"
#include "airport.h"
using namespace std;


bool Flight::operator< (const Flight & flight) const
{
  return false;
}  // operator <

ostream& operator << (ostream &os, const Flight &rhs )
{
  os << rhs.airline[0] << rhs.airline[1] << '-' << rhs.destination << ' ';
  return os;
}  // operator <<


Airport::Airport() 
{
} // Airport()



Airport::Airport(const char *airpor)
{
  strcpy(airport, airpor);
}  // Airport(char*)

void Airport::findRoute(const List <Airport> &cities, List <Flight> &route, 
                        const char *airline, const char *destination, 
                        bool *found) const
{
  int index; 
  Flight flight;

  if (strcmp(airport, destination) == 0)
  {
    strcpy(flight.airline, airline);
    strcpy(flight.destination, destination);
    route += flight;
    *found = true;
  }  // if reach destination
  else // haven't reached destination yet
  {
    for (int i = 0; i < flights.getCount(); i++)
    {
      if (strcmp(flights[i].airline, airline) == 0)
      {
        Airport city;
        city.setAirport(flights[i].destination);
  
        for (index = 0; index < cities.getCount(); index++)
          if (cities[index] == city)
            break;
      
        cities[index].findRoute(cities, route, airline, destination, found);
        
        if (*found)
        {
          strcpy(flight.destination, airport);
          strcpy(flight.airline, airline);
          route += flight;
        }  // if found destination
      } // if found match of airline
    }  // for each flight from the airport
  } // else haven't reached destination yet
}  // findRoute())


void Airport::readAirlines(ifstream &inf)
{
  Flight flight;
  int count;
  inf >> count;
  
  for (int i = 0; i < count; i++)
  {
    inf >> flight.airline >> flight.destination;
    flights += flight;
  }  // for each flight
}  // readAirlines())

bool Airport::operator != (const Airport &rhs) const
{
  return strcmp(airport, rhs.airport) != 0;
} // operator !=


ostream& operator << (ostream &os, const Airport &rhs )
{
  os << rhs.airport << ": " << rhs.flights << endl;
  return os;
}  // operator <<
