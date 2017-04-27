#ifndef NODE_HH
#define NODE_HH
#include <iostream>

class Node {
  private:
  int value;
  Node* next;
  Node* prev;

  public:
  Node() : value(0),next(nullptr),prev(nullptr) {};
  Node (int values, Node* n, Node* p) {
    value = values;
    next = n;
    prev = p;
  }
  int getValue();
  void setValue(int newValue);

  Node* getNext();
  Node* getPrev();
  void setNext(Node* N);
  void setPrev(Node* N);
};

#endif
