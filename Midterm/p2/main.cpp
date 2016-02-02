#include <iostream>
#include <fstream>
#include <cstring>

#include "itemList.h"
#include "item.h"

int main(int argc, char* argv[])
{
	itemList list;
	list.read(argv[1]);
	list += new Item("napkins", 1.29);
	list += new Perishable("carrots", 0.49, "11-28-02");
	cout << "012345678901234567890123456789\n";
	//cout << list;
	return 0;
} // main()

