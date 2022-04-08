#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "time.h"

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
