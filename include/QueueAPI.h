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

/**Function to initialize a Queue. Allocates memory to the struct.
 * @param printFunction function pointer to print the data associated with a single node from the Queue.
 * @param deleteFunction function pointer to delete the data associated with a single node from the Queue.
 * @param compareFunction function pointer to compare the data associated with two nodes of the Queue in order to test for equality.
 * @return pointer to the Queue Struct.
 **/
Queue* initializeQueue(void (*printFunction)(void *toBePrinted), void (*deleteFucntion)(void *toBeDeleted), int (*compareFunction)(const void *first, const void *second));

/**Function to initializing a node for a Queue. This node contains generic data and may be connected to other nodes
 * in the queue.
 * @pre data should be of same size of void pointer on the users machine to avoid size conflicts. data must be valid.
 * data must be cast to void pointer before being added.
 * @post data is valid to be added to a Queue
 * @param data - is a generic pointer to any data type.
 * @return On success returns a node that can be added to a Queue. On failure, returns NULL.
 **/
Node* initializeNode(void* data);

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
 */
int getLength(Queue* queue);

/**Function to determine if the queue is empty.
 * @pre Queue must exist, does not have to have elements.
 * @param Queue pointer to Queue.
 * @return 1 if the queue is empty.
 * @return 0 if the queue is not empty.
 */
int isEmpty(Queue* queue);

/**Deletes the entire queue, starting with the nodes, followed by the Queue itself.
 * @pre Queue type must exist and be used in order to keep track of the Queue.
 * @param queue pointer to the Queue struct.
 **/
void deleteQueue(Queue* queue);

/**Function to delete a single node.
 * @pre Node must exist and have memory allocated to it
 * @post toDelete will have its associated data freed using delete, it will then free the Node
 * @param Node pointer to the node to be deleted
 * @param delete function pointer to function that will delete data associated with the node
 */
void deleteNode(Node* toDelete, void (*delete)(void *toBeDeleted));

#endif
