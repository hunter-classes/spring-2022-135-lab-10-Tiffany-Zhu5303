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
  /*Time *newTime;

    newTime = new Time;*/

  //convert given time to minutes
  int minutes = minutesSinceMidnight(time0);
  minutes += min;

  //convert time back to hours
  int hours = minutes / 60;
  time0.h = hours;

  //get the minutes from remainder
  time0.m = minutes % 60;

  return time0;
}
