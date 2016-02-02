#ifndef RESULT_H
	#define RESULT_H
#include "trial.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include "list.h"
#include <string>
#include <cstring>
using namespace std;

class Normal{
protected:
	string name;
	multiset <Trial> trials;
public:
	Normal(const string &n, const vector <bool> &v, const vector <float> &t);
	void print() const;
	virtual float getTime() const; // returns time selected
	const string& getName() const {return name;}
}; // class Normal

class Multiple : public Normal {
public:
	Multiple(const string &n, const vector <bool> &v, const vector <float> &t);
	float getTime() const; // returns time selected
}; // class Multiple


typedef map <string, Normal*> ResultsMap;
class Results {
	ListNode <Normal> *head; ResultsMap map;
public:
	Results() : head(NULL) {;};
	~Results();
	void print(const string &directory) const;
	Results& operator+= (Normal *n);
	friend istream& operator>> (istream &is, Results &result);
};

#endif