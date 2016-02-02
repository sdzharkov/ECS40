#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>
#include <iterator>
#include <vector>
using namespace std;

void insert(vector<string> &myVector, ifstream& cmd)
{
  string character;
  int lineNum = 0, position = 0, i = 0;
  cmd >> lineNum;
  cmd >> position;
  getline (cmd, character);
  vector<string>::iterator itr;
  
  for (itr = myVector.begin(); itr != myVector.end(); ++itr, i++)
  {
    if (i == lineNum)
      break;
  } //
  
  character.erase(0, 1);
  (*itr).insert(position, character);
} //

void replace(vector<string> &myVector, ifstream& cmd)
{
  int lineNum = 0, position = 0, endPosition = 0, i = 0;
  string character;
  cmd >> lineNum;
  cmd >> position;
  cmd >> endPosition;
  getline(cmd, character);
  int len = endPosition - position;
  vector<string>::iterator itr;
  
  for (itr = myVector.begin(); itr != myVector.end(); ++itr, i++)
  {
    if (i == lineNum)
      break;
  } //
  
  character.erase(0, 1);
  (*itr).replace(position, len, character);
} //

void find(vector<string> &myVector, ifstream& cmd)
{
  string character;
  int i = 0;
  getline(cmd, character);
  character.erase(0, 1);
  cout << character << " ";
  vector<string>::iterator itr;
  
  for (itr = myVector.begin(); itr != myVector.end(); ++itr, i++)
  {
    if ((*itr).find(character) < (*itr).length())
    {
      cout << i << " ";
    } //
  } //
  
  cout << endl;
} //

void deletee(vector<string> &myVector, ifstream& cmd)
{
  int startLine = 0, endLine = 0, i = 0, j = 0;
  string character;
  cmd >> startLine;
  cmd >> endLine;
  vector<string>::iterator itr;
  vector<string>::iterator it;
  
  for (itr = myVector.begin(); itr != myVector.end(); ++itr, i++)
  {
    if ( i == startLine)
      break;
  } //
  
  for (it = myVector.begin(); it != myVector.end(); ++it, j++)
  {
    if ( j == endLine)
      break;
  } //
  
  myVector.erase(itr, it + 1);
  
}//

void erase(vector<string> &myVector, ifstream& cmd)
{
  int i;
  string character;
  getline(cmd, character);
  vector<string>::iterator itr;
  
  character.erase(0, 1);
  
  for (itr = myVector.begin(); itr != myVector.end(); ++itr, i++)
  {
    if ((*itr).compare(character) == 0)
    {
      myVector.erase(itr);
      continue;
    } //
    
    if ((*itr).find(character) < (*itr).length())
      (*itr).erase((*itr).find(character), character.length());
  }  //
} //

void copy(vector<string> &myVector, ifstream& cmd)
{
  string character;
  int start = 0, end = 0, dest = 0, i = 0;
  cmd >> start;
  cmd >> end;
  cmd >> dest;
  vector<string>::iterator itr;

  vector<string> temp(myVector.begin() + start, myVector.begin() + end + 1);
 
  for (itr = myVector.begin(); itr != myVector.end(); ++itr, i++)
  {
    if (i == dest)
      break;
  }  //
  
  myVector.insert(itr, temp.begin(), temp.end());
  
} //
  
void move(vector<string> &myVector, ifstream& cmd)
{
  string character;
  int start = 0, end = 0, dest = 0;
  cmd >> start;
  cmd >> end;
  cmd >> dest;
  vector<string>::iterator itr;

  vector<string> temp(myVector.begin() + start, myVector.begin() + end + 1);

  if (dest > start)
    {
    dest = dest - (end + 1 - start);
    } //
  
  myVector.erase(myVector.begin() + start, myVector.begin() + end + 1);
  
  myVector.insert(myVector.begin() + dest, temp.begin(), temp.end());

} //

void readFiles(char **srcFile, vector<string> &myVector)
{
  ifstream src(srcFile[1]);
  ifstream cmd(srcFile[2]);
  string line, com, first, fourth;
  
  while (getline (src, line))
    myVector.push_back(line);
  
  while (cmd >> first)
  {
    
    if (first == "I")
      insert(myVector, cmd);

    if (first == "R")
      replace(myVector, cmd);

    if (first == "F")
      find(myVector, cmd);

    if (first == "D")
      deletee(myVector, cmd);

    if (first == "E")
      erase(myVector, cmd);

    if (first == "C")
      copy(myVector, cmd);

    if (first == "M")
      move(myVector, cmd);
  } //

  src.close();
  cmd.close();
} //

void write(vector<string> &myVector, char** destFile)
{
  vector<string>::iterator itr;
  ofstream inf(destFile[3], ios_base::trunc);

  for (itr = myVector.begin(); itr != myVector.end(); ++itr)
  {
    if (inf.is_open())
    {
      inf << *itr << endl;
    } //
  }//
  
  inf.close();
  
} //



int main(int argc, char** argv) 
{

  vector<string> myVector;
  vector<string>::iterator itr;
  readFiles(argv, myVector);
  write(myVector, argv);
  
  return 0;
  
} //

