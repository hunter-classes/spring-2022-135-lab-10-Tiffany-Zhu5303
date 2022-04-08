#include <iostream>
#include <string>

#include "time.h"
#include "timeslot.h"
#include "movie.h"

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

std::string getTimeSlot(TimeSlot ts){
  printMovie(ts.movie);
  std::cout << " ";

  std::string printTime = "[starts at ";
  if(ts.startTime.h == 0){
    printTime += "00";
  }else{
    printTime += std::to_string(ts.startTime.h) + ":";
  }

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

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
  Time ending = ts.startTime;
  int minutes = minutesSinceMidnight(ending);

  minutes += ts.movie.duration;
  ending = {0, 0};
  
  ending = addMinutes(ending, minutes);
  
  TimeSlot nextOne = {nextMovie, ending};

  return nextOne;
}

bool timeOverLap(TimeSlot ts1, TimeSlot ts2){
  Time end1 = addMinutes(ts1.startTime, ts1.movie.duration);
  Time end2 = addMinutes(ts2.startTime, ts2.movie.duration);

  if(ts1.startTime.h > ts2.startTime.h && ts1.startTime.h <= end2.h){
    return true;
  }else if(ts1.startTime.h = ts2.startTime.h){
    return true;
  }else if(ts1.startTime.h < ts2.startTime.h && end1.h > ts2.startTime.h && end1.h < end2.h){
    return true;
  }else if(ts2.startTime.h > ts1.startTime.h && ts2.startTime.h <= end1.h){
    return true;
  }else{
    return false;
  }
  
}
  
