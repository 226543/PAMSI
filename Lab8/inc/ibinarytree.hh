#ifndef IBINARYTREE
#define IBINARYTREE
#include "tree.hh"

class IBinaryTree {
  public:
  virtual void insert(int value) = 0;
  virtual bool search (int value) = 0;
};

#endif
