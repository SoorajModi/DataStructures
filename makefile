CC=gcc
CFLAGS = -Wall -std=c99 -pedantic

BIN = ./bin/
SRC = ./src/
LIBS = .L./lib

LinkedList:
	$(CC) $(CFLAGS) $(SRC)LinkedListAPITest.c $(SRC)LinkedListAPI.c $(SRC)DataTypes.c -Iinclude -o $(BIN)linkedList

Stack: StackAPI.h
	$(CC) $(CFLAGS) $(SRC)StackAPITest.c $(SRC)StackAPI.c -Iinclude -o $(BIN)stack

Queue: QueueAPI.h
	$(CC) $(CFLAGS) $(SRC)QueueAPITest.c $(SRC)QueueAPI.c -Iinclude -o $(BIN)queue

Heap: HeapAPI.h
	$(CC) $(CFLAGS) $(SRC)HeapAPITest.c $(SRC)HeapAPI.c -Iinclude -o $(BIN)heap

BinaryTree: BinaryTree.h
	$(CC) $(CFLAGS) $(SRC)BinaryTreeAPITest.c $(SRC)BinaryTreeAPI.c -Iinclude -o $(BIN)binaryTree

HashMap: HashMapAPI.h
	$(CC) $(CFLAGS) $(SRC)HashMapAPITest.c $(SRC)HashMapAPI.c -Iinclude -o $(BIN)hashMap

Graph: GraphAPI.h
	$(CC) $(CFLAGS) $(SRC)GraphAPITest.c $(SRC)GraphAPI.c -Iinclude -o $(BIN)graph

runLinkedList:
	$(BIN)linkedList $(SRC)listData.txt

runStack:
	$(BIN)stack

runQueue:
	$(BIN)queue

runHeap:
	$(BIN)heap

runBinaryTree:
	$(BIN)binaryTree

runHashMap:
	$(BIN)hashMap

runGraph:
	$(BIN)graph

clean:
	rm $(BIN)*

cls:
	clear

sayHi:
	@echo 'These are Data Structure APIs made by Sooraj Modi'
