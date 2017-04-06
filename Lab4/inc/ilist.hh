#ifndef ILIST_HH
#define ILIST_HH
#include "node.hh"

class iList {
  public:
  virtual void add(unsigned int position,int value) = 0;
  virtual int remove(unsigned int position) = 0;
  virtual Node* get(unsigned int position) = 0;
  virtual unsigned int size()const = 0;
  virtual bool isEmpty()const = 0;
};

#endif
