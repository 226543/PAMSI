#include <iostream>
#include "../inc/tree.hh"

int Node::getValue()const {
  return val;
}

void Node::setValue(int newValue) {
  val = newValue;
}

Node* Node::getParent()const {
  return parent;
}

void Node::setParent(Node* newParent) {
  parent = newParent;
}

Node* Node::getLeft()const {
  return left;
}

void Node::setLeft(Node* newLeft) {
  left = newLeft;
}

Node* Node::getRight()const {
  return right;
}

void Node::setRight(Node* newRight) {
  right = newRight;
}

Color Node::getColour()const {
  return colour;
}

void Node::setColour(Color newColour) {
  colour = newColour;
}

Node* RBTree::getRoot() {
  return root;
}

void RBTree::leftRotate(Node* x) {
  Node* y = x->getRight();
  x->setRight( y->getLeft() );

  if (y->getLeft() != sentinel) {
    y->getLeft()->setParent(x);
  }

  y->setParent( x->getParent() );

  if (x->getParent() == sentinel) {
    root = y;
  }
  else if (x == (x->getParent())->getLeft()) {
    x->getParent()->setLeft(y);
  }
  else {
    x->getParent()->setRight(y);
  }

  y->setLeft(x);
  x->setParent(y);
}

void RBTree::rightRotate(Node* x) {
  Node* y = x->getLeft();
  x->setLeft( y->getRight() );

  if (y->getRight() != sentinel) {
    y->getRight()->setParent(x);
  }

  y->setParent( x->getParent() );

  if (x->getParent() == sentinel) {
    root = y;
  }
  else if (x == (x->getParent())->getRight()) {
    x->getParent()->setRight(y);
  }
  else {
    x->getParent()->setLeft(y);
  }

  y->setRight(x);
  x->setParent(y);
}


void RBTree::insert(int newValue) {
  Node* z = new Node(newValue);
  Node* x = root;
  Node* y = sentinel;
  z ->setLeft(sentinel);
  z ->setRight(sentinel);
  z ->setColour(red);

  while (x != sentinel) {
    y = x;
    if (newValue < x->getValue()) {
      x = x->getLeft();
    }
    else {
      x = x->getRight();
    }
  }

  z->setParent(y);

  if (y == sentinel) {
    root = z;
    root->setRight(sentinel);
    root->setLeft(sentinel);
  }
  else if (newValue < y->getValue()) {
      y->setLeft(z);
  }
  else {
    y->setRight(z);
  }
  fixTree(z);
}

void RBTree::fixTree(Node* x) {
  while (x->getParent()->getColour() == red) {
		if (x->getParent() == x->getParent()->getParent()->getLeft()) {
      Node *y = x->getParent()->getParent()->getRight();
      // przypadek 1
      if (y->getColour() == red) {
        x->getParent()->setColour(black);
        y->setColour(black);
        x->getParent()->getParent()->setColour(red);
        x = x->getParent()->getParent();
      } // przypadek 2
      else {
        if (x == x->getParent()->getRight()) {
          x = x->getParent();
          leftRotate(x);
        }
        // przypadek 3
        x->getParent()->setColour(black);
        x->getParent()->getParent()->setColour(red);
        rightRotate(x->getParent()->getParent());
      }
    }
    else {
      Node* y = x->getParent()->getParent()->getLeft();
      // przypadek 1
      if (y->getColour() == red) {
        x->getParent()->setColour(black);
        y->setColour(black);
        x->getParent()->getParent()->setColour(red);
        x = x->getParent()->getParent();
      } // przypadek 2
      else {
        if (x == x->getParent()->getLeft())  {
          x = x->getParent();
          rightRotate(x);
        }

        // przypadek 3
        x->getParent()->setColour(black);
        x->getParent()->getParent()->setColour(red);
        leftRotate(x->getParent()->getParent());
      }
    }
  }
  root->setColour(black);
}



bool RBTree::search (int value) {
  bool found = false;
  Node* current = root;
  if (root == sentinel) {
    std::cerr << "Próbujesz wyszukać element w pustym drzewie\n";
    return false;
  }
  while (found==false && current != sentinel) {
    if (current->getValue() == value) {
      found = true;
    }
    if (found==false) {
      if (current->getValue() > value) {
        current = current->getLeft();
      }
      else {
        current = current->getRight();
      }
    }
  }
  if (found == true) {
    //std::cout << std::endl <<"Znaleziono element!\n";
    return true;
  }
  else {
    std::cout << std::endl <<"Nie znaleziono elementu!\n";
    return false;
  }
}

void RBTree::print(Node* node) {
  if (node == sentinel)
    return;
  print(node->getLeft());
  std::cout << node->getValue() << " ";
  print(node->getRight());
}

void RBTree::removeNode (Node* node) {
  if(node != sentinel && node != root) {
    removeNode(node->getLeft());
    removeNode(node->getRight());
    delete node;
  }
  root = sentinel;
}

Node* RBTree::getMin (Node* x) {
  while (x->getLeft() != sentinel) {
    x = x->getLeft();
  }
  return x;
}

Node* RBTree::getMax (Node* x) {
  while (x->getRight() != sentinel) {
    x = x->getRight();
  }
  return x;
}
