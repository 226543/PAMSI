#include <iostream>
#include "darray.hh"


void DArray::expandTab1(void) {

	int *tempTab = new int[1+size];

	// kopiowanie starej tablicy do nowej
	for(unsigned int i = 0; i<=size-1; ++i) {
		tempTab[i] = tab[i];
	} 
	delete [] tab;
	tab = tempTab;
}

void DArray::expandTab2(void) {

	int *tempTab = new int[2*size];

	// kopiowanie starej tablicy do nowej
	for(unsigned int i = 0; i<=size-1; ++i) {
		tempTab[i] = tab[i];
	} 
	delete [] tab; 
	tab = tempTab;
}

void DArray::shrinkTab1(void) {

	int *tempTab = new int[size-1];

	// kopiowanie starej tablicy do nowej
	for(unsigned int i = 0; i<=size-1; ++i) {
		tempTab[i] = tab[i];
	} 
	delete [] tab;
	tab = tempTab;
}

void DArray::shrinkTab2(void) {

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

void DArray::delElem1(void) {

	if(size > 0) {
		shrinkTab1();
		allocatedSize -=1;
		--size;
	}
	else {
		std::cout << "Próbujesz usunąć element z pustej tablicy" << std::endl;
	}
}

void DArray::delElem2(void) {

	if(size == 0) {
		std::cout << "Próbujesz usunąć element z pustej tablicy" << std::endl;
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


void DArray::displayTab(void)const {

	if(size > 0){
		for(unsigned int i = 0; i <= size-1; ++i) {
			std::cout << tab[i] << " ";
		}
	}
	else {
		std::cout<<"Pusta Tablica"<<std::endl;
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


int DArray::showSize(void)const {

	return size;
}

int DArray::showCapacity(void)const {

	return allocatedSize;
}
