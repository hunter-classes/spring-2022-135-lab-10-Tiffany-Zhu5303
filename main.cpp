#include <iostream>

#include "time.h"

int main(){
  Time now = {10, 18};

  std::cout << "--------------------Task A-------------------" << std::endl;
  std::cout << "It is now " << now.h << ":" << now.m << std::endl;
  std::cout << "The time in minutes since midnight: " << minutesSinceMidnight(now) << std::endl;

  Time later = {10, 46};

  std::cout << "\n\nAfter some time has past\n" << std::endl;
  std::cout << "It is now " << later.h << ":" << later.m << std::endl;
  std::cout << "It took " << minutesUntil(now, later) << " minutes to get from the first to the second time" << std::endl;

  std::cout << "\n--------------------Task B-------------------" << std::endl;

  now = {8, 10};
  std::cout << "Start time: {" << now.h << ", " << now.m << "}" << std::endl;
  
  int minutes = 75;
  std::cout << "After " << minutes << " minutes" << std::endl;
  now = addMinutes(now, minutes);
  
  std::cout << "The time now is {" << now.h << ", " << now.m << "}" << std::endl;

  return 0;
}
