#ifndef DARRAY_HH
#define DARRAY_HH
#include "measurable.hh"

class DArray : public Measurable {
	private:
	int *tab;
	unsigned int size;               // liczba elementow tablicy, ktorej przydzielono wartosci
	unsigned int allocatedSize;      // liczba elementów dla których jest zaalokowana pamięć

	void expandTab1();
	void expandTab2();
	void shrinkTab1();
	void shrinkTab2();

	public:
	DArray() {
		tab = new int[10];
		size = 0;
		allocatedSize = 10;
	}

	DArray(int x) {
		tab = new int[x];
		size = 0;
		allocatedSize = x;
	}

	~DArray() {
		delete []tab;
	}

	//przeciążenia operatora indeksowania z zabezpieczeniami wyjścia poza zakres
	int operator [](unsigned int index)const;
	int &operator [](unsigned int index);

	void displayTab()const;        // wyświetla elementy tablicy
	int showSize()const;           // zwraca liczbę elementów w tablicy
	int showCapacity()const;       // zwraca liczbę elementów dla których jest zarezewowana pamięć

	void addElem1(int value);          // metoda dodająca element na koniec tablicy, gdy za malo miejsca powieksza tablice o 1 element
	void addElem2(int value);          // metoda dodająca element na koniec tablicy, gdy za malo miejsca powieksza tablice o 2 razy
	void delElem1();			   // metoda usuwająca ostatni element i pomniejsza tablice o jeden element
	void delElem2();          	   // metoda usuwająca ostatni element, gdy jest możliwe to pomniejsza tablicę o połowę

	void doThings(unsigned int amount,int mode);
	void restart();
};

#endif
