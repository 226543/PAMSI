#ifndef TESTER_HH
#define TESTER_HH
#include <iostream>
#include <random>
#include "../inc/measurable.hh"
#include "../inc/tree.hh"


class Tester: public Measurable {
  private:
  RBTree* tree;
  unsigned int toFind;
  public:
  Tester() {
    tree = new RBTree();
  };
  ~Tester() {};

  void prepareThings(unsigned int amount);
  void doThings(unsigned int amount);
  void restart();
};

#endif
