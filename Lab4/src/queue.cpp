#include <iostream>
#include "queue.hh"

int Queue::size()const {
  return n;
}

bool Queue::isEmpty()const {
  return (n == 0);
}

int Queue::front() {
  if(isEmpty()) {
    std::cout << "Pusta kolejka! " << std::endl;
    exit(EXIT_FAILURE);
  }
  Node temp = *(L.get(1));
  return temp.getValue();
}

void Queue::enqueue(int value) {
  L.addBack(value);
  ++n;
}

int Queue::dequeue() {
  if(isEmpty()) {
    std::cout << "Próbujesz usunąć elelement z pustej kolejki! " << std::endl;
    exit(EXIT_FAILURE);
  }
  return L.removeFront();
}

void Queue::prepareThings(unsigned int amount) {
  for(unsigned int i = 0; i < amount-1; ++i) {
      enqueue(i);
    }
  enqueue(-1);
}

void Queue::doThings(unsigned int amount,int mode) {
  find(-1);
}

void Queue::restart() {
  L.restart();
  n = 0;
}

int Queue::find(int value) {
  int position = 1;
  while(dequeue() != value) {
    ++position;
  }
  return position;
}
