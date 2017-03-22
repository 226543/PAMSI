#include <iostream>
#include "darray.hh"
#include "stopwatch.hh"

using namespace std;

int main() {
	Stopwatch stoper;
	DArray tab(10);
	stoper.start();
	tab.doThings(1,10000);
	stoper.stop();
	cout << "Czas to " << stoper.result() << endl;
	cout << "Pamięć zarezewowana na " << tab.showCapacity() << " elementów\n"
			 << "Tablica ma " << tab.showSize() << " elementów." << endl;

	return 0;
}
