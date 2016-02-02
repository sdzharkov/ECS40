// Author: Sean Davis
#include <iostream>
#include <fstream>
using namespace std;
#include <cstring>
#include <cstdlib>
#include <cmath>
#include "city.h"

//City::void initialize()
City::City()
{
  name = NULL;
  state = NULL;
  airport[0] = '\0';  // sentinel value
}  // initialize()



void City::deallocate()
{
  if (name)
    delete [] name;
    name = NULL;
  
  if (state)
    delete [] state;
    state = NULL;
}  // deallocate()

City::~City()
{
  if (name)
    delete [] name;
  
  if (state)
    delete [] state;
}  // deallocate()

City & City::operator=(const City& rhs) 
{
  if (this == &rhs)
    return *this;
  
  if (name)
    delete [] name;
  
  if (state)
    delete [] state;
 
 if (rhs.name)
    {
    name = new char [strlen(rhs.name) + 1];
    strcpy(name, rhs.name);
    } //
  else //
    name = NULL;
  
  if (rhs.state)
    {
    state = new char [strlen(rhs.name) + 1];
    strcpy(state, rhs.state);
    } //
  else //
    state = NULL;
  
  strcpy(airport, rhs.airport);
  latitude = rhs.latitude;
  longitude = rhs.longitude;
  population = rhs.population;
  //strncpy(airport, rhs.airport, 4); 

  return *this;
} //

void City::calcDistance(const City *city2) const
{
  int distance, passengers;
  
  passengers = (double) population * city2->population / 2500000000U;
  distance = acos(
    sin(latitude * M_PI / 180) * sin(city2->latitude * M_PI / 180) 
    + cos(latitude * M_PI / 180) * cos(city2->latitude * M_PI / 180)
    * cos((longitude - city2->longitude) * M_PI / 180)) * 3963;
  
  if (distance < 100)
    passengers = 0;

  cout << passengers << " passengers fly the " << distance << " miles from\n" <<
  name << ", " << state << " to " << 
  city2->name << ", " << city2->state << ".\n";

}  // calcDistance())

void City::copyLocation(const City *srcCity) 
{
  strcpy(airport, srcCity->airport);
  latitude = srcCity->latitude;
  longitude = srcCity->longitude;
}  // copyLocation()


bool City::hasAirport()
{
  return airport[0] != '\0';
}  // hasAirport()


bool City::isEqual(const City *city2) const
{
  if ((name && city2->name) && (state && city2->state))
    return strcmp(name, city2->name) == 0 && strcmp(state, city2->state) == 0;
  
  if (airport[0] && city2->airport[0])
    return strcmp(airport, city2->airport) == 0;
  
  return false;
}  // isName()


void City::readCity(ifstream &fp)
{
  char line[1000], *ptr;
  
  if (!fp.getline(line, 1000) || !strstr(line, ","))
    return;
  
  ptr = strtok(line, ",");
  
  if (ptr)
  {  
    name = new char[strlen(ptr) + 1];
    strcpy(name, ptr);
    ptr = strtok(NULL, ",");
    state = new char[strlen(ptr) + 1];
    strcpy(state, ptr);
    population = atoi(strtok(NULL, ",\n"));
  } // if something on line
}  // readCity()

void City::readAirport(char *line, char *stat)
{
  char *ptr;
  strtok(line, "] ");
  strcpy(airport, &line[1]);
  latitude = atof(strtok(NULL, " "));
  longitude = atof(strtok(NULL, " "));
  ptr = strtok(NULL, ",") + 1;
  name = new char[strlen(ptr) + 1];
  strcpy(name, ptr);
  
  state = new char[strlen(stat) + 1];
  strcpy(state, stat);
}  // readAirport


void City::setAirport(const char *airpor)
{
  strcpy(airport, airpor);
}  // setAirport()

int City::showTraffic(const City *city2) const
//int City::showTraffic(const City *city2) const
{
int distance, passengers;
 
  passengers = (double) population * city2->population / 2500000000U; // need to add this u
  distance = acos(
    sin(latitude * M_PI / 180) * sin(city2->latitude * M_PI / 180) 
    + cos(latitude * M_PI / 180) * cos(city2->latitude * M_PI / 180)
    * cos((longitude - city2->longitude) * M_PI / 180)) * 3963;
    
  if (distance <= 100)
   passengers = 0;
   
   cout << city2->name << ", " << 
   city2->state << ": " << passengers << "\n";
   
  return passengers;
} //


