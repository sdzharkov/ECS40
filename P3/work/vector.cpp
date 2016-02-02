// Author: Sean Davis

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "vector.h"
using namespace std;

Vector::Vector()
{
  size = 10;
  count = 0;
  cityArray = new City[size];
}  // initialize()

Vector::~Vector()
{
  //if(cityArray != NULL)
  delete[] cityArray;
}  // deallocate())


void Vector::calcDistance(int index1, int index2) const
{
  cityArray[index1].calcDistance(&cityArray[index1], &cityArray[index2]);
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


int Vector::findAirport(const char *airpor) const
{
  City city;
  
  city.setAirport(airpor);
  
  for (int i = 0; i < count; i++)
    {
    if (cityArray[i].isEqual(&city))
      return i;
    
    } //
  cout << airpor << " is not a valid airport.\n";
  return -1;
}  // findAirport()


void Vector::readAirports()
{
  char line[1000];
  char state[40];
  City city;
  ifstream fp;
  fp.open("airportLL.txt");
  
  while (fp.getline(line, 1000))
  {
    if (isalpha(line[0]))
      strcpy(state, line);
    
    if (line[0] == '[')
    {
      city.readAirport(line, state);
      
      for (int i = 0; i < count; i++)
        if (cityArray[i].isEqual(&city))
        {
          cityArray[i].copyLocation(&city);
          //cout<<cityArray[i].name;
          break;
        }  // if found a matching name
      
      city.deallocate();
    }  // if an airport line
  }  // while
}  // readAirports()


void Vector::readCities()
{
  ifstream fp;
  fp.open("citypopulations.csv");
  
  while(!fp.eof())
  {
    if (size == count)
      resize();
      
    cityArray[count++].readCity(fp);
      //how to do it  
  } // while more in file
  
  count--;
  fp.close();
}  // readCities()


void Vector::resize()
{
  int i;
  City *temp = new City[2*size];
  
  for (i = 0; i < size; i++)
    temp[i] = cityArray[i];
  
  size *= 2;
  delete [] cityArray;
  cityArray = temp;
}  // resize()

void Vector::calcAirportTraffic(int index) const
{
 int distance, passengers;
 int i;
 int totalPassengers = 0;
 
 for (i = 0; i < count; i++)
   {
   //if (strcmp(cityArray[i].name, "Palmdale")==0)
    // {
   passengers = (double) cityArray[index].getPop() 
   * cityArray[i].getPop() / 2500000000U;
   
   distance = acos(sin(cityArray[index].getLat() * M_PI / 180) * 
    sin(cityArray[i].getLat() * M_PI / 180) 
    + cos(cityArray[index].getLat() * M_PI / 180) * 
    cos(cityArray[i].getLat() * M_PI / 180)
    * cos((cityArray[index].getLong() - cityArray[i].getLong())
    * M_PI / 180)) * 3963;
    
  if (strcmp(cityArray[index].getName(),cityArray[i].getName())==0)
    continue;
  
  if (distance <= 100)
   passengers = 0;
   
    //cout << distance;
   cout << cityArray[i].getName() << ", " << 
   cityArray[i].getState() << ": " << passengers << "\n";
 //  }
  totalPassengers = totalPassengers + passengers;
  } //
  
  cout << "Total passengers: " << totalPassengers << "\n";
} //



