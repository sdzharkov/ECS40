
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include "plane.h"
using namespace std;

void Plane::print()
{
  cout << "name " << name << endl;
    cout << "passengers " << passengers << endl;
  cout << "range " << range << endl;
  cout << "speed " << speed << endl;
  cout << "fuel " << fuel << endl;
  cout << "price " << price << endl << endl;
} //


void Plane::newPlane()
{
  cout << "Name: ";
  cin >> name;
  cout << "Passengers: ";
  cin >> passengers;
  cout << "Fuel capacity (in U.S. gallons): ";
  cin >> fuel;
  cout << "Range (in miles): ";
  cin >> range;
  cout << "Speed (in mph): ";
  cin >> speed;
  cout << "Price: ";
  cin >> price;
} //

const char* Plane::getName() const
{
  return name;
} //

int Plane::calcCost(int distance, int totPassengers, int &trip) const
{
  double workHours, hours;
  double fuelCost, attendantSalary, pilotSalary, maintCost;
  
  if (distance <= range)
    {
    trip = ceil((double)totPassengers / passengers);
    fuelCost = (fuelPrice * fuel * distance) / range;
    hours = distance / (double)speed; 
    workHours = ceil((double)hours + 2);
    attendantSalary = ceil((double)hours + 2) * ceil((double) passengers / 100) 
    * attendantHourly;
    pilotSalary =  2 * pilotHourly * workHours;
    maintCost = (.000025 * price * hours); 
    return ceil(trip * (fuelCost + attendantSalary + pilotSalary + maintCost));
    } //
  else //
    {
    trip = 0;
    return INT_MAX;
    } //
} //
  
void Plane::displayInfo(int passengers, int distance, int trips, 
                        int cheapest) const
{
  cout << "Passengers Miles  Trips Name      Cost\n";  
  cout << left << setw(11) << passengers << setw(7) << distance << setw(6)
       << trips << setw(10) << name << "$" << cheapest << endl;
} //

ostream& operator << (ostream &os, const Plane &rhs)
{
  int leftRange = rhs.range / 1000;
  int rightRange = rhs.range % 1000;
  int leftFuel = rhs.fuel / 1000;
  int rightFuel = rhs.fuel % 1000;
  
  os << left << setw(12) << rhs.name;
  os << setw(6) << rhs.passengers;
  os << leftRange << "," << setfill('0') << setw(3) << right 
     << rightRange << setfill(' ');
  os << setw(4) << right << rhs.speed;
  os << setw(5) << leftFuel << ',' << setfill('0') << setw(3) 
     << right << rightFuel << setfill(' ');
 
  os << setw(6) << fixed << setprecision(3) << rhs.range / (double) rhs.fuel
     << setw(6) << setprecision(2)
     << (Plane::fuelPrice * rhs.fuel) / rhs.range << setw(2) << "$"
     << setw(5) << setprecision(1) << rhs.price / 1000000.0 << endl;
  return os;
} //


