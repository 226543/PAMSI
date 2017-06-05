#include <iostream>
#include "../inc/tree.hh"
#include "../inc/tester.hh"
#include "../inc/assistant.hh"
using namespace std;

int main() {
	Assistant helper(100);
	Tester obj;

	int amountOfData = 1000;     // liczba próbek
	int reps = 100;                 // liczba powtórzeń obliczeń
	helper.measure(obj,amountOfData,reps);   // funkcja wyswietla czas sredni

	return 0;
}
