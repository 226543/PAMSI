G = g++
GFLAGS = -Wall -pedantic -g -std=c++11 -Iinc

__start__: zad
	./zad

zad: obj/main.o obj/tree.o obj/assistant.o obj/measurable.o obj/tester.o obj/stopwatch.o
	$(G) $(GFLAGS) ./obj/main.o ./obj/tree.o ./obj/assistant.o ./obj/measurable.o ./obj/tester.o ./obj/stopwatch.o -o zad

obj/main.o: src/main.cpp
	$(G) $(GFLAGS) -c ./src/main.cpp -o ./obj/main.o

obj/tree.o: src/tree.cpp inc/tree.hh inc/ibinarytree.hh
	$(G) $(GFLAGS) -c ./src/tree.cpp -o ./obj/tree.o

obj/assistant.o: src/assistant.cpp inc/assistant.hh
	$(G) $(GFLAGS) -c ./src/assistant.cpp -o ./obj/assistant.o

obj/measurable.o: src/measurable.cpp inc/measurable.hh
	$(G) $(GFLAGS) -c ./src/measurable.cpp -o ./obj/measurable.o

obj/tester.o: src/tester.cpp inc/tester.hh
	$(G) $(GFLAGS) -c ./src/tester.cpp -o ./obj/tester.o

obj/stopwatch.o: src/stopwatch.cpp inc/stopwatch.hh
	$(G) $(GFLAGS) -c ./src/stopwatch.cpp -o ./obj/stopwatch.o

clean:
	rm -fr ./obj/*.o zad
