#ifndef LIST_HH
#define LIST_HH
#include "ilist.hh"
#include "measurable.hh"

class List : public iList, public Measurable {
  private:
  Node* header;
  Node* trailer;

  public:
  List() {
    Node* header = new Node;
    Node* trailer = new Node;
    header->setNext(trailer);
    trailer->setPrev(header);

  }
  ~List();

  Node* get(unsigned int position);
  void add(unsigned int position,int value);
  int remove(unsigned int position);
  unsigned int size()const;
  bool isEmpty()const;

  void addFront(int value);
  void addBack(int value);
  void addAfter(Node* nodeBefore,int value);
  int removeBefore(Node* nodeToRemove);
  int removeFront();
  int removeBack();

  void doThings(unsigned int amount,int mode = 0);
  void restart();
};

#endif
