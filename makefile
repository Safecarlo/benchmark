CC=verificarlo-c
CFLAGS=-Wall -Wextra
OFLAGS=-O0 -march=native -fno-unroll-loops
LFLAGS=-lm

.PHONY: all clean

all: main compute

main: main.c
	$(CC) $(CFLAGS) $(OFLAGS) $< -o $@ $(LFLAGS)

compute: compute.c
	clang $< -o $@

clean:
	rm -Rf *~ *.o .vfc* main compute
