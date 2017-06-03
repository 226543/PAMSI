#include <iostream>
#include "tree.hh"

using namespace std;

int main() {
	//Assistant helper;
	//Queue obj;

	//int amountOfData = 10000;     // liczba próbek
	//int reps = 20;                 // liczba powtórzeń obliczeń
	//int mode = 1;                  // wybór metody

	//helper.measure(obj,amountOfData,reps,mode);   // funkcja wyswietla czas sredni
	RBTree drzewo;

	drzewo.insert(1);
	drzewo.insert(2);
	drzewo.insert(3);
  drzewo.insert(4);
  drzewo.insert(5);
  drzewo.insert(6);
  drzewo.insert(7);
  drzewo.insert(8);

  drzewo.insert(100);

	drzewo.search(6);



	return 0;
}
