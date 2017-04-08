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

  int size() const;
  bool isEmpty() const;

  void push(int value);
  int pop();
  int top();

  void prepareThings(unsigned int amount);
  void doThings(unsigned int amount,int mode = 0);
  void restart();

  void find(int i);
};

#endif
