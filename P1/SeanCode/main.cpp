// Author: Sean Davis 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

void run(const Vector *cities)
{
  char airport1[80], airport2[80];
  int index1, index2;
  
//  for(index1 = 0; index1 < cities->count; index1++)
//    for(index2 = index1 + 1; index2  < cities->count; index2++)
//      calcDistance(cities, index1, index2);

  while (1)
  {
    printf("\nPlease enter two airport abbreviations (XXX XXX = done): ");
    scanf("%s %s", airport1, airport2);
    
    if (strcmp(airport1, "XXX") == 0 && strcmp(airport2, "XXX") == 0)
      break;
    
    index1 = findAirport(cities, airport1);
    index2 = findAirport(cities, airport2);
    
    if (index1 >= 0 && index2 >= 0)
      calcDistance(cities, index1, index2);
  }  // infinite while loop
}  // run())


int main(int argc, char** argv) 
{
  Vector cities;
  initialize(&cities);
  readCities(&cities);
  readAirports(&cities);
  cleanCities(&cities);
//  srand(1);
//  for(int i = 0; i < cities.count; i++)
//    printf("%s %s\n", cities.cityArray[i].airport, cities.cityArray[rand() % cities.count].airport);
//  printf("%s %s %lf %lf\n", cities.cityArray[i].name, cities.cityArray[i].airport, cities.cityArray[i].latitude, cities.cityArray[i].longitude);
  run(&cities);
  deallocate(&cities);
  return 0;
} // main())

