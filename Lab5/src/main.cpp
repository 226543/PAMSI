#include <iostream>
#include "darray.hh"
#include "assistant.hh"
#include "measurable.hh"

using namespace std;

/* Spis opcji programu:
a) wybór metody wypelniania tablicy:
mode1 == 1 to tablica zostaje wypełniona losowymi elemenatmi
mode1 == 2 to tablica zostaje wypełniona elementami posortowanymi rosnąco
mode1 == 3 to tablica zostaje wypełniona elementami posortowanymi malejąco

b) wybór metody wyboru pivota:
mode2 == 1 to pivot zostanie wybrany losowo
mode2 == 2 to pivotem zostanie ostatni element
mode2 == 3 to pivotem zostanie środkowy element
*/
int main() {
	DArray obj;
	Assistant helper;

	int amountOfData = 1000000;     // liczba próbek
	int reps = 20;                // liczba powtórzeń obliczeń
	int mode1 = 3; 								// metoda wypelniania tablicy
	int mode2 = 3;                // metoda wyboru pivota

	helper.measure(obj,amountOfData,reps,mode1,mode2);
	return 0;
}
