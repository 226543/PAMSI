#include <iostream>
#include "tablica.hh"

void Tablica::powiekszTab(void){

	int *nowaTab = new int[rozmiar+1];

	// kopiowanie starej tablicy do nowej
	for(unsigned int i = 0; i<=rozmiar-1; ++i){
		nowaTab[i] = tab[i];
	} 
	delete [] tab;
	tab = nowaTab;
}

void Tablica::pomniejszTab(void){

	int *nowaTab = new int[rozmiar-1];

	// kopiowanie starej tablicy do nowej
	for(unsigned int i = 0; i<=rozmiar-1; ++i){
		nowaTab[i] = tab[i];
	} 
	delete [] tab;
	tab = nowaTab;
}

void Tablica::dodajElement(int wartosc){

	if(rozmiar >= size){
		powiekszTab();
	}
	tab[rozmiar] = wartosc;
	++rozmiar;
}

void Tablica::wyswietlTablice(void){

	for(unsigned i = 0; i <= rozmiar-1 ; ++i){
		std::cout << tab[i] << " ";
	}
	std::cout << std::endl;
}
//void Tablica::usunElement(int wartosc);