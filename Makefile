CC = gcc
CFLAGS = -Wall -pthread -g

all: t0 t1 main-race main-race-fixed

t0: t0.c common.h common_threads.h
	$(CC) $(CFLAGS) -o t0 t0.c

t1: t1.c common.h common_threads.h
	$(CC) $(CFLAGS) -o t1 t1.c

main-race: main-race.c
	$(CC) $(CFLAGS) -o main-race main-race.c

main-race-fixed: main-race-fixed.c
	$(CC) $(CFLAGS) -o main-race-fixed main-race-fixed.c

clean:
	rm -f t0 t1 main-race main-race-fixed

.PHONY: all clean