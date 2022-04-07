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

Time addMinutes(Time time0, int min){
  int minutes = minutesSinceMidnight(time0);
  minutes += min;

  int hours = minutes / 60;
  time.h = hours;

  hours = minutesSinceMidnight(hours);
  time.m = minutes - hours;
  
}
