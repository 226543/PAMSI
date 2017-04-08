#include <iostream>
#include "assistant.hh"

void Assistant::measure(Measurable &obj,int amountOfData,
                        int numberOfReps,int mode) {
    for(int i = 0; i < numberOfReps; ++i) {
      obj.prepareThings(amountOfData);
      stopwatch1.start();
      obj.doThings(amountOfData,mode);
      stopwatch1.stop();
      results[i] = stopwatch1.result();
      stopwatch1.reset();
      obj.restart();
    }
    std::cout << "Średni czas wykonania to "
              << getAverage(numberOfReps) << std::endl;
}

double Assistant::getAverage(int numberOfReps) {
  double sum;
  for(int i = 0; i < numberOfReps; ++i) {
    sum += results[i];
  }
  return sum/numberOfReps;
}
