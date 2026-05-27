FLAGS=-Wall -Wextra -Wno-unused-parameter
CC=gcc

all: main

main: main.o tpn.o
	$(CC) $(FLAGS) -o main main.o tpn.o

main.o: main.c tpn.h
	$(CC) $(FLAGS) -c main.c

tpn.o: tpn.c tpn.h
	$(CC) $(FLAGS) -c tpn.c

clean:
	rm -f *.o main