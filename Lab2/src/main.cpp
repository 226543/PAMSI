#include <iostream>
#include <sys/time.h> 
#include "darray.hh"

using namespace std;

int main() {

	DArray tab;
	struct timeval startTime, endTime;
    double duration;
    
    gettimeofday(&startTime, NULL);

	for(unsigned int i = 0; i<9992; ++i) {
		tab.addElem2(i);
	};
	
	gettimeofday(&endTime, NULL);

	duration = (endTime.tv_sec - startTime.tv_sec) * 1000.0;      // sec to ms
    duration += (endTime.tv_usec - startTime.tv_usec) / 1000.0;   // us to ms

    cout << "Czas wykonania " << duration << " ms \n";
    cout << "Pamięć zarezewowana na " << tab.showCapacity() << " elementów\n"
         << "Tablica ma " << tab.showSize() << " elementów." << endl;

	return 0;
} 

