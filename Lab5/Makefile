G = g++
GFLAGS = -Wall -pedantic -g -std=c++11 -Iinc

__start__: zad
	./zad

obj: mkdir obj

zad: obj/main.o obj/darray.o
	$(G) $(GFLAGS) ./obj/main.o ./obj/darray.o -o zad

obj/main.o: src/main.cpp
	$(G) $(GFLAGS) -c ./src/main.cpp -o ./obj/main.o

obj/darray.o: src/darray.cpp inc/darray.hh
	$(G) $(GFLAGS) -c ./src/darray.cpp -o ./obj/darray.o

clean:
	rm -fr ./obj/*.o zad
