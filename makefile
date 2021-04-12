CC=verificarlo-c
OFLAGS=-O0 -march=native

.PHONY: all clean

all: main compute

main: main.c rdtsc.h
	$(CC) $(OFLAGS) $< -o $@

compute: compute.c
	clang $< -o $@

clean:
	rm -Rf *~ *.o .vfc* main compute
