#ifndef _QUEUE_API_
#define _QUEUE_API_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Node for the Queue
 **/
typedef struct node {
    void* data;
    struct node* next;
    struct node* prev;
} Node;

/**
 * Struct for a Queue. Contains a pointer to the front and end of the Queue and to helper functions.
 **/
typedef struct queue {
    Node* head;
    Node* tail;
    int length;
    void (*delete)(void* toBeDeleted);
    int (*compare)(const void* first, const void* second);
    void (*print)(void* toBePrinted);
} Queue;

/**
 *
 */
Queue* initializeQueue(void (*printFunction)(void *toBePrinted), void (*deleteFucntion)(void *toBeDeleted), int (*compareFunction)(const void *first, const void *second));

/**
 *
 */
Node* initializeNode(void* data);

/**
 * @param list
 * @param dataToBeAdded
 */
void insertNode(Queue* queue, void* dataToBeAdded);

/**
 *
 */
Node* peek(Queue* queue);

/**
 *
 */
void dequeue(Queue* queue);

/**
 *
 */
int getLength(Queue* queue);

/**
 *
 */
int isEmpty(Queue* queue);

/**
  *
  */
void deleteQueue(Queue* queue);

#endif
