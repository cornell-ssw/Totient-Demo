CC = gcc
CFLAGS = -O3 -fopenmp -std=c99

.PHONY: all clean

all: pi

pi: estimate_pi_parallel.c
	$(CC) $(CFLAGS) -o estimate_pi_parallel estimate_pi_parallel.c

clean:
	rm -f estimate_pi_parallel pi-parallel.o*
