#include <iostream>

#include "time.h"

int main(){
  Time now = {10, 18};

  std::cout << "--------------------Task A-------------------" << std::endl;
  std::cout << "Hours: " << now.h << "\nMinutes: " << now.m << std::endl;
  std::cout << "The time in minutes since midnight: " << minutesSinceMidnight(now) << std::endl;

  Time later = {10, 46};

  std::cout << "\n\nAfter some time has past\n" << std::endl;
  std::cout << "Hours: " << later.h << "\nMinutes: " << later.m << std::endl;
  std::cout << "It took " << minutesUntil(now, later) << " minutes to get from the first to the second time" << std::endl;

  return 0;
}
