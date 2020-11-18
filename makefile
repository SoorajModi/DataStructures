CC=gcc
CFLAGS = -Wall -std=c99 -pedantic

BIN = ./bin/
SRC = ./src/
LIBS = .L./lib
ASS = ./assets/

LinkedList:
	$(CC) $(CFLAGS) $(SRC)LinkedListAPITest.c $(SRC)LinkedListAPI.c $(SRC)DataTypes.c -Iinclude -o $(BIN)linkedList

runLinkedList: LinkedList
	$(BIN)linkedList $(ASS)TestData.txt

runValgrindLinkedList: runLinkedList
	valgrind --leak-check=full --show-leak-kinds=all $(BIN)linkedList $(ASS)TestData.txt

Stack: StackAPI.h
	$(CC) $(CFLAGS) $(SRC)StackAPITest.c $(SRC)StackAPI.c -Iinclude -o $(BIN)stack

runStack: Stack
	$(BIN)stack $(ASS)TestData.txt

runValgrindStack: runStack
	valgrind --leak-check=full --show-leak-kinds=all $(BIN)stack $(ASS)TestData.txt

Queue: QueueAPI.h
	$(CC) $(CFLAGS) $(SRC)QueueAPITest.c $(SRC)QueueAPI.c -Iinclude -o $(BIN)queue

runQueue:
	$(BIN)queue $(ASS)TestData.txt

runValgrindStack: runQueue
	valgrind --leak-check=full --show-leak-kinds=all $(BIN)queue $(ASS)TestData.txt

Heap: HeapAPI.h
	$(CC) $(CFLAGS) $(SRC)HeapAPITest.c $(SRC)HeapAPI.c -Iinclude -o $(BIN)heap

BinaryTree: BinaryTree.h
	$(CC) $(CFLAGS) $(SRC)BinaryTreeAPITest.c $(SRC)BinaryTreeAPI.c -Iinclude -o $(BIN)binaryTree

HashMap: HashMapAPI.h
	$(CC) $(CFLAGS) $(SRC)HashMapAPITest.c $(SRC)HashMapAPI.c -Iinclude -o $(BIN)hashMap

Graph: GraphAPI.h
	$(CC) $(CFLAGS) $(SRC)GraphAPITest.c $(SRC)GraphAPI.c -Iinclude -o $(BIN)graph

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
