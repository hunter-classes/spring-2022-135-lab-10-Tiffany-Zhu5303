#include <iostream>
#include <string>

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

void printMovie(Movie mv){
  std::string g;
  switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
  std::cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

std::string GetTimeSlot(TimeSlot ts){
  printMovie(ts.movie);
  std::cout << " ";

  std::string printTime = "[starts at ";
  printTime += std::to_string(ts.startTime.h) + ":";

  if(ts.startTime.m == 0){
    printTime += "00";
  }else{
    printTime += std::to_string(ts.startTime.m);
  }

  //calculate ending time
  Time ending = ts.startTime;
  int minutes = minutesSinceMidnight(ending);

  Movie MOVIE;
  
  minutes += MOVIE.duration;
  ending = {0, 0};
  
  ending = addMinutes(ending, minutes);
  printTime += ", ends by " + std::to_string(ending.h) + ":";

  if(ending.m == 0){
    printTime += "00]";
  }else{
    printTime += std::to_string(ending.m) + "]";
  }

  return printTime;
}
