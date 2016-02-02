#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "city.h"
#include "vector.h"
#include <math.h> 

void initialize(City *cityPtr)
{
  cityPtr->latitude = 0.0;
  cityPtr->longitude = 0.0;
  cityPtr->valid = false;
  cityPtr->state = NULL;
  cityPtr->name = NULL;
  cityPtr->airport[0] = 0;
  cityPtr->population = 0;
} //

void readCityfile(City *cityPtr, char* strPtr)
{
  char* ptr = strtok(strPtr, ",");
  cityPtr->name = (char*)malloc((strlen(ptr) + 1)*sizeof(char));
  strcpy(cityPtr->name, ptr);
  char* nptr = strtok(NULL, ",");
  cityPtr->state = (char*)malloc((strlen(nptr) + 1)*sizeof(char));
  strcpy(cityPtr->state, nptr);
  cityPtr->population = atof(strtok(NULL, ","));
} //

void readAirport(City *cityPtr, char* strPtr)
{
  char* ptr = strtok(strPtr, "]");
  strcpy(cityPtr->airport, ptr + 1);
  cityPtr->latitude = atof(strtok(NULL, " "));
  cityPtr->longitude = atof(strtok(NULL, " "));
  ptr = strtok(NULL, ",");
  cityPtr->name = (char*)malloc((strlen(ptr) + 1)*sizeof(char));
  strcpy(cityPtr->name, ptr + 1);
} //

bool isEqual(const City *cityPtr, const City *citytemp)
{
  int const s = 0;
  
  if (cityPtr->airport[s] != '\0' && citytemp->airport[s] != '\0')
  {
    if (strcmp(cityPtr->airport, citytemp->airport) == 0)
    {
      return true;
    } //
    else //
    {
      return false;
    } //
  } //
  
  if (cityPtr->name != NULL && citytemp->name != NULL)
  {
    if (strcmp(cityPtr->name, citytemp->name) == 0)
    {
      return true;
    } //
    else //
    {
      return false;
    } //
  } //
  
  return false;
} //


void copyLocation(City *cityArray, const City *citytemp)
{
  strcpy(cityArray->airport, citytemp->airport);
  cityArray->latitude = citytemp->latitude;
  cityArray->longitude = citytemp->longitude;
} //

void deallocate(City *city)
{
  free(city->name);
  free(city->state);
} //

bool hasAirport(City *cityArray)
{
  if (cityArray->airport[0] == 0)
  {
  return false;
  } // this is the part when
  else //
  {
    return true;
  } //
} //

void setAirport(City *newtemp, const char *city1)
{
  strcpy(newtemp->airport, city1);
} //

void calcDistance(const City *city, const City *city2)
{
  const int R = 3963;
  const int pop = 250000000;
  int distance;
  double lat1 = deg2rads(city->latitude);
  double lat2 = deg2rads(city2->latitude);
  double lon1 = deg2rads(city->longitude);
  double lon2 = deg2rads(city2->longitude);
  double pop1 = city->population;
  double pop2 = city2->population;
  int travelPop = ((pop1 * pop2) / pop);
  distance = acos(sin(lat1) * sin(lat2) + cos(lat1) 
  * cos(lat2) * cos(lon1 - lon2)) * R;
  
  if (distance < 100)
  {
    travelPop = 0;
  } //
  
  printf("%d passengers fly the %d miles from\n%s,%s to %s,%s\n", 
  travelPop, distance, city->name, city->state, city2->name, city2->state);
} //

double deg2rads(double num)
{
  return (num * ((M_PI) / 180));
} //