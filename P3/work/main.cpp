// Author: Sean Davis 
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "vector.h"
using namespace std;

void run(const Vector *cities);
int main(int argc, char** argv);
void getChoice(const Vector *cities);

void run(const Vector *cities)
{
  getChoice(cities);
} //

int main(int argc, char** argv) 
{
  Vector cities;
  cities.readCities();
  cities.readAirports();
  cities.cleanCities();
//  srand(1);
  //for(int i = 0; i < cities.count; i++)
  //if (strcmp(cities.cityArray[i].name, "Springfield")==0)
  //	{
  //printf("%s %s %s %lf %lf\n", cities.cityArray[i].name, cities.cityArray[i].state, cities.cityArray[i].airport, cities.cityArray[i].latitude, cities.cityArray[i].longitude);
  //	}
  run(&cities);
  return 0;
} // main())

void getChoice(const Vector *cities)
{
  while (1)
  {
  int number, index1, index2;
  char airport1[80], airport2[80], airport3[80];
  cout << "\n" << "Flight Simulator Menu\n0. Done.\n";
  cout << "1. Determine distance and passengers between two airports.\n";
  cout << "2. Determine all traffic from one airport.\n" << "\n";
  cout << "Your choice (0 - 2): ";
  cin >> number;
  switch (number)
  {
  case 0:
    return;
  case 1:
    cout << "\nPlease enter two airport abbreviations (XXX XXX): ";
    cin >> airport1 >> airport2;
    index1 = cities->findAirport(airport1);
    index2 = cities->findAirport(airport2);
    
    if (index1 >= 0 && index2 >= 0)
      cities->calcDistance(index1, index2);
    break;
  case 2:
    cout << "\nPlease enter an airport abbreviation (XXX): ";
    cin >> airport3;
    int index;
    index = cities->findAirport(airport3);
    
    if (index >= 0)
      cities->calcAirportTraffic(index);
    break;
  default:
    cout << "Your choice must be between 0 and 2. Please try again.\n";
    break;
  } //
} //
} //
