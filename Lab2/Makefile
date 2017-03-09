G = g++
GFLAGS = -Wall -pedantic -g -std=c++11 -Iinc

tablica: obj/tablica.o src/main.cpp inc/tablica.hh
	$(G) $(GFLAGS) ./obj/tablica.o ./src/main.cpp -o tablica

obj/tablica.o: src/tablica.cpp inc/tablica.hh
	$(G) $(GFLAGS) -c ./src/tablica.cpp -o ./obj/tablica.o

clean:
	rm -fr ./obj/*.o tablica
