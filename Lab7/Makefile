G = g++
GFLAGS = -Wall -pedantic -g -std=c++14 -Iinc

__start__: zad
	./zad

obj: mkdir obj

zad: obj/main.o  obj/node.o obj/list.o obj/measurable.o obj/assistant.o obj/stopwatch.o obj/hashtable.o obj/tester.o
	$(G) $(GFLAGS) ./obj/main.o ./obj/node.o ./obj/list.o ./obj/measurable.o ./obj/assistant.o ./obj/stopwatch.o ./obj/hashtable.o ./obj/tester.o -o zad

obj/main.o: src/main.cpp
	$(G) $(GFLAGS) -c ./src/main.cpp -o ./obj/main.o

obj/assistant.o: src/assistant.cpp inc/assistant.hh
		$(G) $(GFLAGS) -c ./src/assistant.cpp -o ./obj/assistant.o

obj/measurable.o: src/measurable.cpp inc/measurable.hh
		$(G) $(GFLAGS) -c ./src/measurable.cpp -o ./obj/measurable.o

obj/list.o: src/list.cpp inc/list.hh inc/node.hh
		$(G) $(GFLAGS) -c ./src/list.cpp -o ./obj/list.o

obj/node.o: src/node.cpp inc/node.hh
		$(G) $(GFLAGS) -c ./src/node.cpp -o ./obj/node.o

obj/hashtable.o: src/hashtable.cpp inc/hashtable.hh
	$(G) $(GFLAGS) -c ./src/hashtable.cpp -o ./obj/hashtable.o

obj/tester.o: src/tester.cpp inc/tester.hh
		$(G) $(GFLAGS) -c ./src/tester.cpp -o ./obj/tester.o

obj/stopwatch.o: src/stopwatch.cpp inc/stopwatch.hh
	$(G) $(GFLAGS) -c ./src/stopwatch.cpp -o ./obj/stopwatch.o


clean:
	rm -fr ./obj/*.o zad
