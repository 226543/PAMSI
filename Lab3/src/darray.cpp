#include <iostream>
#include "darray.hh"


void DArray::expandTab1() {
	int *tempTab = new int[1+size];

	// kopiowanie starej tablicy do nowej
	for(unsigned int i = 0; i<=size-1; ++i) {
		tempTab[i] = tab[i];
	}
	delete [] tab;
	tab = tempTab;
}

void DArray::expandTab2() {
	int *tempTab = new int[2*size];

	// kopiowanie starej tablicy do nowej
	for(unsigned int i = 0; i<=size-1; ++i) {
		tempTab[i] = tab[i];
	}
	delete [] tab;
	tab = tempTab;
}

void DArray::shrinkTab1() {
	int *tempTab = new int[size-1];

	// kopiowanie starej tablicy do nowej
	for(unsigned int i = 0; i<=size-1; ++i) {
		tempTab[i] = tab[i];
	}
	delete [] tab;
	tab = tempTab;
}

void DArray::shrinkTab2() {
	int *tempTab = new int[size/2];

	// kopiowanie starej tablicy do nowej
	for(unsigned int i = 0; i<=size-1; ++i) {
		tempTab[i] = tab[i];
	}
	delete [] tab;
	tab = tempTab;
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

void DArray::delElem1() {
	if(size > 0) {
		shrinkTab1();
		allocatedSize -=1;
		--size;
	}
	else {
		std::cerr << "Próbujesz usunąć element z pustej tablicy" << std::endl;
	}
}

void DArray::delElem2() {
	if(size == 0) {
		std::cerr << "Próbujesz usunąć element z pustej tablicy" << std::endl;
	}
	else if(size <= allocatedSize/2) {
		shrinkTab2();
		allocatedSize /=2;
		--size;
	}
	else {
		--size;
	}
}


void DArray::displayTab()const {
	if(size > 0){
		for(unsigned int i = 0; i <= size-1; ++i) {
			std::cout << tab[i] << " ";
		}
	}
	else {
		std::cerr<<"Pusta Tablica"<<std::endl;
	}
	std::cout << std::endl;
}



int DArray::operator [](unsigned int index)const {
// zabezpiecznie przed wyjściem poza zakres, wyświetla komunikat i zamyka program
	if((int)index > (int)size-1) {
		std::cerr << "Bład! Indeks operatora[] jest poza zakresem" <<std::endl;
		exit(EXIT_FAILURE);
	}
	return tab[index];
}


int& DArray::operator [](unsigned int index) {
// zabezpiecznie przed wyjściem poza zakres, wyświetla komunikat i zamyka program
	if((int)index > (int)size-1) {
		std::cerr << "Bład! Indeks operatora[] jest poza zakresem" <<std::endl;
		exit(EXIT_FAILURE);
	}
	return tab[index];
}


int DArray::showSize()const {
	return size;
}

int DArray::showCapacity()const {
	return allocatedSize;
}

void DArray::doThings(int mode,unsigned int amount) {
	if(mode == 1) {
		for(unsigned int i = 0; i < amount; ++i) {
			addElem1(i);
		}
	}
	else if(mode == 2) {
		for(unsigned int i = 0; i < amount; ++i) {
			addElem2(i);
		}
	}
	else {
		std::cout << "Wybrano złą metodę" << std::endl;
	}
}
