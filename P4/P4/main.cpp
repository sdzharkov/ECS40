/* 
 * File:   main.cpp
 * Author: stepa
 *
 * Created on May 1, 2015, 4:35 PM
 */

#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
using namespace std;

void calcDistance(const Vector *cities)
{
  char airport1[80], airport2[80];
  int index1, index2;
  cout << "\nPlease enter two airport abbreviations (XXX XXX): ";
  cin >> airport1 >> airport2;
  index1 = cities->findAirport(airport1);
  index2 = cities->findAirport(airport2);

  if (index1 >= 0 && index2 >= 0)
    cities->calcDistance(index1, index2);
}  // calcDistance())


void determineAirportTraffic(const Vector *cities)
{
  char airport[80];
  int index;
  cout << "\nPlease enter an airport abbreviation (XXX): ";
  cin >> airport;
  index = cities->findAirport(airport);

  if (index >= 0 && index >= 0)
    cities->calcAirportTraffic(index);
}  // determinAirportTraffic()


int getChoice()
{
  int choice;

  do
  {
    cout << "\nFlight Simulator Menu\n";
    cout << "0. Done.\n";
    cout << "1. Determine distance and passengers between two airports.\n";
    cout << "2. Determine all traffic from one airport.\n\n";
    cout << "Your choice (0 - 2): ";
    cin >> choice;
    cin.ignore(1000, '\n');
   
    if  (choice < 0 || choice > 2)
      cout << "Your choice must be between 0 and 2. Please try again.\n";
  } while(choice < 0 || choice > 2);
   
  return choice;
}  // getChoice()  


void run(const Vector *cities)
{
  int choice;
  
//  for(index1 = 0; index1 < cities->count; index1++)
//    for(index2 = index1 + 1; index2  < cities->count; index2++)
//      calcDistance(cities, index1, index2);

  do
  {
    choice = getChoice();
    
    if (choice == 1)
      calcDistance(cities);
    else  // Done or determine traffic
      if (choice == 2)
        determineAirportTraffic(cities);
  } while(choice != 0);
}  // run())


int main(int argc, char** argv) 
{
  Vector cities;
  cities.readCities();
  cities.readAirports();
  cities.cleanCities();
//  srand(1);
//  for(int i = 0; i < cities.count; i++)
//    cout << "1\n" << cities.cityArray[i].airport << ' ' << cities.cityArray[rand() % cities.count].airport << endl;
//  printf("%s %s %lf %lf\n", cities.cityArray[i].name, cities.cityArray[i].airport, cities.cityArray[i].latitude, cities.cityArray[i].longitude);
  run(&cities);
  return 0;
} // main()+

