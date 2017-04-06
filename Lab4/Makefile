G = g++
GFLAGS = -Wall -pedantic -g -std=c++11 -Iinc

__start__: tab
	./tab

obj: mkdir obj

tab: obj/main.o obj/measurable.o obj/stopwatch.o obj/darray.o obj/assistant.o obj/stack.o obj/node.o obj/list.o
	$(G) $(GFLAGS) ./obj/main.o ./obj/measurable.o ./obj/stopwatch.o ./obj/darray.o ./obj/assistant.o ./obj/stack.o ./obj/node.o ./obj/list.o -o tab

obj/main.o: src/main.cpp
	$(G) $(GFLAGS) -c ./src/main.cpp -o ./obj/main.o

obj/assistant.o: src/assistant.cpp inc/assistant.hh
	$(G) $(GFLAGS) -c ./src/assistant.cpp -o ./obj/assistant.o

obj/darray.o: src/darray.cpp inc/darray.hh
	$(G) $(GFLAGS) -c ./src/darray.cpp -o ./obj/darray.o

obj/stack.o: src/stack.cpp inc/stack.hh inc/istack.hh
	$(G) $(GFLAGS) -c ./src/stack.cpp -o ./obj/stack.o

obj/list.o: src/list.cpp inc/list.hh inc/ilist.hh inc/node.hh
	$(G) $(GFLAGS) -c ./src/list.cpp -o ./obj/list.o

obj/node.o: src/node.cpp inc/node.hh
	$(G) $(GFLAGS) -c ./src/node.cpp -o ./obj/node.o

obj/stopwatch.o: src/stopwatch.cpp inc/stopwatch.hh
	$(G) $(GFLAGS) -c ./src/stopwatch.cpp -o ./obj/stopwatch.o

obj/measurable.o: src/measurable.cpp inc/measurable.hh
	$(G) $(GFLAGS) -c ./src/measurable.cpp -o ./obj/measurable.o

clean:
	rm -fr ./obj/*.o tab
