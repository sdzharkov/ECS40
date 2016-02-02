// Author: Sean Davis 

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <iomanip>
#include <climits>
#include "list.h"
#include "airport.h"
#include "plane.h"
using namespace std;

void calcAirportTraffic(const List<Airport> &cities, int index);
void calcDistance(const List<Airport> &cities, int index1, int index2, 
                  int *distance, int *passengers, bool display);
void cleanCities(List<Airport> &cities);
int findAirport(const List<Airport> &cities, const char *airport);
void readAirports(List<Airport> &cities);
void readCities(List<Airport> &cities);

void determineRoute(const List<Airport> &cities)
{
  List<Flight> route;
  char origin[4], destination[4], airline[20];
  int index, path;

  cout << endl << "Please enter origin destination and an airline: ";
  cin >> origin >> destination >> airline;
  index = findAirport(cities, origin);
  path = cities[index].findRoute(cities, route, airline, destination);
  
  if (path <0)
    cout << "No route found." << endl;
  else //
    cout << route << endl;
 
} //

void addPlaneInformation(List<Plane> &planes)
{
  Plane plane;
  plane.getPlane();
  ofstream outf("planes.dat", ios::app | ios::binary);
  outf.write((char*) &plane, sizeof(Plane));
  planes += plane;
  outf.close();
}  // addPlaneInformation()


void calcDistance(const List<Airport> &cities)
{
  char airport1[80], airport2[80];
  int index1, index2, distance, passengers;
  cout << "\nPlease enter two airport abbreviations (XXX XXX): ";
  cin >> airport1 >> airport2;
  index1 = findAirport(cities, airport1);
  index2 = findAirport(cities, airport2);

  if (index1 >= 0 && index2 >= 0)
    calcDistance(cities, index1, index2, &distance, &passengers, true);
}  // calcDistance())


void determineAirportTraffic(const List<Airport> &cities)
{
  char airport[80];
  int index;
  cout << "\nPlease enter an airport abbreviation (XXX): ";
  cin >> airport;
  index = findAirport(cities, airport);

  if (index >= 0 && index >= 0)
    calcAirportTraffic(cities, index);
}  // determinAirportTraffic()


void determineBestPlane(const List<Airport> &cities, const List<Plane> &planes, 
                        int planeCount)
{
  char airport1[80], airport2[80];
  int index1, index2, distance, passengers, minIndex = -1, minCost = INT_MAX, 
    minTrips, trips, cost;
  cout << "\nPlease enter two airport abbreviations (XXX XXX): ";
  cin >> airport1 >> airport2;
  index1 = findAirport(cities, airport1);
  index2 = findAirport(cities, airport2);

  if (index1 >= 0 && index2 >= 0)
  {
    calcDistance(cities, index1, index2, &distance, &passengers, false);
      
    for (int i = 0; i < planes.getCount(); i++)
    {
       cost = planes[i].calcCost(distance, passengers, &trips);
       
       if (trips > 0 && cost < minCost)
       {
         minTrips = trips;
         minCost = cost;
         minIndex = i;
       }  // if lower cost
    }  // for each plane
    
    if (minIndex == -1)
      cout << "No planes available\n";
    else // else found a plane
    {
      cout << "Passengers Miles  Trips Name      Cost\n";
      cout << left << setw(11) << passengers << setw(7) << distance << setw(6) 
        << minTrips << setw(10) << planes[minIndex].getName() << '$' << minCost 
        << endl;
    } // else found a plane
  }   // if valid inputs  
}  //  determineBestPlane()


void displayPlaneInformation(const List<Plane> &planes)
{
  cout << "\nPlane Information\n";
  cout << "Name        Pass. Range Speed Fuel   MPG   $/mi  Price * 10^6\n";
  
  for (int i = 0; i < planes.getCount(); i++)
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
    cout << "5. Determine best plane between two airports.\n";
    cout << "6. Show airline flights.\n";
    cout << "7. Determine route between two airports.\n\n";

    cout << "Your choice (0 - 7): ";
    cin >> choice;
    cin.ignore(1000, '\n');
   
    if  (choice < 0 || choice > 7)
      cout << "Your choice must be between 0 and 7. Please try again.\n";
  } while(choice < 0 || choice > 7);
   
  return choice;
}  // getChoice()  


void readPlanes(List<Plane> &planes)
{
  ifstream inf("planes.dat", ios::binary);

  Plane plane;
  
  if (! inf)
    return;

  while (inf.read((char*) &plane, sizeof(Plane)))
    {
    planes += plane;
    } //
    
  inf.close();
} // readPlanes()



void run(const List<Airport> &cities, List<Plane> &planes, int planeCount)
{
  int choice;

  do
  {
    choice = getChoice();
    
    switch(choice)
    {
      case 1 : calcDistance(cities); break;
      case 2 : determineAirportTraffic(cities); break;
      case 3 : displayPlaneInformation(planes); break;
      case 4 : addPlaneInformation(planes); break;
      case 5 : determineBestPlane(cities, planes, planeCount); break;
      case 6 : cout << cities; break;
      case 7 : determineRoute(cities); break;
    }  // switch
  } while(choice != 0);
}  // run())


void calcAirportTraffic(const List<Airport> &cities, int index)
{
  int total = 0;
  
  for (int i = 0; i < cities.getCount(); i++)
    if (i != index)
      total += cities[index].showTraffic(cities[i]);
  
  cout << "Total passengers: " << total << endl;
}  // calcAirportTraffic()


void calcDistance(const List<Airport> &cities, int index1, int index2, 
                  int *distance, int *passengers, bool display)
{
  cities[index1].calcDistance( &cities[index2], distance, passengers,
    display);
}  // calcDistance()


void cleanCities(List<Airport> &cities)
{
  int i = 0;
  
  while (i < cities.getCount())
  {
    if (!cities[i].hasAirport())
      cities -= cities[i];
    else // city has an Airport
      i++;
  }  // while more in array
}  // cleanCities())


int findAirport(const List<Airport> &cities, const char *airport)
{
  Airport city;
  
  city.setAirport(airport);
  
  for (int i = 0; i < cities.getCount(); i++)
    if (cities[i] == city)
      return i;
  
  cout << airport << " is not a valid airport.\n";
  return -1;
}  // findAirport()


void readAirports(List<Airport> &cities)
{
  char line[1000], state2[80];
  Airport city;
  ifstream inf("airportLL.txt");

  while (inf.getline(line, 1000))
  {
    if (isalpha(line[0]))
      strcpy(state2, strtok(line, "\n"));
    
    if (line[0] == '[')
    {
      city.readAirport(line, state2);
      
      for (int i = 0; i < cities.getCount(); i++)
        if (cities[i] == city)
        {
          cities[i].copyLocation(&city);
          break;
        }  // if found a matching name
      
      city.deallocate();
    }  // if an Airport line
  }  // while
}  // readAirports()


void readCities(List<Airport> &cities)
{
  ifstream inf("citypopulations.csv");
  Airport city;
  
 // while(!inf.eof())
 while(inf >> city)
  {
    cities += city;
    city.deallocate();
  } // while more in file
  
  inf.close();
}  // readCities()

void readAirlines(char* filename, List<Airport> &cities)
{
  char line [1000], origin[4];
  int index = 0;
  ifstream inf(filename);
  Airport city;
  
  while (inf.getline(line, 1000))
    {
    
    if (index >= 9)
      {
      strcpy(origin, strtok(line, " "));
      city.setAirport(origin);
      
      for ( int i = 0; i < cities.getCount(); i++)
        {
        
        if (cities[i] == city)
          {
            cities[i].readAirline(line);
            break;
          } //
        } //
       // }
      } //
      
    index ++;
    
    } //
    
  inf.close();
} //


int main(int argc, char** argv) 
{
  List<Airport> cities;
  List<Plane> planes;
  List<Airport> flights;
  int planeCount = 0;
  readCities(cities);
  readAirports(cities);
  cleanCities(cities);
  readPlanes(planes);
  readAirlines(argv[1], cities);

  run(cities, planes, planeCount);
  return 0;
} // main())

