#include <fstream>
#include <istream>
#include <string>
#include "results.h"
using namespace std;

int main()
{
  Results results;
  string directory;
  ifstream inf("results.csv");
  inf >> results;

  do{
    cout << "Please enter a directory: ";
    cin >> directory;
    results.print(directory);
  } while (directory != "Done");
  return 0;
}
