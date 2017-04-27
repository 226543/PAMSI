#include "entry.hh"

int Entry::getValue() const {
  return value;
}

void Entry::setValue(int nValue) {
  value = nValue;
}

std::string Entry::getKey() const {
  return key;
}
