#include <iostream>
#include <sys/time.h> 
#include "darray.hh"

using namespace std;

int main() {

	DArray tab;
	struct timeval startTime, endTime;
        double duration;
    
        gettimeofday(&startTime, NULL);

	for(unsigned int i = 0; i<1000000; ++i) {
		tab.addElem2(1);
	};
	
	gettimeofday(&endTime, NULL);

	duration = (endTime.tv_sec - startTime.tv_sec) * 1000.0;      // sec to ms
        duration += (endTime.tv_usec - startTime.tv_usec) / 1000.0;   // us to ms

<<<<<<< HEAD
    cout << duration << " ms \n";
    cout << tab.showSize() << endl << tab.showCapacity() << endl;
	
	return 0;
} 
=======
        cout << duration << " ms \n";
	
	return 0;
}
>>>>>>> 8f6269d917e74bd8ab6583df1ba030b7b8ae8cf3
