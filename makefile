CC = gcc
AR = ar 
CFLAGS = -Wall -g -std=c99
LDFLAGS = -L.
LDLIBS = 


all: test

test: game.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS) $(LDFLAGS)

game.o: game.c game.h


.PHONY: clean
clean:
	rm -f *.o test