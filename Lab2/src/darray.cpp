#include <iostream>
#include "darray.hh"


void DArray::expandTab1(void) {

	int *tempTab = new int[1+size];

	// kopiowanie starej tablicy do nowej
	for(unsigned int i = 0; i<=size-1; ++i) {
		tempTab[i] = tab[i];
	} 
	delete [] tab; // zwalnianie pamięci przed przypisaniem nowej wartości
	tab = tempTab;
}

void DArray::expandTab2(void) {

	int *tempTab = new int[2*size];

	// kopiowanie starej tablicy do nowej
	for(unsigned int i = 0; i<=size-1; ++i) {
		tempTab[i] = tab[i];
	} 
	delete [] tab; // zwalnianie pamięci przed przypisaniem nowej wartości
	tab = tempTab;
}

void DArray::shrinkTab(void) {

	//TODO
}

void DArray::addElem1(int value) {

	if(size >= allocatedSize) {
		expandTab1();
		allocatedSize +=1;
	}
	tab[size] = value;
	++size;
}

void DArray::addElem2(int value) {

	if(size >= allocatedSize) {
		expandTab2();
		allocatedSize *=2;
	}
	tab[size] = value;
	++size;
}

void DArray::delElem(int value) {

	//TODO
}


void DArray::displayTab(void)const {

	if(size > 0){
		for(unsigned int i = 0; i <= size-1; ++i) {
			std::cout << tab[i] << " ";
		}
	}
	else{
		std::cout<<"Pusta Tablica"<<std::endl;
	}
	std::cout << std::endl;
}



int DArray::operator [](unsigned int index)const {
	
// zabezpiecznie przed wyjściem poza zakres, wyświetla komunikat i zamyka program
	if(size == 0 || index > size-1) {
		std::cerr << "Bład! Indeks operatora[] jest poza zakresem" <<std::endl;
		exit(EXIT_FAILURE);
	}
	return tab[index];
}


int& DArray::operator [](unsigned int index) {

// zabezpiecznie przed wyjściem poza zakres, wyświetla komunikat i zamyka program
	if(size == 0 || index > size-1) {
		std::cerr << "Bład! Indeks operatora[] jest poza zakresem" <<std::endl;
		exit(EXIT_FAILURE); 
	}
	return tab[index];
}


int DArray::showSize(void)const {

	return size;
}

int DArray::showCapacity(void)const {

	return allocatedSize;
}
