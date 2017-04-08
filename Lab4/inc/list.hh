#ifndef LIST_HH
#define LIST_HH
#include "ilist.hh"
#include "measurable.hh"

class List : public iList, public Measurable {
  private:
  Node* header = new Node();
  Node* trailer = new Node();

  public:
  List() {
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
  int removeElem(Node* nodeToRemove);
  int removeFront();
  int removeBack();

  void prepareThings(unsigned int amount);
  void doThings(unsigned int amount,int mode = 0);
  void restart();
  int find(int numb);
};

#endif
