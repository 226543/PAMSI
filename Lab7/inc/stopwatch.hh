#ifndef STOPWATCH_HH
#define STOPWATCH_HH
#include <sys/time.h>

class Stopwatch {
  private:
  struct timeval startTime;
  struct timeval endTime;

  public:
  void start();
  void stop();
  void reset();
  double result();
};

#endif
