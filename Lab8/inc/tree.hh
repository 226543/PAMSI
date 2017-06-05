#ifndef TREE_HH
#define TREE_HH
#include "ibinarytree.hh"

enum Color {red,black};

class Node {
  private:
  int val;
  Color colour;
  Node* parent;
  Node* left;
  Node* right;

  public:
  Node (int newValue): val {newValue}, colour {black}, parent {nullptr} , left{nullptr}, right{nullptr} {}

  int getValue()const;
  void setValue(int newValue);

  Node* getParent()const;
  void setParent(Node* newParent);

  Node* getLeft()const;
  void setLeft(Node* newLeft);

  Node* getRight()const;
  void setRight(Node* newRight);

  Color getColour()const;
  void setColour(Color newColour);
};

class RBTree: public IBinaryTree {
  private:
  Node* sentinel;
  Node* root;
  void fixTree(Node *node);

  public:
  RBTree() {
    sentinel = new Node(0);
    sentinel -> setParent(sentinel);
    sentinel -> setLeft(sentinel);
    sentinel -> setRight(sentinel);
    root = sentinel;
  }

  virtual ~RBTree() {
    removeNode(root);
    delete sentinel;
  }

  Node* getRoot();
  void leftRotate(Node* rNode);
  void rightRotate(Node* rNode);
  void insert(int newValue);
  bool search (int value);
  void print(Node* node);
  void removeNode(Node* node);
  Node* getMin (Node* x);
  Node* getMax (Node* x);
};

#endif
