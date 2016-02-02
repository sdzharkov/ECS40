#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include "booklist.h"
using namespace std;

BookList::BookList(): head(NULL), count(0) {}

BookList::~BookList()
{
}

BookNode::BookNode(const char *titl, const char *auth)
{
  title = new char[strlen(titl) + 1];
  strcpy(title, titl);
  author = new char[strlen(auth) + 1];
  strcpy(author, auth);
}

BookNode::~BookNode()
{
  delete [] title;
  delete [] author;
}

TextBookNode::TextBookNode(const char *titl, const char *auth, const char *cours): BookNode(titl,auth)
{
  course = new char[strlen(cours) + 1];
  strcpy(course, cours);
}


TextBookNode::~TextBookNode()
{
  delete [] course;
}

const char* BookNode::getAuthor() {return author;}

const char* BookNode::getTitle() const {return title;}

void BookNode::write (ostream &os) const
{
  
  os << "Title: " << setw(21) << left << title 
     << "Author: " << author << endl;
}

void TextBookNode::write (ostream &os) const
{
  os << "Course: " << setw(10) << left << course
     << "Author: " << setw(10) << author << "Title: " << getTitle() << endl;
}

const char* TextBookNode::getCourse() const {return course;}

void BookList::write(char *outfile)
{
  ofstream outf(outfile);
  BookNode *ptr = head;
  
  while(ptr)
  {
    ptr->write(outf);
    ptr = ptr->next;
  }
  outf.close();
}

void BookList::insert(BookNode *n)
{
  BookNode *ptr, *prev = NULL;
  if(n)
  {
    for (ptr = head; ptr && strcmp(n->title, ptr->title) > 0; ptr = ptr->next)
      prev = ptr;

    if (prev)
    {
      prev->next = n;
      n->next = ptr;
    }
    else
    {
      head = n;
      n->next = ptr;
    }
  } 
}

