#include "tester.hh"
#include <iostream>

void Tester::prepareThings(unsigned int amount) {
  unsigned int randomNumber;
  unsigned int newValue;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, amount);
  randomNumber = dis(gen);

  for(unsigned int i = 0; i < amount; ++i) {
    newValue = dis(gen);
		tree->insert(newValue);
    if(i == randomNumber) {
      toFind = newValue;
    }
  }
}

void Tester::doThings(unsigned int amount) {
  tree->search(toFind);
}

void Tester::restart() {}
