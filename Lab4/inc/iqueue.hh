#ifndef IQUEUE_HH
#define IQUEUE_HH

class iQueue {
  public:
  virtual int size() = 0;
  virtual void enqueue(int value) = 0;
  virtual int dequeue() = 0;
  virtual int front() = 0;
  virtual bool isEmpty() = 0;
};

#endif
