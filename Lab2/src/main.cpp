#include <iostream>
#include "tablica.hh"

using namespace std;

int main(){
	Tablica test;

	test.dodajElement(2);
	test.dodajElement(3);
	test.dodajElement(4);
	test.dodajElement(5);
	test.dodajElement(7);
	test.wyswietlTablice();
	return 0;
}