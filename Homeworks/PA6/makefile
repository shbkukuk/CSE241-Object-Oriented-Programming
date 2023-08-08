CFLAGS = --std=c++11

CC = g++

ALL = main.o music.o movie.o catolog.o book.o content.o


run: $(ALL)
	$(CC) $(ALL) -o run
	./run

main.o: main.cpp
	$(CC) -c main.cpp

movie.o: movie.h
	$(CC) -c movie.cpp

catolog.o: catolog.h
	$(CC) -c catolog.cpp

music.o: music.h
	$(CC) -c music.cpp

book.o: book.h
	$(CC) -c book.cpp

content.o: content.h
	$(CC) -c content.cpp


clean:
	rm *.o run