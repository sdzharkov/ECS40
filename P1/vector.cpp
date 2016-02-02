#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "city.h"
#include "vector.h"

Vector* baseVector;
City baseCity;

void initialize(Vector* baseVector)
{
  int i = 0;
  baseVector->count = 0;
  baseVector->size = INITIAL_VECTOR_SIZE;
  baseVector->cityArray = (City*)malloc(baseVector->size * sizeof(City));
  
  if (baseVector->cityArray != NULL)
  {
    for (i = 0; i < baseVector->size; i++)
    {
      initialize(&baseVector->cityArray[i]);
    } //
  } //
} //


void resize(Vector *baseVector)
{
  int i;
  City *tempArray = (City*)malloc(sizeof(City)*(baseVector->count)*2);
  
  for (i = 0; i < baseVector->count; i++)
  {
    tempArray[i] = baseVector->cityArray[i];
  } //
  
  baseVector->size *= 2;
  
  for (i = baseVector->count; i < baseVector->size; i++)
  {
    initialize(&tempArray[i]);
  } //
  
  free(baseVector->cityArray);
  baseVector->cityArray = tempArray;
} //

void readCity(Vector *baseVector)
{
  char csvline[MAX_LINE_LENGTH + 1];
  FILE* csvfile = fopen("citypopulations.csv", "r");
  
  if (csvfile != NULL)
  {
    while (fgets(csvline, MAX_LINE_LENGTH, csvfile) != NULL)
    {
      readCityfile(&baseVector->cityArray[baseVector->count], csvline);
      baseVector->count++;
      
      if (baseVector->count == baseVector->size)
      {
        resize(baseVector);
      } //
    } //
  } //
} //

void readAirports(Vector *baseVector)
{
  int i;
  char myFile[MAX_LINE_LENGTH + 1];
  City *citytemp = (City*)malloc(sizeof(City));
  initialize(citytemp);
  FILE* inFile = fopen("airportLL.txt", "r");
  
  if (inFile != NULL)
  {
    while (fgets(myFile, MAX_LINE_LENGTH, inFile) != NULL)
    {
      if (myFile[0] == '[')
      {
        readAirport(citytemp, myFile);
        
        for (i = 0; i < baseVector->count; i++)
        {
          if (isEqual(&baseVector->cityArray[i], citytemp))
          {
            copyLocation(&baseVector->cityArray[i], citytemp);
            break;
          } //
          else //
          {
            continue;
          } //
        } //
      } //
    } //
    
  fclose(inFile);
  free(citytemp);
  } //
} //

void cleanCities(Vector *baseVector)
{
  int i;
  
  for (i = 0; i<baseVector->count; i++)
  {
    if (hasAirport(&baseVector->cityArray[i]) == false)
    {
      deallocate(&baseVector->cityArray[i]);
      baseVector->cityArray[i] = baseVector->cityArray[baseVector->count];
      baseVector->count--;
      i = i - 1;
    } //
  } //
} //

void deallocate(Vector *baseVector)
{
  int i;
  
  for (i = 0; i < baseVector->count; i++)
  {
    deallocate(&baseVector->cityArray[i]);
  } //
  
  free(baseVector->cityArray);
} //

int findAirport(const char *city1, const Vector *baseVector)
{
  int i;
  City newtemp;
  initialize(&newtemp);
  setAirport(&newtemp, city1);
  
  for (i = 0; i <baseVector->count; i++)
  {
    if (isEqual(&baseVector->cityArray[i], &newtemp) == true)
    {
      return i;
    } //
  } //
  
  printf("%s is not a valid airport.\n", city1);
  return -1;
} //

void calcDistance(const Vector *baseVector, int count1, int count2)
{
  calcDistance(&baseVector->cityArray[count1], &baseVector->cityArray[count2]);
} //