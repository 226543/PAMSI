#include <iostream>
#include "list.hh"

bool List::isEmpty()const {
  return (header->getNext() == trailer);
}

unsigned int List::size()const {
  Node* temp = header->getNext();
  unsigned int count = 0;

  while(temp != trailer) {
    ++count;
    temp = temp->getNext();
  }
  return count;
}

void List::addAfter(Node* nodeBefore,int value) {
  Node* newNode = new Node;
  newNode->setValue(value);
  newNode->setPrev(nodeBefore);
  newNode->setNext(nodeBefore->getNext());
  (nodeBefore->getNext())->setPrev(newNode);
  nodeBefore->setNext(newNode);
}

void List::addFront(int value) {
  addAfter(header,value);
}

void List::addBack(int value) {
  addAfter(trailer->getPrev(),value);
}

int List::removeElem(Node* nodeToRemove) {
  int temp = 0;
  Node* nodeBefore = nodeToRemove->getPrev();
  Node* nodeAfter = nodeToRemove->getNext();
  temp = nodeToRemove->getValue();

  nodeBefore->setNext(nodeAfter);
  nodeAfter->setPrev(nodeBefore);

  delete nodeToRemove;

  return temp;
}

int List::removeFront() {
  int removedValue;
  removedValue = removeElem(header->getNext());
  return removedValue;
}

int List::removeBack() {
  int removedValue;
  removedValue = removeElem(trailer->getPrev());
  return removedValue;
}

Node* List::get(unsigned int position) {
  Node* temp = header;
  if(position > size()) {
    std::cout << "Chcesz uzyskac dostep do elementu, ktory nie istnieje! \n";
    exit(EXIT_FAILURE);
  }
  else {
    for(unsigned int i = 1; i <= position; ++i) {
      temp = temp->getNext();
    }
  }
  return temp;
}

void List::add(unsigned int position,int value) {
  if(position == 1) {
    addFront(value);
  }
  else if(position == size()+1) {
    addBack(value);
  }
  else if(position > size()+1 || position <= 0) {
    std::cout << "Chcesz dodać element poza listą! \n";
    exit(EXIT_FAILURE);
  }
  else {
    addAfter(get(position),value);
  }
}

int List::remove(unsigned int position) {
  int result = 0;
  if(position == 1) {
    result = removeFront();
  }
  else if(position == size()) {
    result = removeBack();
  }
  else if(position > size() || position <= 0) {
    std::cout << "Chcesz usunąć element poza listą! \n";
    exit(EXIT_FAILURE);
  }
  else {
    result = removeElem(get(position));
  }
  return result;
}

void List::prepareThings(unsigned int amount) {
  for(unsigned int i = 0; i < amount-1; ++i) {
  		addBack(i);
  	}
  addBack(-1);
}

void List::doThings(unsigned int amount,int mode) {
  find(-1);
}

void List::restart() {
  while(!isEmpty()) {
    removeBack();
  }
}

List::~List() {
  while(!isEmpty()) {
    removeBack();
  }
  delete trailer;
  delete header;
}

int List::find(int number) {
  Node* temp = header->getNext();
  bool notFound = true;
  int position = 1;

  while(temp != trailer && notFound ) {
    if(temp->getValue() == number) {
      notFound = false;
    }
    else {
      ++position;
    }
    temp = temp->getNext();
  }
  if(notFound) {
    std::cout << "Tej liczby nie ma w liście!" << std::endl;
  }
  return position;
}
