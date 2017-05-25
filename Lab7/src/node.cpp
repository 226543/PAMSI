#include "node.hh"

std::string Node::getValue() const {
  return value;
}

void Node::setValue(std::string nValue) {
  value = nValue;
}

void Node::setKey(std::string newKey) {
  key = newKey;
}

std::string Node::getKey() const {
  return key;
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
