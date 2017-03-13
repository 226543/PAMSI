#include <iostream>
#include <sys/time.h> 
#include "darray.hh"

using namespace std;

int main() {

	DArray tab;
	struct timeval startTime, endTime;
    double duration;
    
    gettimeofday(&startTime, NULL);

	for(unsigned int i = 0; i<10000; ++i) {
		tab.addElem2(1);
	};
	
	gettimeofday(&endTime, NULL);

	duration = (endTime.tv_sec - startTime.tv_sec) * 1000.0;      // sec to ms
    duration += (endTime.tv_usec - startTime.tv_usec) / 1000.0;   // us to ms

    cout << duration << " ms \n";
	
	return 0;
}