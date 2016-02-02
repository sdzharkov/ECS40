#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "city.h"
#include "vector.h"

void run (Vector *baseVector)
{
  char city1[80], city2[80];
  
  while (true)
  {
    printf("\nPlease enter two airport abbreviations (XXX XXX = done): ");
    scanf("%s %s", city1, city2);
    
    if (strcmp(city1, "XXX") != 0 || strcmp(city2, "XXX") != 0)
    {
      int first = findAirport(city1, baseVector);
      int second = findAirport(city2, baseVector);
      
      if (first == -1 || second == -1)
      {
        continue;
      } //
      
      calcDistance(baseVector, first, second);
      continue;
    } //
    else //
    {
    exit (0);
    } //
  } //
} //

int main(int argc, const char* argv[])
{
Vector baseVector;
  initialize(&baseVector);
  readCity(&baseVector);
  readAirports(&baseVector);
  cleanCities(&baseVector);
  run(&baseVector);
  deallocate(&baseVector);
} //


