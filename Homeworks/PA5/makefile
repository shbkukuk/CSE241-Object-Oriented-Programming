CFLAGS = --std=c++11

CC = g++

ALL = main.o World.o Buldozer.o Humanic.o Optimusprime.o Robocop.o Robot.o Roomba.o


run: $(ALL)
	$(CC) $(ALL) -o run
	./run

main.o: main.cpp
	$(CC) -c main.cpp

Buldozer.o: Buldozer.h
	$(CC) -c Buldozer.cpp

Humanic.o: Humanic.h
	$(CC) -c Humanic.cpp

World.o: World.h
	$(CC) -c World.cpp

Optimusprime.o: Optimusprime.h
	$(CC) -c Optimusprime.cpp

Robocop.o: Robocop.h
	$(CC) -c Robocop.cpp

Robot.o: Robot.h
	$(CC) -c Robot.cpp

Roomba.o: Roomba.h
	$(CC) -c Roomba.cpp

clean:
	rm *.o run