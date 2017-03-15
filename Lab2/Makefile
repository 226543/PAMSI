G = g++
GFLAGS = -Wall -pedantic -g -std=c++11 -Iinc

__start__: tab
	./tab
	
obj: mkdir obj
	
tab: obj/darray.o src/main.cpp inc/darray.hh
	$(G) $(GFLAGS) ./obj/darray.o ./src/main.cpp -o tab

obj/darray.o: src/darray.cpp inc/darray.hh
	$(G) $(GFLAGS) -c ./src/darray.cpp -o ./obj/darray.o

clean:
	rm -fr ./obj/*.o tab
