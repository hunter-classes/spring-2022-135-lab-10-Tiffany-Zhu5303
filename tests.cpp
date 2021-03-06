#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "time.h"
#include "timeslot.h"

TEST_CASE("Minutes since midnight"){
  Time now = {8, 51};
  Time later = {5, 6};

  CHECK(minutesSinceMidnight(now) == 531);
  CHECK(minutesSinceMidnight(later) == 306);
}

TEST_CASE("Time between intervals"){
  Time now = {9, 5};
  Time later = {6, 13};

  CHECK(minutesUntil(now, later) == -172);
  
  now = {21, 9};
  later = {24, 0};
  
  CHECK(minutesUntil(now, later) == 171);
}

TEST_CASE("Adding time"){
  Time now = {17, 9};
  int minutes = 59;
  now = addMinutes(now, minutes);

  CHECK(now.h == 18);
  CHECK(now.m == 8);

  now = addMinutes(now, 57);

  CHECK(now.h == 19);
  CHECK(now.m == 5);
}

TEST_CASE("Movie time slot"){
  Movie movie1 = {"The Secrets of Dumbledore", DRAMA, 142};
  Movie movie2 = {"Everything Everywhere All At Once", ACTION, 132};

  TimeSlot afternoon = {movie1, {12, 0}};
  TimeSlot night = {movie2, {21, 30}};

  CHECK(getTimeSlot(afternoon) == "[starts at 12:00, ends by 14:22]");
  CHECK(getTimeSlot(night) == "[starts at 21:30, ends by 23:42]"); 
}

TEST_CASE("Next time slot"){
  Movie movie1 = {"Spider-Man: No Way Home", ACTION, 150};
  Movie movie2 = {"Hotel Transylvania: Transformania", COMEDY, 87};

  TimeSlot first = {movie1, {1, 38}};
  TimeSlot second = scheduleAfter(first, movie2);

  CHECK(second.startTime.h == 4);
  CHECK(second.startTime.m == 8);
}

TEST_CASE("Time slot overlap?"){
  Movie movie1 = {"Uncharted", ACTION, 115};
  Movie movie2 = {"Hotel Transylvania: Transformania", COMEDY, 87};

  TimeSlot first = {movie1, {20, 10}};
  TimeSlot second = {movie2, {19, 38}};

  CHECK(timeOverLap(first, second) == 1);

  first = {movie1, {19, 50}};
  CHECK(timeOverLap(second, first));
}

  

