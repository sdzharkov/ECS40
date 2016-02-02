#ifndef PLANES_H
#define PLANES_H

#include <fstream>
using namespace std;

class Plane
{
char name[12];
int passengers;
int range;
int speed;
int fuel;
int price;
static const int attendantHourly = 30;
static const int pilotHourly = 100;
public:
  void print();
  void newPlane();
  const char* getName() const;
  void displayPlaneInformation();
  int calcCost(int distance, int totPassengers, int &trip) const;
  void displayInfo(int passengers, int distance, int trips, int totCost) const;
  friend ostream& operator << (ostream &os, const Plane &rhs);
  static const double fuelPrice = 3.39; 
}; //


#endif
