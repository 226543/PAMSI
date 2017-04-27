#include <iostream>
#include <string>
//#include "hashtable.hh"

using namespace std;

int main() {
	std::string dd = "aa";
	/*
	Hashtable test;
	cout << test.hash(dd);
	*/
	int value = 0 ;
	for (int i = 0; i < dd.length(); i++) {
		char x = dd.at(i);
		value += int(x);
	}
	cout <<value;
	return 0;
}
