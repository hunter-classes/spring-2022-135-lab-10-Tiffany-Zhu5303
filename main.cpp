#include <iostream>

#include "time.h"
#include "timeslot.h"
#include "movie.h"

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

  std::cout << "\n--------------------Task C-------------------" << std::endl;
  Movie movie1 = {"Jujutsu Kaisen 0", ACTION, 105};
  Movie movie2 = {"Uncharted", ACTION, 115};
  Movie movie3 = {"Hotel Transylvania: Transformania", COMEDY, 87};
  Movie movie4 = {"Spider-Man: No Way Home", ACTION, 150};
  
  TimeSlot morning = {movie1, {9, 33}};
  TimeSlot lateMorning = {movie3, {10, 19}};
  TimeSlot afternoon = {movie2, {15, 0}};
  TimeSlot evening = {movie4, {19, 15}};
  TimeSlot night = {movie1, {21, 37}};

  std::cout << getTimeSlot(morning) << std::endl;
  std::cout << "\n" << getTimeSlot(lateMorning) << std::endl;
  std::cout << "\n" << getTimeSlot(afternoon) << std::endl;
  std::cout << "\n" << getTimeSlot(evening) << std::endl;
  std::cout << "\n" << getTimeSlot(night) << std::endl;

  std::cout << "\n--------------------Task D-------------------" << std::endl;
  TimeSlot beforeAfternoon = scheduleAfter(lateMorning, movie4);

  std::cout << getTimeSlot(lateMorning) << std::endl;
  std::cout << "\n" << getTimeSlot(beforeAfternoon) << std::endl;

  std::cout << "\n--------------------Task E-------------------" << std::endl;
  std::cout << "For " << morning.movie.title << " at " << morning.startTime.h << ":" << morning.startTime.m << " and " << lateMorning.movie.title << " at " << lateMorning.startTime.h << ":" << lateMorning.startTime.m << " : Do their timeslots overlap?\n(1 for yes and 0 for no)\n\n" << timeOverLap(morning, lateMorning) << std::endl;

  std::cout << "\nFor " << morning.movie.title << " at " << morning.startTime.h << ":" << morning.startTime.m << " and " << night.movie.title << " at " << night.startTime.h << ":" << night.startTime.m << ": Do their timeslots overlap?\n(1 for yes and 0 for no)\n\n" << timeOverLap(morning, night) << std::endl;

  return 0;
}
