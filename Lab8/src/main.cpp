#include <iostream>
#include "tree.hh"
#include "tester.hh"
#include "assistant.hh"
using namespace std;

int main() {
	Assistant helper;
	Tester obj;

	int amountOfData = 100;     // liczba próbek
	int reps = 1;                 // liczba powtórzeń obliczeń

	helper.measure(obj,amountOfData,reps);   // funkcja wyswietla czas sredni


	return 0;
}
