G = g++
GFLAGS = -Wall -pedantic -g -std=c++11 -Iinc

__start__: zad
	./zad

obj: mkdir obj

zad: obj/main.o obj/tree.o
	$(G) $(GFLAGS) ./obj/main.o ./obj/tree.o -o zad

obj/main.o: src/main.cpp
	$(G) $(GFLAGS) -c ./src/main.cpp -o ./obj/main.o

obj/tree.o: src/tree.cpp inc/tree.hh
	$(G) $(GFLAGS) -c ./src/tree.cpp -o ./obj/tree.o

clean:
	rm -fr ./obj/*.o zad
