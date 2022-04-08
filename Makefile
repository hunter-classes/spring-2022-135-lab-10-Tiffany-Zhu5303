OBJECTS = time.o timeslot.o

main: main.o time.o timeslot.o
	g++ -o main main.o $(OBJECTS)

tests: tests.o time.o timeslot.o
	g++ -o tests tests.o $(OBJECTS)

time.o: time.cpp time.h

timeslot.o: timeslot.cpp timeslot.h time.h movie.h

main.o: main.cpp time.h timeslot.h movie.h

tests.o: tests.cpp doctest.h time.h

clean:
	rm -f main tests main.o tests.o $(OBJECTS)
