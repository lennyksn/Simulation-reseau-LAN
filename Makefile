CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
BIN = reseau

all: $(BIN)

$(BIN): $(OBJ) main.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $

main.o: main.c
	$(CC) $(CFLAGS) -c -o main.o main.c

clean:
	rm -f src/*.o main.o $(BIN)