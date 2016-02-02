// Author: Sean Davis

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

void initialize(Vector *cities)
{
  cities->size = 10;
  cities->count = 0;
  cities->cityArray = (City*) malloc(cities->size * sizeof(City));
  
  for (int i = 0; i < cities->size; i++)
    initialize(&cities->cityArray[i]);
}  // initialize()


void deallocate(Vector *cities)
{
  for (int i = 0; i < cities->count; i++)
    deallocate(&cities->cityArray[i]);
  
  free(cities->cityArray);
}  // deallocate())


void calcDistance(const Vector *cities, int index1, int index2)
{
  calcDistance(&cities->cityArray[index1], &cities->cityArray[index2]);
}  // calcDistance()

void cleanCities(Vector *cities)
{
  int i = 0;
  
  while (i < cities->count)
  {
    if (!hasAirport(&cities->cityArray[i]))
    {
      deallocate(&cities->cityArray[i]);
      cities->cityArray[i] = cities->cityArray[--cities->count];
    }  // if city does not have an airport
    else // city has an airport
      i++;
  }  // while more in array
}  // cleanCities())


int findAirport(const Vector *cities, const char *airport)
{
  City city;
  
  initialize(&city);
  setAirport(&city, airport);
  
  for (int i = 0; i < cities->count; i++)
    if (isEqual(&cities->cityArray[i], &city))
      return i;
  
  printf("%s is not a valid airport.\n", airport);
  return -1;
}  // findAirport()


void readAirports(Vector *cities)
{
  char line[1000];
  City city;
  initialize(&city);
  FILE *fp = fopen("airportLL.txt", "r");

  while (fgets(line, 1000, fp))
  {
    if (line[0] == '[')
    {
      readAirport(&city, line);
      
      for (int i = 0; i < cities->count; i++)
        if (isEqual(&cities->cityArray[i], &city))
        {
          copyLocation(&cities->cityArray[i], &city);
          break;
        }  // if found a matching name
      
      deallocate(&city);
    }  // if an airport line
  }  // while
}  // readAirports()


void readCities(Vector *cities)
{
  FILE *fp = fopen("citypopulations.csv", "r");
  
  while(!feof(fp))
  {
    if (cities->size == cities->count)
      resize(cities);
  
    readCity(&cities->cityArray[cities->count++], fp);
  } // while more in file
  
  cities->count--;
  fclose(fp);
}  // readCities()


void resize(Vector *cities)
{
  int i;
  City *temp = (City*) malloc(sizeof(City) * 2 * cities->size);
  
  for (i = 0; i < cities->size; i++)
    temp[i] = cities->cityArray[i];
  
  cities->size *= 2;
  
  for (; i < cities->size; i++)
    initialize(&temp[i]);
    
  free(cities->cityArray);
  cities->cityArray = temp;
}  // resize()


