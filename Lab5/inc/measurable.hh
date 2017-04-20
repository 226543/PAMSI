#ifndef MEASURABLE_HH
#define MEASURABLE_HH

class Measurable {
  public:
  virtual void prepareThings(unsigned int amount,int mode) = 0;
  virtual void doThings(unsigned int amount,int mode) = 0;
  virtual void restart() = 0;
  virtual ~Measurable(){};
};

#endif
