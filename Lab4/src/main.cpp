#include <iostream>
#include "darray.hh"
#include "assistant.hh"
#include "stack.hh"

using namespace std;

int main() {
	Assistant helper;
	Stack obj(10000000);

	int amountOfData = 1000000;     // liczba próbek
	int reps = 20;                 // liczba powtórzeń obliczeń
	int mode = 1;                  // wybór metody

	helper.measure(obj,amountOfData,reps,mode);   // funkcja wyswietla czas sredni

	return 0;
}
