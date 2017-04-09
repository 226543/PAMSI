#include <iostream>
#include "darray.hh"
#include "assistant.hh"
#include "stack.hh"
#include "list.hh"
#include "queue.hh"

using namespace std;

int main() {
	Assistant helper;
	Queue obj;

	int amountOfData = 1000;     // liczba próbek
	int reps = 5;                 // liczba powtórzeń obliczeń
	int mode = 1;                  // wybór metody

	helper.measure(obj,amountOfData,reps,mode);   // funkcja wyswietla czas sredni

	return 0;
}
