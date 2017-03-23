#include <iostream>
#include "assistant.hh"

void Assistant::measure(Measurable &obj,int amountOfData,
                        int numberOfReps,int mode){
    for(int i = 0; i < numberOfReps; ++i){
      stopwatch1.start();
      obj.doThings(amountOfData,mode);
      stopwatch1.stop();
      results[i] = stopwatch1.result();
      stopwatch1.reset();
      obj.restart();
    }
    std::cout << calcAverage(numberOfReps);
}

double Assistant::calcAverage(int numberOfReps){
  double sum;
  for(int i = 0; i < numberOfReps; ++i){
    sum += results[i];
  }
  return sum/numberOfReps;
}
