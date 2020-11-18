#ifndef _QUEUE_API_
#define _QUEUE_API_

/************************
     CORE LIBARIES
************************/

#include "LinkedListAPI.h"

/************************
       CORE OBJECTS
************************/

/**
 * Queue pointer, wraps around doubly linked list.
 **/
typedef List Queue;

/************************
      CORE FUNCTIONS
************************/

/**Function to initialize a Queue. Allocates memory to the struct.
 * @param printFunction function pointer to print the data associated with a single node from the Queue.
 * @param deleteFunction function pointer to delete the data associated with a single node from the Queue.
 * @param compareFunction function pointer to compare the data associated with two nodes of the Queue in order to test for equality.
 * @return pointer to the Queue Struct.
 **/
Queue* initializeQueue(void (*printFunction)(void *toBePrinted), void (*deleteFucntion)(void *toBeDeleted), int (*compareFunction)(const void *first, const void *second));

/**Function to return the data at the front of the Queue.
 * @pre The queue exists and has memory allocated to it
 * @param Queue pointer to the Queue.
 * @return pointer to the data located at the head of the list
 **/
void* front(Queue* queue);

/**Inserts a Node to the end of the Queue. The Queue then updates accordingly.
 * @pre 'Queue' type must exist and be used in order to keep track of the Queue.
 * @param queue pointer to the Queue struct.
 * @param dataToBeAdded a pointer to data that is to be added to the Queue.
 * @post a new Node with data dataToBeAdded is added to the end of the Queue.
 **/
void enqueue(Queue* queue, void* dataToBeAdded);

/**Function to remove the first element in the queue.
 * @pre the Queue exists and has memory allocated to it.
 * @param Queue pointer to the Queue.
 * @post the first element in the queue is removed.
 **/
void dequeue(Queue* queue);

/**Function to get the length of the Queue.
 * @pre Queue must exist, does not have to have elements.
 * @param queue pointer to Queue.
 * @return the number of nodes in the queue.
 **/
int getQueueLength(Queue* queue);

/**Function to determine if the queue is empty.
 * @pre Queue must exist, does not have to have elements.
 * @param Queue pointer to Queue.
 * @return 1 if the queue is empty.
 * @return 0 if the queue is not empty.
 **/
int isQueueEmpty(Queue* queue);

/**Function to print queue from the front to the end. This will the Queue's printNode function pointer to print.
 * @pre Queue must exist, but does not have to have elements.
 * @param list pointer to linked list.
 **/
void printQueue(Queue* queue);

/**Deletes the entire queue, starting with the nodes, followed by the Queue itself.
 * @pre Queue type must exist and be used in order to keep track of the Queue.
 * @param queue pointer to the Queue struct.
 **/
void deleteQueue(Queue* queue);

#endif
