#ifndef ISTACK_HH
#define ISTACK_HH

class iStack {
  public:
  virtual int size() = 0;
  virtual void push(int value) = 0;
  virtual int pop() = 0;
  virtual bool isEmpty() = 0;
  virtual int top() = 0;
};

#endif
