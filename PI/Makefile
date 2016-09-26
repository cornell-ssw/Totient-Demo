CC = gcc
CFLAGS = -O3 -std=c99

.PHONY: all clean

all: pi

pi: estimate_pi.c
	$(CC) $(CFLAGS) -o estimate_pi estimate_pi.c

clean:
	rm -f estimate_pi pi.o*
