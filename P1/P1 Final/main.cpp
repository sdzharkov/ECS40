// Author: Sean Davis 
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "vector.h"
using namespace std;

void run(const Vector *cities)
{
  char airport1[80], airport2[80];
  int index1, index2;
  
//  for(index1 = 0; index1 < cities->count; index1++)
//    for(index2 = index1 + 1; index2  < cities->count; index2++)
//      calcDistance(cities, index1, index2);

  while (1)
  {
    cout<<"\nPlease enter two airport abbreviations (XXX XXX = done): ";
    cin >> airport1 >> airport2;
    
    if (strcmp(airport1, "XXX") == 0 && strcmp(airport2, "XXX") == 0)
      break;
    
    index1 = cities->findAirport(airport1);
    index2 = cities->findAirport(airport2);
    
    if (index1 >= 0 && index2 >= 0)
      cities->calcDistance(index1, index2);
  }  // infinite while loop
}  // run())


int main(int argc, char** argv) 
{
  Vector cities;
  cities.readCities();
  cities.readAirports();
  cities.cleanCities();
//  srand(1);
//  for(int i = 0; i < cities.count; i++)
//    printf("%s %s\n", cities.cityArray[i].airport, cities.cityArray[rand() % cities.count].airport);
//  printf("%s %s %lf %lf\n", cities.cityArray[i].name, cities.cityArray[i].airport, cities.cityArray[i].latitude, cities.cityArray[i].longitude);
  run(&cities);
  return 0;
} // main())
