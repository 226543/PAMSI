#include <iostream>
#include "stack.hh"

bool Stack::isEmpty() {
  return (topElem<0);
}

int Stack::size() {
  return topElem-1;
}


void Stack::push(int value) {
    if(size() == capacity){
      std::cerr << "Stos jest zapełniony" <<std::endl;
      exit(EXIT_FAILURE);
    } else {
      ++topElem;
      tab[topElem];
    }
}

int Stack::pop() {
  if(isEmpty()){
    std::cerr << "Chcesz usunąć z pustego stosu" <<std::endl;
    exit(EXIT_FAILURE);
  } else {
    --topElem;
  }
}

int Stack::top(){
  return topElem;
}

void Stack::doThings(unsigned int amount,int mode) {
	for(unsigned int i = 0; i < amount; ++i) {
		push(i);
	}
}

void Stack::restart() {
	delete [] tab;
	tab = new int[capacity];
	topElem = -1;
}
