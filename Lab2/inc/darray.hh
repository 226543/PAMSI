#ifndef DARRAY_HH
#define DARRAY_HH

#define STARTSIZE 10                 // liczba elementow, ktora pomiesci tablica po inicjalizacji


class DArray {

	private:

	int *tab = nullptr; 
	unsigned int size;               // liczba elementow tablicy, ktorej przydzielono wartosci
	unsigned int allocatedSize;      // liczba elementów dla których jest zaalokowana pamięć

	void expandTab1(void);
	void expandTab2(void);
	void shrinkTab(void);

	public:

	DArray() {
		tab = new int[STARTSIZE];   
		size = 0;
		allocatedSize = STARTSIZE;
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

	void displayTab(void)const;        // wyświetla elementy tablicy
	int showSize(void)const;           // zwraca liczbę elementów w tablicy
	int showCapacity(void)const;       // zwraca liczbę elementów dla których jest zarezewowana pamięć
	void addElem1(int value);          // metoda dodająca element na koniec tablicy, gdy za malo miejsca powieksza tablice o 1 element
	void addElem2(int value);          // metoda dodająca element na koniec tablicy, gdy za malo miejsca powieksza tablice o 2 razy
	void delElem(int value);           // metoda usuwająca ostatni element w tablicy
};

#endif 
