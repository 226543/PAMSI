#ifndef ILIST_HH
#define ILIST_HH
#include <string>
#include "node.hh"

class iList {
  public:
  virtual void add(unsigned int position,) = 0;
  virtual std::string remove(unsigned int position) = 0;
  virtual Node* get(unsigned int position) = 0;
  virtual unsigned int size()const = 0;
  virtual bool isEmpty()const = 0;
};

#endif
