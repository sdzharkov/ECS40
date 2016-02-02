#include <iostream>
#include <fstream>
#include <cctype>
#include <set>
#include <map>
#include <locale>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iomanip>
using namespace std;

class Word
{
  string word;
  short value;
public:
  Word (string w, short v): word(w), value(v){};
  string getWords() const {return word; };
  int getValue() const {return value; };
  bool operator < (const Word &rhs) const;
}; //

bool Word::operator < (const Word &rhs) const
{
    return (word < rhs.word);
} //

void createMap(map<char, short> &scrabbleMap, short values[])
{
  char c = 'a';

  for (int i = 0; i < 26; i++, c++)
  {
    scrabbleMap.insert(pair<char, short>(c, values[i]));
  }//
}//

short calcVal(string line, map<char, short> &scrabbleMap)
{
  short val = 0;

  for (string::iterator itr = line.begin(); itr != line.end(); ++itr)
  {
    val += scrabbleMap.find(*itr)->second;
  }//

  return val;
}//

void displaySet(set<string>tempVec, string str, int high)
{
  if (high > 0 && str.length() < 8)
  {
    cout << setw(2) << right << high << " " << str << ":";

    for (set<string>::iterator it = tempVec.begin(); it != tempVec.end(); ++it)
    {
      cout << " " << *it;
    } //

    cout << endl;
  } //
  else //
    cout << setw(2) << right << "0" << " " << str << ": No words found."
         << endl;
} //


void  readFile(set<Word> &scrabble, char* file, map<char, short> scrabbleMap)
{
  string line, sub; short high = 0; set<string> tempVec, tempLine;
  ifstream inf(file);

  while (getline(inf, line))
  {
    string str; str.append(line); set<Word>::iterator point;
    sort(line.begin(), line.end());

    do
    {
      for (size_t i = 1; i < 8; i++)
      {
        sub = line.substr(0, i);
        Word temp(sub, calcVal(sub, scrabbleMap));
        point = scrabble.find(temp);

        if (point != scrabble.end() && point->getValue() >= high)
        {
          if (point->getValue() > high)
          {
        	tempVec.clear();
            tempVec.insert(temp.getWords());
            high = point->getValue();
          } //

          else //
            if (point->getValue() == high)
              tempVec.insert(temp.getWords());
        }//
      }   //
    } while(next_permutation(line.begin(), line.end()));
    displaySet(tempVec, str, high);
    high = 0;
  } //
} //

void getWord(set<Word> &scrabble, char* file, map<char, short> &scrabbleMap)
{
  locale loc;
  string line;
  //int i = 0;
  ifstream inf("words.txt");
  set<Word>::iterator it;
  bool val = true;

  while (getline (inf, line))
  {
    val = true;

    if (line.length() <= 7)
    {
      for (string::const_iterator itr = line.begin(); itr != line.end(); ++itr)
      {
        if (!isalpha((*itr), loc) || isupper((*itr), loc))
        {
          val = false;
        } //
      } //

        if (val)
        {
          scrabble.insert(Word (line, calcVal(line, scrabbleMap)));
        } //
      
    } //
  } //
 // for (it = scrabble.begin(); it != scrabble.end(); ++it, i++)
  //{
    //cout << (it->getValue()) << ": " << (it->getWords()) << endl;
  //}
  inf.close();
  readFile(scrabble, file, scrabbleMap);
} //

int main(int argc, char** argv)
{
  set<Word> scrabble;
  map<char, short> scrabbleMap;
  short values [] = {1, 3, 3, 2, 1, 4, 2, 4, 2, 8, 5, 1, 3, 1, 1, 3, 10, 1,
                     1, 1, 1, 4, 4, 8, 4, 10};
  createMap(scrabbleMap, values);
  getWord(scrabble, *(argv + 1), scrabbleMap);
  return 0;
} //
