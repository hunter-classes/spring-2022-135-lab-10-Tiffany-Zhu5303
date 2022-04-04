#include <iostream>

#include "time.h"

int main(){
  Time now = {10, 18};

  std::cout << "--------------------Task A-------------------" << std::endl;
  std::cout << minutesSinceMidnight(now) << std::endl;

  return 0;
}
