CC = gcc
FLAGS = -Wall -g

all: signal

signal: 
	$(CC) $(FLAGS) signals.c -o signal
	
.PHONY: clean all

clean:
	rm -f signal *.o

run: 
	./signal