// Author: Sean Davis
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "city.h"

void initialize(City *city)
{
  city->name = NULL;
  city->state = NULL;
  city->airport[0] = '\0';  // sentinel value
}  // initialize()


void deallocate(City *city)
{
  if (city->name)
    free(city->name);

  if (city->state)
    free(city->state);
}  // deallocate()


void calcDistance(const City *city1, const City *city2)
{
  int distance, passengers;
  
  passengers = (double) city1->population * city2->population / 250000000;
  distance = acos(
    sin(city1->latitude * M_PI / 180) * sin(city2->latitude * M_PI / 180) 
    + cos(city1->latitude * M_PI / 180) * cos(city2->latitude * M_PI / 180)
    * cos((city1->longitude - city2->longitude) * M_PI / 180)) * 3963;
  
  if (distance < 100)
    passengers = 0;

  printf("%d passengers fly the %d miles from\n%s,%s to %s,%s\n", passengers,
    distance, city1->name, city1->state, city2->name, city2->state);
  
}  // calcDistance())

void copyLocation(City *destCity, const City *srcCity)
{
  strcpy(destCity->airport, srcCity->airport);
  destCity->latitude = srcCity->latitude;
  destCity->longitude = srcCity->longitude;
}  // copyLocation()


bool hasAirport(City *city)
{
  return city->airport[0] != '\0';
}  // hasAirport()


bool isEqual(const City *city, const City *city2)
{
  if (city->name && city2->name)
    return strcmp(city->name, city2->name) == 0;
  
  if (city->airport[0] && city2->airport[0])
    return strcmp(city->airport, city2->airport) == 0;
  
  return false;
}  // isName()


void readCity(City *city, FILE *fp)
{
  char line[1000], *ptr;
  
  if (!fgets(line, 1000, fp) || !strstr(line, ","))
    return;
  
  ptr = strtok(line, ",");
  
  if (ptr)
  {  
    city->name = (char*) malloc(strlen(ptr) + 1);
    strcpy(city->name, ptr);
    ptr = strtok(NULL, ",");
    city->state = (char*) malloc(strlen(ptr) + 1);
    strcpy(city->state, ptr);
    city->population = atoi(strtok(NULL, ",\n"));
  } // if something on line
}  // readCity()

void readAirport(City *city, char *line)
{
  char *ptr;
  
  strtok(line, "] ");
  strcpy(city->airport, &line[1]);
  city->latitude = atof(strtok(NULL, " "));
  city->longitude = atof(strtok(NULL, " "));
  ptr = strtok(NULL, ",") + 1;
  city->name = (char*) malloc(strlen(ptr) + 1);
  strcpy(city->name, ptr);
}  // readAirport


void setAirport(City *city, const char *airport)
{
  strcpy(city->airport, airport);
}  // setAirport()
