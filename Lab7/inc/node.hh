#ifndef NODE_HH
#define NODE_HH
#include <string>

class Node {
  private:
  std::string key;
  std::string value;
  Node* next;
  Node* prev;

  public:
  Node() : key(""),value(""),next(nullptr),prev(nullptr) {};
  Node (std::string newKey, std::string newValue,
        Node* n = nullptr, Node* p = nullptr) {
    key = newKey;
    value = newValue;
    next = n;
    prev = p;
  }
  std::string getValue() const;
  void setValue(std::string value);

  std::string getKey() const;
  void setKey(std::string newKey);

  Node* getNext();
  Node* getPrev();

  void setNext(Node* N);
  void setPrev(Node* N);
};

#endif
