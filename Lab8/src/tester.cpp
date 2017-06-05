#include "../inc/tester.hh"
#include <iostream>

void Tester::prepareThings(unsigned int amount) {
  unsigned int newValue;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, amount);

  for(unsigned int i = 0; i < amount; ++i) {
    newValue = dis(gen);
		tree->insert(newValue);
  }
  // przypisanie wartości największego elementu w drzewie do zmiennej toFind
  toFind = (tree->getMax( tree->getRoot()) )->getValue();
}

void Tester::doThings(unsigned int amount) {
  tree->search(toFind);
}

void Tester::restart() {
  tree->removeNode( tree->getRoot() );
}
