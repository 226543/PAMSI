#ifndef LIST_HH
#define LIST_HH
#include <node.hh>
#include <string>

class List {
  private:
  // wskaźnik na pierwszy element listy
  Node* header = new Node;

  // wskaźnik na ostatni element listy
  Node* trailer = new Node;

  public:
  List() {
    header->setNext(trailer);
    trailer->setPrev(header);
  }
  ~List() {
    while(!isEmpty()) {
      removeBack();
    }
    delete trailer;
    delete header;
  }
  // metoda zwraca węzeł, argumentem jest numer węzła (pierwszy węzeł ma numer 1)
  Node* get(unsigned int position);
  void add(unsigned int position, std::string key, std::string value);

  // metoda do usuwania elementów węzła, argumentem jest numer węzła
  std::string remove(unsigned int position);
  unsigned int size()const;
  bool isEmpty()const;

  void addFront(std::string key, std::string value);
  void addBack(std::string key, std::string value);

  // metoda dodaje nowy węzeł za podanym węzłem
  void addAfter(Node* nodeBefore, std::string key, std::string value);
  bool removeElem(std::string key);

  std::string removeNode(Node* nodeToRemove);
  std::string removeFront();
  std::string removeBack();
  std::string find(std::string wKey);

  // metoda usuwająca wszystkie elementy z listy
  void restart();
};

#endif
