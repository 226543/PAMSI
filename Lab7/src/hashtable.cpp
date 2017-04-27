#include "hashtable.hh"

int Hashtable::hash(std::string key) {
  return (int) key[0];
}
