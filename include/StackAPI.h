#ifndef _STACK_API_
#define _STACK_API_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Node for the Stack
 **/
typedef struct node {
    void* data;
    struct node* next;
} Node;

/**
 * Struct for a Queue. Contains a pointer to the top of the Queue and to helper functions.
 **/
typedef struct stack {
    Node* top;
    int size;
    void (*delete)(void* toBeDeleted);
    int (*compare)(const void* first, const void* second);
    void (*print)(void* toBePrinted);
} Stack;

Stack* initializeStack(void (*printFunction)(void *toBePrinted), void (*deleteFucntion)(void *toBeDeleted), int (*compareFunction)(const void *first, const void *second));

Node* initializeNode(void* data);

Node* top(Stack* stack);

void push(Stack* stack, void* toBeAdded);

void pop(Stack* stack);

int getSize(Stack* stack);

int isEmpty(Stack* stack);

void deleteStack(Stack* stack);

#endif
