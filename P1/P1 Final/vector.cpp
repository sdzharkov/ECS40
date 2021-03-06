// Author: Sean Davis

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "vector.h"
using namespace std;

//Vector::void initialize()
Vector::Vector()
{
  size = 10;
  count = 0;
  cityArray = new City[size];
  
 // for (int i = 0; i < size; i++)
  //  initialize(&cityArray[i]);
}  // initialize()


//Vector::void deallocate()
Vector::~Vector()
{
 // for (int i = 0; i < count; i++)
 //   deallocate(&cityArray[i]);
  
  //free(cityArray);
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
      //deallocate(&cityArray[i]);
      cityArray[i] = cityArray[--count];
    }  // if city does not have an airport
    else // city has an airport
      i++;
  }  // while more in array
}  // cleanCities())


int Vector::findAirport(const char *airpor) const
{
  City city;
  
  cityArray->setAirport(airpor);
  
  for (int i = 0; i < count; i++)
    if (cityArray[i].isEqual(&city))
      return i;
  
  cout<< airpor <<" is not a valid airport.\n";
  return -1;
}  // findAirport()


void Vector::readAirports()
{
  char line[1000];
  City city;
  //initialize(&city);
	ifstream fp;
	fp.open("airportLL.txt");
  while (fp.getline(line,1000))
  {
    if (line[0] == '[')
    {
      cityArray->readAirport(line);
      
      for (int i = 0; i < count; i++)
        if (cityArray[i].isEqual(&city))
        {
          cityArray[i].copyLocation(&city);
          break;
        }  // if found a matching name
      
      deallocate(&city);
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
      resize(cities);
  
    cities->readCity(&cityArray[count++], fp);
  } // while more in file
  
  count--;
  fp.close();
}  // readCities()


void Vector::resize()
{
  int i;
  //City *temp = (City*) malloc(sizeof(City) * 2 * size);
  City *temp = new City[2*size];
  for (i = 0; i < size; i++)
    temp[i] = cityArray[i];
  
  size *= 2;
  
  for (; i < size; i++)
    cityArray->initialize(&temp[i]);
    
  free(cityArray);
  cityArray = temp;
}  // resize()


