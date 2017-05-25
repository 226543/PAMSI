#ifndef IHASHTABLE_HH
#define IHASHTABLE_HH
#include <string>


class iHashtable {
  public:
  virtual void insert(std::string key, std::string value) = 0;
  virtual std::string find(std::string key) = 0;
  virtual std::string remove(std::string key) = 0;
  ~iHashtable() {};
};

#endif
