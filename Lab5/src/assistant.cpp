#include <iostream>
#include "assistant.hh"
#include <cstdlib>

void Assistant::measure(Measurable &obj, int amountOfData,
                        int numberOfReps, int mode1,
                        int mode2) {
    std::srand(time(NULL));
    for(int i = 0; i < numberOfReps; ++i) {
      obj.prepareThings(amountOfData,mode1);
      stopwatch1.start();
      obj.doThings(amountOfData,mode2);
      stopwatch1.stop();
      results[i] = stopwatch1.result();
      stopwatch1.reset();
      obj.restart();
    }
    std::cout << "Średni czas wykonania to "
              << getAverage(numberOfReps) << std::endl;
}

double Assistant::getAverage(int numberOfReps) {
  double sum = 0;

  for(int i = 0; i < numberOfReps; ++i) {
    sum += results[i];
  }
  return sum/numberOfReps;
}
