#ifndef STACK_HH
#define STACK_HH
#include "istack.hh"
#include "measurable.hh"

class Stack : public iStack, public Measurable {
  private:
  int capacity;
  int *tab;
  int topElem;

  public:
  Stack() {
    capacity = 10;
    tab = new int[capacity];
    topElem = -1;
  }
  Stack(int p) {
    capacity = p;
    tab = new int[capacity];
    topElem = -1;
  }
  ~Stack() {
    delete []tab;
  }

  int size();
  bool isEmpty();

  void push(int value);
  int pop();
  int top();

  void doThings(unsigned int amount,int mode = 0);
  void restart();
};

#endif
