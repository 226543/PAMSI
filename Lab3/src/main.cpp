#include <iostream>
#include "darray.hh"
#include "assistant.hh"

using namespace std;

int main() {
	Assistant helper;
	DArray tab;

	helper.measure(tab,100000,20,1);

	return 0;
}
