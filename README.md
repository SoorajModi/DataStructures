# Data Structures

The following are a list of Data Structures written in C. Some of the APIs are dependent on each other.

You can view the source code under src, and the header files under include.

## How to Run

To compile CMakeList: `cmake .`

To compile makefile: `make`



## Linked List API
- initializeList
- insertFront
- insertBack
- insertSorted
- getFromFront
- getFromBack
- printForward
- printBackwards
- getLength
- isEmpty
- clearList
- deleteDataFromList
- deleteFromFront
- deleteFromBack
- deleteList

## Singly Linked List API
- initializeList
- insertFront
- insertBack
- insertSorted
- getDataFromFront
- getDataFromBack
- printForward
- printBackwards
- getLength
- isEmpty
- clearList
- deleteFromFront
- deleteFromBack
- deleteList

## Queue API (Requires Linked List API)
- initializeQueue
- front
- enqueue
- dequeue
- getLength
- isEmpty
- deleteQueue

## Stack API (Requires Singly Linked List API)
- initializeStack
- top
- pop
- push
- printStack
- isStackEmpty
- clearStack
- deleteStack

## Binary Tree API
- initializeTree
- insertData
- removeData
- printPostorder
- printPreorder
- printInorder
- isEmpty
- getTreeSize
- deleteSubtree
- deleteTree

## Graph API
- createGraph
- addVertex
- addAdjVertex
- addEdge
- printGraph
- checkForVertex
