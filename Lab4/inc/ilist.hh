#ifndef ILIST_HH
#define ILIST_HH

class iList {
  public:
  virtual void add(unsigned int position,int value) = 0;
  virtual int remove(int position) = 0;
  virtual int get(unsigned int position) = 0;
  virtual int size() = 0;
};

#endif
