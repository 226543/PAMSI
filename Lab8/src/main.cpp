#include <iostream>
#include "../inc/tree.hh"
#include "../inc/tester.hh"
#include "../inc/assistant.hh"
using namespace std;

int main() {
	//Assistant helper;
	//Tester obj;

	//int amountOfData = 10;     // liczba próbek
	//int reps = 1;                 // liczba powtórzeń obliczeń
	//helper.measure(obj,amountOfData,reps);   // funkcja wyswietla czas sredni
	RBTree drzewo;
	drzewo.insert(1);
	drzewo.insert(2);
	drzewo.insert(3);
	drzewo.insert(4);
	drzewo.insert(5);
	drzewo.print(drzewo.getRoot());
	drzewo.deleteTree();
	drzewo.print(drzewo.getRoot());


	return 0;
}
