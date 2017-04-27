#ifndef IHASHTABLE_HH
#define IHASHTABLE_HH
#include <iostream>
#include <string>
#include "entry.hh"

class iHashtable : public Entry {
  public:
  virtual void add(Entry newEntry) = 0;
  virtual int find(std::string requestedEntry) = 0;
  ~iHashtable() {};
};

#endif
