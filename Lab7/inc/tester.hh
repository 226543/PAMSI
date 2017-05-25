#ifndef TESTER_HH
#define TESTER_HH
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include "hashtable.hh"
#include "measurable.hh"

class Tester: public Measurable {
  private:
  Hashtable* dictionary = new Hashtable;
  std::ifstream file;
  std::string toFind;
  public:
  Tester() {};
  ~Tester() {
    file.close();
  }

  void prepareThings(unsigned int amount,int mode = 2);
  void doThings(unsigned int amount,int mode = 2);
  void restart();
};

#endif
