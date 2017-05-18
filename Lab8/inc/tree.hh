#ifndef TREE_HH
#define TREE_HH


class Node {
  private:
  int val;
  Node* parent;
  Node* left;
  Node* right;

  public:
  Node(): value(0),parent(nullptr),left(nullptr),right(nullptr) {}
  ~Node();
  int getValue()const;
  void setValue(int newValue);

  Node* getParent()const;
  void setParent(Node* newParent);

  Node* getLeft()const;
  void setLeft(Node* newLeft);

  Node* getRight()const;
  void setRight(Node* newRight);
};

class BinaryTree {
  private:
  int size;
  Node* root;

  public:
  BinaryTree(): size(0), root(nullptr) {}
  ~BinaryTree();
  void insert(int value);
  Node* findParent(Node* son);
}

#endif
