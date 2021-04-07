CC=verificarlo-c
OFLAGS=-O0 -march=native

.PHONY: all clean

all: main

main: main.c rdtsc.h
	$(CC) $(OFLAGS) $< -o $@

clean:
	rm -Rf *~ *.o .vfc* main
