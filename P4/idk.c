class Plane 
{
  char name[12];
  int passengers;
  int range; // in miles
  int speed; // in mile per hour
  int fuel;  // in U.S. gallons
  int price;  // in U.S. dollars
  static const int attendantHourly = 30;
  static const int pilotHourly = 100;
public:
  Plane();
  int calcCost(int distance, int numPassengers, int *trips) const;
  const char* getName() const;
  void getPlane();
  friend ostream& operator << (ostream &os, const Plane &plane);
  static const double fuelPrice = 3.39;
};  // class Plane



#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include "vector.h"
using namespace std;

Vector::Vector()
{
  size = 10;
  count = 0;
  cityArray = new City[size];
}  // initialize()


void Vector::calcAirportTraffic(int index) const
{
  int total = 0;
  
  for (int i = 0; i < count; i++)
    if (i != index)
      total += cityArray[index].showTraffic(cityArray[i]);
  
  cout << "Total passengers: " << total << endl;
}  // calcAirportTraffic()

Vector::~Vector()
{
  delete [] cityArray;
}  // deallocate())


void Vector::calcDistance(int index1, int index2, int *distance, 
  int *passengers, bool display) const
{
  cityArray[index1].calcDistance( &cityArray[index2], distance, passengers,
    display);
}  // calcDistance()

void Vector::cleanCities()
{
  int i = 0;
  
  while (i < count)
  {
    if (!cityArray[i].hasAirport())
    {
      cityArray[i] = cityArray[--count];
    }  // if city does not have an airport
    else // city has an airport
      i++;
  }  // while more in array
}  // cleanCities())


int Vector::findAirport(const char *airport) const
{
  City city;
  
  city.setAirport(airport);
  
  for (int i = 0; i < count; i++)
    if (cityArray[i].isEqual(&city))
      return i;
  
  cout << airport << " is not a valid airport.\n";
  return -1;
}  // findAirport()


void Vector::readAirports()
{
  char line[1000], state2[80];
  City city;
  ifstream inf("airportLL.txt");

  while (inf.getline(line, 1000))
  {
    if (isalpha(line[0]))
      strcpy(state2, strtok(line, "\n"));
    
    if (line[0] == '[')
    {
      city.readAirport(line, state2);
      
      for (int i = 0; i < count; i++)
        if (cityArray[i].isEqual(&city))
        {
          cityArray[i].copyLocation(&city);
          break;
        }  // if found a matching name
      
      city.deallocate();
    }  // if an airport line
  }  // while
}  // readAirports()


void Vector::readCities()
{
  ifstream inf("citypopulations.csv");
  
  while(!inf.eof())
  {
    if (size == count)
      resize();
  
    cityArray[count++].readCity(inf);
  } // while more in file
  
  count--;
  inf.close();
}  // readCities()


void Vector::resize()
{
  int i;
  City *temp = new City[2 * size];
  
  for (i = 0; i < size; i++)
    temp[i] = cityArray[i];
  
  size *= 2;
  
  delete[] cityArray;
  cityArray = temp;
}  // resize()




#include <iostream>
#include <iomanip>
#include <climits>
#include <cmath>
#include "plane.h"

using namespace std;

Plane::Plane() {
} // Plane()


int Plane::calcCost(int distance, int numPassengers, int *trips) const
{
  double fuelCost, attendantSalaries, pilotSalaries, maintenance, hours;
  int crewHours;
  
  if(distance <= range)
  {
    *trips = ceil ((double) numPassengers / passengers);
    fuelCost =  fuelPrice * distance * fuel / range;
    hours = distance / (double) speed;
    crewHours = ceil((double) hours + 2);
    attendantSalaries = crewHours * ceil((double) passengers / 100) 
      * attendantHourly;
    pilotSalaries = 2 * crewHours * pilotHourly;
    maintenance =  0.000025 * distance * price / speed;
    return ceil(*trips 
      * (fuelCost + attendantSalaries + pilotSalaries + maintenance));
  }
   
  *trips = 0;
  return INT_MAX;
}

const char* Plane::getName() const
{
  return name;
}

void Plane::getPlane()
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
}  // getPlane())


ostream& operator << (ostream &os, const Plane &plane)
{
  os << setw(12) << left << plane.name << setw(6) << plane.passengers;
  
  if (plane.range >= 1000)
    os << plane.range / 1000 << ',' << setfill('0') << setw(3) 
      << right << plane.range % 1000 << setfill(' ');
  else
    os << setw(5) << right << plane.range;
  
  os << setw(4) << right << plane.speed;
  
  if (plane.fuel >= 1000)
    os << setw(5) << plane.fuel / 1000 << ',' << setfill('0') << setw(3) 
      << plane.fuel % 1000 << setfill(' ');
  else
    os << setw(10) << plane.fuel;
    
  os << setw(6) << fixed << setprecision(3) 
    << plane.range / (double) plane.fuel << setw(6) << setprecision(2)
    << (plane.fuelPrice * plane.fuel) / plane.range << setw(2) << "$"
    << setw(5) << setprecision(1)  << plane.price / 1000000.0 << endl;
    
  return os;
}  // operator<<



#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <climits>
#include "vector.h"
#include "plane.h"
using namespace std;


void addPlaneInformation(Plane planes[], int *planeCount)
{
  planes[*planeCount].getPlane();
  ofstream outf("planes.dat", ios::app|ios::binary);
  outf.write((char*) &planes[(*planeCount)++], sizeof(Plane));
  outf.close();
}  // addPlaneInformation()


void calcDistance(const Vector *cities)
{
  char airport1[80], airport2[80];
  int index1, index2, distance, passengers;
  cout << "\nPlease enter two airport abbreviations (XXX XXX): ";
  cin >> airport1 >> airport2;
  index1 = cities->findAirport(airport1);
  index2 = cities->findAirport(airport2);

  if (index1 >= 0 && index2 >= 0)
    cities->calcDistance(index1, index2, &distance, &passengers, true);
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


void determineBestPlane(const Vector *cities, const Plane *planes, 
  int planeCount)
{
  char airport1[80], airport2[80];
  int index1, index2, distance, passengers, minIndex = -1, minCost = INT_MAX, 
    minTrips, trips, cost;
  cout << "\nPlease enter two airport abbreviations (XXX XXX): ";
  cin >> airport1 >> airport2;
  index1 = cities->findAirport(airport1);
  index2 = cities->findAirport(airport2);

  if (index1 >= 0 && index2 >= 0)
  {
    cities->calcDistance(index1, index2, &distance, &passengers, false);
      
    for(int i = 0; i < planeCount; i++)
    {
       cost = planes[i].calcCost(distance, passengers, &trips);
       
       if(trips > 0 && cost < minCost)
       {
         minTrips = trips;
         minCost = cost;
         minIndex = i;
       }  // if lower cost
    }  // for each plane
    
    if (minIndex == -1)
      cout << "No planes available\n";
    else
    {
      cout << "Passengers Miles  Trips Name      Cost\n";
      cout << left << setw(11) << passengers << setw(7) << distance << setw(6) 
        << minTrips << setw(10) << planes[minIndex].getName() << '$' << minCost 
        << endl;
    }
  }   // if valid inputs  
}  //  determineBestPlane()


void displayPlaneInformation(const Plane *planes, int planeCount)
{
  cout << "\nPlane Information\n";
  cout << "Name        Pass. Range Speed Fuel   MPG   $/mi  Price * 10^6\n";
  
  for(int i = 0; i < planeCount; i++)
    cout << planes[i];

}  // displayPlaneInformation()


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


void readPlanes(Plane planes[], int *planeCount)
{
  ifstream inf("planes.dat", ios::binary);
  *planeCount = 0;
  
  if(! inf)
    return;

  while(inf.read((char*) &planes[(*planeCount)++], sizeof(Plane)));

  --(*planeCount);
  inf.close();
} // readPlanes()



void run(const Vector *cities, Plane *planes, int planeCount)
{
  int choice;
  
//  for(index1 = 0; index1 < cities->count; index1++)
//    for(index2 = index1 + 1; index2  < cities->count; index2++)
//      calcDistance(cities, index1, index2);

  do
  {
    choice = getChoice();
    
    switch(choice)
    {
      case 1 : calcDistance(cities); break;
      case 2 : determineAirportTraffic(cities); break;
      case 3 : displayPlaneInformation(planes, planeCount); break;
      case 4 : addPlaneInformation(planes, &planeCount); break;
      case 5 : determineBestPlane(cities, planes, planeCount); break;
    }  // switch
  } while(choice != 0);
}  // run())


int main(int argc, char** argv) 
{
  Vector cities;
  Plane planes[10];
  int planeCount = 0;
  cities.readCities();
  cities.readAirports();
  cities.cleanCities();
  readPlanes(planes, &planeCount);
 
//  srand(1);
//  for(int i = 0; i < cities.count; i++)
//    cout << "1\n" << cities.cityArray[i].airport << ' ' << cities.cityArray[rand() % cities.count].airport << endl;
//  printf("%s %s %lf %lf\n", cities.cityArray[i].name, cities.cityArray[i].airport, cities.cityArray[i].latitude, cities.cityArray[i].longitude);
  run(&cities, planes, planeCount);
  return 0;
} // main())

