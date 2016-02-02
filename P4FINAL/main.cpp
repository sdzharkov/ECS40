// Author: Sean Davis 

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <climits>
#include "vector.h"
#include "plane.h"
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
    cities->calcDistance(index1, index2, 1);
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
    cout << "2. Determine all traffic from one airport.\n";
    cout << "3. Display planes information.\n";
    cout << "4. Add plane information.\n";
    cout << "5. Determine best plane between two airports.\n\n";
    cout << "Your choice (0 - 5): ";
    cin >> choice;
    cin.ignore(1000, '\n');
   
    if  (choice < 0 || choice > 5)
      cout << "Your choice must be between 0 and 5. Please try again.\n";
  } while(choice < 0 || choice > 5);
   
  return choice;
}  // getChoice()  

void readPlanes(Plane planes[10], int *numberOfPlanes)
{
  ifstream inf("planes.dat", ios::binary);

  while(inf.read((char*) &planes[*numberOfPlanes], sizeof(Plane)))
   {
   (*numberOfPlanes)++;
   } //

  inf.close();
} //

void displayPlaneInformation(Plane planes[10], int *numberOfPlanes)
{
  int i;
  cout << endl << "Plane Information" << endl;
  cout << "Name        " << "Pass. " << "Range " << "Speed " << 
       "Fuel   " << "MPG   " << "$/mi  " << "Price * 10^6" << endl;

  for (i = 0; i < (*numberOfPlanes); i++)
    {
    cout << planes[i];
    } //
} //

void addPlaneInformation(Plane *planes, int *numberOfPlanes)
{
  planes[*numberOfPlanes].newPlane();
  ofstream outf("planes.dat", ios::app | ios::binary);
  outf.write((char*) &planes[(*numberOfPlanes)++], sizeof(Plane));
  outf.close();
} //

void determineBestPlane(const Vector *cities, const Plane planes[],
                        int *numberOfPlanes)
{
  int passengers, distance, index1, index2, num = -1, trip, numTrip,
      cheapest = INT_MAX , totalCosts = 0;
  char airport1[80], airport2[80];
  cout << endl << "Please enter two airport abbreviations (XXX XXX): ";
  cin >> airport1 >> airport2;
  index1 = cities->findAirport(airport1);
  index2 = cities->findAirport(airport2);
  planes[0].getName();

  if (index1 >= 0 && index2 >= 0)
  {
    passengers = cities->calcDistance(index1, index2, 2);
    distance = cities->calcDistance(index1, index2, 3);

    for (int i = 0; i < (*numberOfPlanes); i++)
    {
    totalCosts = planes[i].calcCost(distance, passengers, trip);

    if (trip > 0 && totalCosts <= cheapest)
      {
      numTrip = trip;
      cheapest = totalCosts;
      num = i;
      } //
    } //
 
  if (num == -1)
    cout << "No planes available" << endl;
  else //
    planes[num].displayInfo(passengers, distance, numTrip, cheapest);
  } //
} //

void run(const Vector *cities, Plane planes[], int *numberOfPlanes)
{
  int choice;

  do
  {
    choice = getChoice();
    
    if (choice == 1)
      calcDistance(cities);

    if (choice == 2)
      determineAirportTraffic(cities);

    if (choice == 3)
      displayPlaneInformation(planes, numberOfPlanes);

    if (choice == 4)
      addPlaneInformation(planes, numberOfPlanes);

    if (choice == 5)
      determineBestPlane(cities, planes, numberOfPlanes);

  } while(choice != 0);
}  // run())

int main(int argc, char** argv) 
{
  Plane planes[10];
  int numberOfPlanes = 0;
  Vector cities;
  cities.readCities();
  cities.readAirports();
  cities.cleanCities();
  readPlanes(planes, &numberOfPlanes);
  run(&cities, planes, &numberOfPlanes);
  return 0;
} // main())

