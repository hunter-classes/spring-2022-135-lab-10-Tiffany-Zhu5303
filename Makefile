OBJECTS = time.o

main: main.o time.o
	g++ -o main main.o $(OBJECTS)

tests: tests.o time.o
	g++ -o tests tests.o $(OBJECTS)

time.o: time.cpp time.h

main.o: main.cpp time.h

tests.o: tests.cpp doctest.h time.h

clean:
	rm -f main tests main.o tests.o $(OBJECTS)
