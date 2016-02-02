#include <stdio.h>
#include <stdlib.h>

// insertion sort, several errors

int X[10],  // input array
    Y[10],  // workspace array  
    NumInputs,  // length of input array
    NumY = 0;  // current number of 
               // elements in Y

void getArgs(int AC, char **AV)

{  int I;

   NumInputs = AC - 1;

   for (I = 0; I < NumInputs; I++)
      X[I] = atoi(AV[I + 1]);
} //

void scootOver(int JJ)

{  int K;

   for (K = NumY; K > JJ; K--)
      Y[K] = Y[K - 1];
} //

void insert(int NewY)

{  int J;

   if (NumY == 0)  
     { // Y empty so far,
       Y[0] = NewY;
       return;
     } //
   // need to insert just before the first Y

   for (J = 0; J < NumY; J++) 
      {
      if (NewY < Y[J])
         {
         // shift Y[J], Y[J+1],... rightward
         // before inserting NewY
         scootOver(J);
         Y[J] = NewY;
         return;
         }//
      }//
  //one more case: NewY > all existing Y elements
  Y[NumY] = NewY;
} //

void processData()
{  

   for (NumY == 0; NumY < NumInputs; NumY++)
      // insert new Y in the proper place 
      // among Y[0],...,Y[NumY-1]
      insert(X[NumY]);
}

void printResults()

{  int I;

   for (I = 0; I < NumInputs; I++)
      printf("%d\n",Y[I]);
} //

int main(int Argc, char ** Argv)

{  
   getArgs(Argc,Argv);
   processData();
   printResults();
} //
 
