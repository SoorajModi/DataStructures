CC=gcc
CFLAGS = -Wall -std=c99 -pedantic

BIN = ./bin/
SRC = ./src/
LIBS = .L./lib

program:
	$(CC) $(FLAGS) $(SRC)main.c -Iinclude -o $(BIN)program

run:
	$(BIN)program data.txt

clean:
	rm $(BIN)*

cls:
	clear

sayHi:
	@echo 'This is Assignment 2 for CIS 2520 made by Sooraj Modi'
