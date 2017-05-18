#include "tree.hh"

int Node::getValue()const {
  return value;
}
void Node::setValue(int newValue){
  value = newValue;
}

Node* Node::getParent()const {
  return parent;
}

void Node::setParent(Node* newParent) {
  Node* temp = parent;
  parent = newParent;
  delete temp;
}

Node* Node::getLeft()const {
  return left;
}

void Node::setLeft(Node* newLeft) {
  Node* temp = left;
  left = newLeft;
  delete temp;
}

Node* Node::getRight()const {
  return right;
}

void Node::setRight(Node* newRight) {
  Node* temp = right;
  right = newRight;
  delete temp;
}

Node* Tree::findParent(Node* son) {
  if(son->getValue() >= root->getValue()) {

  }
}
void Tree::insert(int value) {
  newNode = new Node;
  newNode->setValue(value);
  newNode->setLeft(new Node);
  (newNode->getLeft())->setParent(newNode);
  newNode->setRight(new Node);
  (newNode->getRight())->setParent(newNode);
  size += 2;
  if(root != nullptr) {
    newNode->setParent(findParent());
  }
  else {
    root = newNode;
  }
}
