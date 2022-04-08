#pragma once

#include "movie.h"

class TimeSlot { 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts
};

void printMovie(Movie mv);
std::string getTimeSlot(TimeSlot ts);
