#ifndef ASSISTANT_HH
#define ASSISTANT_HH
#include "stopwatch.hh"
#include "measurable.hh"

class Assistant {
  private:
  double *results; //tablica służąca do przechowywania wyników pomiarów
  Stopwatch stopwatch1;

  double getAverage(int numberOfReps);

  public:
  Assistant() {
    results = new double [20];
  }

  Assistant(int size) {
    results = new double [size];
  }

  ~Assistant() {
    delete [] results;
  }
  
  void measure(Measurable &obj,int amountOfData,int numberOfReps,int mode);
};
#endif
