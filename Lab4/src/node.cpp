#include "node.hh"

int Node::getValue() {
  return value;
}

void Node::setValue(int newValue) {
  value = newValue;
}

Node* Node::getNext() {
  return next;
}

Node* Node::getPrev() {
  return prev;
}

void Node::setNext(Node* N) {
  next = N;
}

void Node::setPrev(Node* O) {
  prev = O;
}
