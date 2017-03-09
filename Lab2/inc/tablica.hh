#ifndef TABLICA_HH
#define TABLICA_HH

#define size 5

class Tablica{

	private:

	int *tab;
	unsigned int rozmiar;

	void powiekszTab(void);
	void pomniejszTab(void);

	public:
	Tablica(){
		tab = new int[size];
		rozmiar = 0;
	}

	~Tablica(){
		delete []tab;	
	}

	

	void dodajElement(int wartosc);
	void usunElement(int wartosc);
	void wyswietlTablice(void);
};
#endif