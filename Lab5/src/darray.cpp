#include <iostream>
#include <cstdlib>
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

void DArray::prepareThings(unsigned int amount,int mode) {
	if(mode == 1) {
		fillRandomOrder(amount);
	}
	else if(mode == 2) {
		fillIncreasingOrder(amount);
	}
	else if(mode == 3) {
		fillDecreasingOrder(amount);
	}
	else {
		std::cout << "Wybrano złą metodę" << std::endl;
	}
}

void DArray::doThings(unsigned int amount,int mode) {
	if(mode == 1) {  // losowy pivot
		quickSort(0,size-1,mode);
	}
	else if(mode == 2) { // pivot na koncu
		quickSort(0,size-1,mode);
	}
	else if(mode == 3) { // pivot w srodku
		quickSort(0,size-1,mode);
	}
	else {
		std::cout << "Wybrano złą metodę" << std::endl;
	}
}

void DArray::restart() {
	delete [] tab;
	tab = new int[10];
	size = 0;
	allocatedSize = 10;
}

int DArray::getRandom(int a, int b) {
	return std::rand() %(b-a) + a;
}

void DArray::swap (int index1, int index2) {
	int temp = tab[index1];
	tab[index1] = tab[index2];
	tab[index2] = temp;
}

void DArray::fillIncreasingOrder(int amount) {
	for(int i = 0; i < amount; ++i) {
		addElem2(i);
	}
}

void DArray::fillDecreasingOrder(int amount) {
	for(int i = amount; i > 0; --i) {
		addElem2(i);
	}
}

void DArray::fillRandomOrder(int amount) {
	for(int i = 0; i < amount; ++i) {
		addElem2(getRandom(0,amount));
	}
}

int DArray::choosePivot(int t1, int t2, int option) {
	if(option == 1) {
		return getRandom(t1,t2);
	}
	else if(option == 2) {
		return t2;
	}
	else if(option == 3) {
		return (t1+t2)/2;
	}
	else {
		std::cout << "Wybrano złą metodę" << std::endl;
		return 0;
	}
}

void DArray::quickSort(int left, int right,int modePivot) {
	int i = left;
	int j = right;
	int index = choosePivot(left, right, modePivot);
	int pivot = tab[index];

	do {
	while(tab[i] < pivot) {
		++i;
	}
	while(tab[j] > pivot) {
		--j;
	}
	if(i <= j) {
		swap(i,j);
		++i;
		--j;
		}
	} while(i <= j)

	if (left < j) {
		quickSort(left, j, modePivot);
	}
	if (right > i) {
		quickSort(i, right, modePivot);
	}
}
