#ifndef IQUEUE_HH
#define IQUEUE_HH

class iQueue {
  public:
  virtual int size()const = 0;
  virtual void enqueue(int value) = 0;
  virtual int dequeue() = 0;
  virtual int front() = 0;
  virtual bool isEmpty()const = 0;
};

#endif
