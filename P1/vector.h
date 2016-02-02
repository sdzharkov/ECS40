#ifndef VECTOR_H
  #define VECTOR_H
#define MAX_LINE_LENGTH (80)
#define INITIAL_VECTOR_SIZE (10)
typedef struct vector
{
  City* cityArray;
  int size;
  int count;
} //
Vector;

void initialize(Vector* baseVector);
void readCity(Vector *baseVector);
void readAirports(Vector* baseVector);
void resize(Vector* baseVector);
void cleanCities(Vector *baseVector);
void deallocate(Vector *baseVector);
int findAirport(const char *city1, const Vector *baseVector);
void calcDistance(const Vector *baseVector, int count1, int count2);
#endif


