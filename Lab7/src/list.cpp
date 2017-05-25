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

void List::addAfter(Node* nodeBefore, std::string key, std::string value) {
  Node* newNode = new Node;
  newNode->setKey(key);
  newNode->setValue(value);
  newNode->setPrev(nodeBefore);
  newNode->setNext(nodeBefore->getNext());
  (nodeBefore->getNext())->setPrev(newNode);
  nodeBefore->setNext(newNode);
}

void List::addFront(std::string key, std::string value) {
  addAfter(header,key,value);
}

void List::addBack(std::string key, std::string value) {
  addAfter(trailer->getPrev(),key,value);
}

std::string List::removeFront() {
  std::string removedValue;
  removedValue = removeNode(header->getNext());
  return removedValue;
}

std::string List::removeBack() {
  std::string removedValue;
  removedValue = removeNode(trailer->getPrev());
  return removedValue;
}

std::string List::removeNode(Node* nodeToRemove) {
  std::string temp;
  Node* nodeBefore = nodeToRemove->getPrev();
  Node* nodeAfter = nodeToRemove->getNext();
  temp = nodeToRemove->getKey();

  nodeBefore->setNext(nodeAfter);
  nodeAfter->setPrev(nodeBefore);

  delete nodeToRemove;

  return temp;
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

void List::add(unsigned int position,std::string key, std::string value) {
  if(position == 1) {
    addFront(key,value);
  }
  else if(position == size()+1) {
    addBack(key,value);
  }
  else if(position > size()+1 || position <= 0) {
    std::cout << "Chcesz dodać element poza listą! \n";
    exit(EXIT_FAILURE);
  }
  else {
    addAfter(get(position),key,value);
  }
}
std::string List::remove(unsigned int position) {
  std::string result = 0;
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
    result = removeNode(get(position));
  }
  return result;
}

 bool List::removeElem(std::string key) {
  Node* temp = header->getNext();
  std::string removedKey;
  while(temp != trailer) {
    if(temp->getKey() == key) {
      Node* nodeBefore = temp->getPrev();
      Node* nodeAfter = temp->getNext();
      removedKey = temp->getKey();

      nodeBefore->setNext(nodeAfter);
      nodeAfter->setPrev(nodeBefore);

      delete temp;
      return true;
    }
  }
  std::cerr << "NIE MA TAKIEGO ELEMENTU!\n";
  return false;
}

std::string List::find(std::string wKey) {
  Node* temp = header->getNext();
  bool notFound = true;
  std::string keyValue;

  while(temp != trailer && notFound ) {
    if(temp->getKey() == wKey) {
      keyValue = temp->getValue();
      notFound = false;
    }
    else {
    temp = temp->getNext();
  }
  }
  if(notFound) {
    std::cout << "Nie znaleziono tego elementu w liście! Zwracam pierwszy" << std::endl;
    return (header->getNext())->getValue();
  }
  return keyValue;
}

void List::restart() {
  while(!isEmpty()) {
    removeBack();
  }
}
