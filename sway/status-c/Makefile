CC = gcc
CFLAGS = -g -Wall -Werror
REQS = main.o util.o system.o status_bars.o cachemaster.o mathutil.o

all: main

clean:
	rm -f $(REQS) main get_status

push: all
	rm -f get_status
	cp main get_status
	sway reload

main: $(REQS)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c status_bars.o
	$(CC) $(CFLAGS) -c $<

system.o: system.c system.h
	$(CC) $(CFLAGS) -c $<

util.o: util.c util.h mathutil.o
	$(CC) $(CFLAGS) -c $<

mathutil.o: mathutil.c mathutil.h
	$(CC) $(CFLAGS) -c $<

status_bars.o: status_bars.c status_bars.h util.o cachemaster.o
	$(CC) $(CFLAGS) -c $<

cachemaster.o: cachemaster.c cachemaster.h system.o
	$(CC) $(CFLAGS) -c $<
