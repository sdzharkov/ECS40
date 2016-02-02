#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "booklist.h"
using namespace std;

int main(int argc, char* argv[])
{
  char title[80], author[80], courseName[80];
  BookList list;
  BookNode *ptr;
  cout << "Title (done = exit): ";
  cin.getline(title, 80);
  while(strcmp(title, "done"))
  {
    cout << "Author: ";
    cin.getline(author,80);
    cout << "Course name (\"\" = none): ";
    cin.getline(courseName, 80);
    if(strlen(courseName) > 0)
      ptr = (BookNode*) new TextBookNode(title, author, courseName);
    else
      ptr = new BookNode(title, author);

    list.insert(ptr);
    cout << "Title (done = exit): ";
    cin.getline(title,80);
  }
  
  list.write("books.txt");
  return 0 ;
}
