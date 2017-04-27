#ifndef HASHTABLE_HH
#define HASHTABLE_HH
#include <iostream>
#include <string>
#include "ihashtable.hh"
#include "entry.hh"
#include "list.hh"

#define SIZE 100

class Hashtable : public Entry, public iHashtable {
  private:
  

  public:
  Hashtable();
  ~Hashtable();
  void add(Entry newEntry);
  int find(std::string requestedEntry);
  int hash(std::string key);
};

#endif
