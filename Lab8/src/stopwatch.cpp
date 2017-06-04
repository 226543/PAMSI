#include <iostream>
#include "../inc/stopwatch.hh"

void Stopwatch::start() {
  gettimeofday(&startTime, NULL);
}

void Stopwatch::stop() {
  gettimeofday(&endTime, NULL);
}

void Stopwatch::reset() {
  startTime.tv_usec = 0;
  startTime.tv_sec = 0;
  endTime.tv_usec = 0;
  endTime.tv_sec = 0;
}

double Stopwatch::result(){
  double duration;
  duration = (endTime.tv_sec - startTime.tv_sec) * 1000.0;      // sec to ms
  duration += (endTime.tv_usec - startTime.tv_usec) / 1000.0;   // us to ms
  return duration;
}
