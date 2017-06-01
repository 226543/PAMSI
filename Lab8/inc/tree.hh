#ifndef TREE_HH
#define TREE_HH

enum Color {red,black};

class Node {
  private:
  int val = 0;
  Color colour;
  Node* parent;
  Node* left;
  Node* right;

  public:
  Node (int newValue): val {newValue}, colour {red}, parent {nullptr} , left{nullptr}, right{nullptr} {}

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

class RBTree {
  private:
  Node* root;

  void fixTree(Node *node);
  public:
  RBTree() {
    root = nullptr;
  }

  ~RBTree() {
    //delete root;
  }

  Node* getRoot();
  void leftRotate(Node* rNode);
  void rightRotate(Node* rNode);
  void insert(int newValue);
  bool search (int value);

};

#endif
