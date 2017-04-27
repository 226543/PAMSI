#ifndef ENTRY_HH
#define ENTRY_HH
#include <iostream>
#include <string>

class Entry {
  private:
  std::string key;
  int value;

  public:
  Entry() {
    key = "brak hasla";
    value = 0;
  }

  Entry(std::string name, int nValue) {
    key = name;
    value = nValue;
  }

  int getValue() const;
  void setValue(int value);
  std::string getKey() const;

};

#endif
