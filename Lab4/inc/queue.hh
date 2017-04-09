#ifndef QUEUE_HH
#define QUEUE_HH
#include "iqueue.hh"
#include "list.hh"
#include "measurable.hh"


class Queue : public iQueue, public Measurable {
  private:
  List L;
  int n;

  public:
  Queue() {
    n = 0;
  }
  ~Queue() {}

  int size()const;
  bool isEmpty()const;

  int front();
  void enqueue(int value);
  int dequeue();

  void prepareThings(unsigned int amount);
  void doThings(unsigned int amount,int mode = 0);
  void restart();
  int find(int numb);
};

#endif
