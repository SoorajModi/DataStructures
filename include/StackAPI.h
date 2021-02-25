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

/**Function to initialize the Stack. Allocates memory to a List Struct.
 * @param printFunction function pointer to print the data associated with a single node in the list.
 * @param deleteFunction function pointer to delete the data associated with a single node in the list
 * @param compareFunction function pointer to compare the data associated with two nodes of the list in order to test for equality.
 * @return pointer to the Stack.
 **/
Stack *initializeStack(void (*printFunction)(void *toBePrinted), void (*deleteFucntion)(void *toBeDeleted),
                       int (*compareFunction)(const void *first, const void *second));

/**Function to return the data at the top of the Stack.
 * @pre The Stack exists and has memory allocated to it.
 * @param Stack pointer to the Stack.
 * @return pointer to the data associated with the node located at the top of the stack.
 **/
void *top(Stack *stack);

/**Deletes the head of the Stack, including the data associated with the head.
 * @pre Stack type must exist and be used in order to keep track of the Stack.
 * @param Stack pointer to the Stack.
 * @post head node is deleted, the next element of the Stack is set to head.
 **/
void pop(Stack *stack);

/**Inserts a Node at the top of a Stack. The Stack then updates accordingly.
 * @pre Stack type must exist and be used in order to keep track of the Stack.
 * @param Stack pointer to the Stack.
 * @param toBeAdded a pointer to data that is to be added to the Stack.
 * @post Node is inserted into the Stack, set to Stack head.
 **/
void push(Stack *stack, void *toBeAdded);

/**Function to print Stack from top to bottom. This will utilize the Stack's printNode function pointer to print.
 * @pre Stack must exist, but does not have to have elements.
 * @param Stack pointer to linked list.
 **/
void printStack(Stack *stack);

/**Function to get the size of the Stack. Number of elements in the Stack.
 * @pre Stack must exist, does not have to have elements.
 * @param Stack pointer to Stack.
 * @return the number of nodes in the Stack.
 **/
int getSize(Stack *stack);

/**Function to determine if the Stack is empty.
 * @pre Stack must exist, does not have to have elements.
 * @param Stack pointer to Stack.
 * @return 1 if the Stack is empty.
 * @return 0 if the Stack is not empty.
 **/
int isStackEmpty(Stack *stack);

/**Deletes all nodes in a Stack, but not the Stack itself.
 * @pre Stack type must exist and be used.
 * @param Stack pointer to the List.
 */
void clearStack(Stack *stack);

/**Deletes the entire Stack head to tail, starting with the nodes, followed by the Stack itself.
 * @pre Stack type must exist and be used in order to keep track of the Stack.
 * @param Stack pointer to the Stack.
 **/
void deleteStack(Stack *stack);

#endif
