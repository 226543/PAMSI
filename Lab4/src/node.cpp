#include "node.hh"

int Node::getValue() {
  return this->value;
}

void Node::setValue(int newValue) {
  value = newValue;
}

Node* Node::getNext() {
  return this->next;
}

Node* Node::getPrev() {
  return this->prev;
}

void Node::setNext(Node* N) {
  next = N;
}

void Node::setPrev(Node* O) {
  prev = O;
}
