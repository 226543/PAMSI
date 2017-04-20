G = g++
GFLAGS = -Wall -pedantic -g -std=c++11 -Iinc

__start__: zad
	./zad

obj: mkdir obj

zad: obj/main.o obj/darray.o obj/stopwatch.o obj/assistant.o obj/measurable.o
	$(G) $(GFLAGS) ./obj/main.o ./obj/darray.o ./obj/stopwatch.o ./obj/assistant.o ./obj/measurable.o  -o zad

obj/main.o: src/main.cpp
	$(G) $(GFLAGS) -c ./src/main.cpp -o ./obj/main.o

obj/darray.o: src/darray.cpp inc/darray.hh
	$(G) $(GFLAGS) -c ./src/darray.cpp -o ./obj/darray.o

obj/stopwatch.o: src/stopwatch.cpp inc/stopwatch.hh
	$(G) $(GFLAGS) -c ./src/stopwatch.cpp -o ./obj/stopwatch.o

obj/assistant.o: src/assistant.cpp inc/assistant.hh
		$(G) $(GFLAGS) -c ./src/assistant.cpp -o ./obj/assistant.o

obj/measurable.o: src/measurable.cpp inc/measurable.hh
		$(G) $(GFLAGS) -c ./src/measurable.cpp -o ./obj/measurable.o

clean:
	rm -fr ./obj/*.o zad
