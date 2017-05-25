#include <iostream>
#include <string>
#include "assistant.hh"
#include "tester.hh"

using namespace std;

int main() {
	Assistant helper(100);
	Tester obj;
	int amountOfData = 100000;  // liczba próbek
	int reps = 100;               // liczba powtórzeń obliczeń
	int mode = 2;                // wybór funkcji haszującej

	helper.measure(obj,amountOfData,reps,mode);   // funkcja wyswietla czas sredni

	return 0;
}
