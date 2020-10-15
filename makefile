CC=gcc
CFLAGS = -Wall -std=c99 -pedantic

BIN = ./bin/
SRC = ./src/
LIBS = .L./lib

LinkedList:
	$(CC) $(FLAGS) $(SRC)LinkedListTest.c -Iinclude -o $(BIN)program

run:
	$(BIN)program $(SRC)data.txt

clean:
	rm $(BIN)*

cls:
	clear

sayHi:
	@echo 'These are Data Structure APIs made by Sooraj Modi'
