#include <iostream>

#include "time.h"

int minutesSinceMidnight(Time time){
  int hoursToMinutes = 60;
  int timeSince = time.m;
  
  time.h = time.h * hoursToMinutes;
  timeSince += time.h;
  
  return timeSince;
};

int minutesUntil(Time earlier, Time later){
  int minutes = minutesSinceMidnight(later) - minutesSinceMidnight(earlier);
  
  return minutes;
}
