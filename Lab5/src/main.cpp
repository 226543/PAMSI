#include <iostream>
#include "darray.hh"

using namespace std;

DArray quickSort(DArray tab,int left, int right) {
	int temp;
	int i = left;
	int j = right;

	int pivot = tab[tab.showSize()-1];
	while(i <= j) {
		while(tab[i] < pivot) {
			++i;
		}
		while(tab[j] > pivot) {
			--j;
		}
		if(i <= j) {
			temp = tab[i];
			tab[i] = tab[j];
			tab[j] = temp;
			++i;
			--j;
		}
	}
	if(left < j) {
		quickSort(tab,left,j);
	}
	if(i < right) {
		quickSort(tab,i,right);
	}
	return tab;
}


int main() {

	DArray tab(10);
	for(int i = 0; i <= 10; ++i) {
		tab = i;
	}
	quickSort(tab,0,tab.showSize()-1);

	return 0;
}
