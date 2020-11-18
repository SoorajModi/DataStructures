#ifndef _STACK_API_
#define _STACK_API_

/************************
     CORE LIBARIES
************************/

#include "SinglyLinkedListAPI.h"

/************************
       CORE OBJECTS
************************/

/**
 * Stack pointer, wraps around a singly linked list struct.
 **/
typedef List Stack;

/************************
      CORE FUNCTIONS
************************/

Stack* initializeStack(void (*printFunction)(void *toBePrinted), void (*deleteFucntion)(void *toBeDeleted), int (*compareFunction)(const void *first, const void *second));

void* top(Stack* stack);

void pop(Stack* stack);

void push(Stack* stack, void* toBeAdded);

void printStack(Stack* stack);

int getSize(Stack* stack);

int isStackEmpty(Stack* stack);

void clearStack(Stack* stack);

void deleteStack(Stack* stack);

#endif
