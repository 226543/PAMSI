#include <iostream>
#include "../inc/tree.hh"
#include "../inc/tester.hh"
#include "../inc/assistant.hh"
using namespace std;

int main() {
	Assistant helper;
	Tester obj;

	int amountOfData = 10000;     // liczba próbek
	int reps = 20;                 // liczba powtórzeń obliczeń
	helper.measure(obj,amountOfData,reps);   // funkcja wyswietla czas sredni

	return 0;
}
