G = g++
GFLAGS = -Wall -pedantic -g -std=c++11 -Iinc

__start__: zad
	./zad

obj: mkdir obj

zad: obj/main.o obj/entry.o obj/hashtable.o
	$(G) $(GFLAGS) ./obj/main.o ./obj/entry.o ./obj/hashtable.o -o zad

obj/main.o: src/main.cpp
	$(G) $(GFLAGS) -c ./src/main.cpp -o ./obj/main.o

obj/entry.o: src/entry.cpp inc/entry.hh
	$(G) $(GFLAGS) -c ./src/entry.cpp -o ./obj/entry.o

obj/hashtable.o: src/hashtable.cpp inc/hashtable.hh
	$(G) $(GFLAGS) -c ./src/hashtable.cpp -o ./obj/hashtable.o

clean:
	rm -fr ./obj/*.o zad
