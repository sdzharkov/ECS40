#include "result.h"
#include <iostream>
using namespace std;
/*
void print(const string &directory) const
{
	cout << Results->getName() 
}
*/
Results& Results::operator += (Normal *n)
{
	//ListNode *ptr, *prev = NULL;
	//for (multiset<Trial>::iterator itr = n->trials.begin(); itr != n->trials.end(); ++itr)
	//{
	//	map.insert(valid, time);
	//}

}

istream &operator >> (istream &is, Results &result)
{
	char line[1000];
	string name, dir;
	int num;
	bool val;
	float it;
	is.getline(line, 1000);
	vector<bool> v;
	vector<float> t;
	while (is.getline(line, 1000))
	{
		strcpy(dir, strtok(line, ","));
		name = (strtok(NULL, ",") + 1);
		for (int = 0; i < 5; i++)
		{
			it = (strtok(NULL, ",") + 1);
			if (it == "yes")
			{
				v.insert(true);
			}
			else
				v.insert(false);

			it = atof(strtok(NULL, ","));
			t.insert(it);

		}
	}
}