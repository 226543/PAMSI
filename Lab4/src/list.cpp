#include <iostream>
#include "list.hh"

bool List::isEmpty()const {
  return (header->getNext() == trailer);
}

unsigned int List::size()const {
  Node* temp = trailer;
  unsigned int count = 0;

  while(temp) {
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
  Node* newNode = new Node(value,header,header->getNext());
  (header->getNext())->setNext(newNode);
  header->setNext(newNode);
}

void List::addBack(int value) {
  Node* newNode = new Node;
  newNode->setValue(value);
  newNode->setPrev(trailer->getPrev());
  newNode->setNext(trailer);
  (trailer->getPrev())->setNext(newNode);
  trailer->setPrev(newNode);
}

int List::removeBefore(Node* nodeToRemove) {
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
  removedValue = removeBefore(header->getNext());
  return removedValue;
}

int List::removeBack() {
  int temp = 0;
  Node* nodeToRemove = trailer->getPrev();
  Node* nodeBeforeRemoved = nodeToRemove->getPrev();
  temp = nodeToRemove->getValue();

  nodeBeforeRemoved->setNext(trailer);
  trailer->setPrev(nodeBeforeRemoved);

  delete nodeToRemove;

  return temp;
}

Node* List::get(unsigned int position) {
  Node* temp = header;
  if(position >= size()) {
    std::cout << "Chcesz uzyskac dostep do elementu, ktory nie istnieje! \n";
    exit(EXIT_FAILURE);
  }
  else {
    for(unsigned int i = 0; i <= position; ++i) {
      temp = temp->getNext();
    }
  }
  return temp;
}

void List::add(unsigned int position,int value) {
  if(position == 0) {
    addFront(value);
  }
  else if(position == size()) {
    addBack(value);
  }
  else if(position > size()) {
    std::cout << "Chcesz dodać element poza listą! \n";
    exit(EXIT_FAILURE);
  }
  else {
    addAfter(get(position-1),value);
  }
}

int List::remove(unsigned int position) {
  int result = 0;
  if(position == 0) {
    result = removeFront();
  }
  else if(position == size()) {
    result = removeBack();
  }
  else if(position > size()) {
    std::cout << "Chcesz usunąć element poza listą! \n";
    exit(EXIT_FAILURE);
  }
  else {
    result = removeBefore(get(position));
  }
  return result;
}

void List::doThings(unsigned int amount,int mode) {
for(unsigned int i = 0; i < amount; ++i) {
		addBack(i);
	}
  addBack(-1);
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

void List::find(int numb) {
  Node* temp = header->getNext();
  int counter = 0;
  while(temp != trailer) {
    if(temp->getValue() == numb) {
      std::cout << "Znaleziono " << numb
                << " na " << counter << " pozycji!\n";
    }
    else {
      ++counter;
    }
    temp = temp->getNext();
  }
}
