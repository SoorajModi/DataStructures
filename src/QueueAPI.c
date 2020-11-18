/**
 * Sooraj Modi
 * Created September, 2020
 */
#include "QueueAPI.h"

/************************
        FUNCTIONS
************************/

Queue* initializeQueue(void (*printFunction)(void *toBePrinted), void (*deleteFunction)(void *toBeDeleted), int (*compareFunction)(const void *first, const void *second));
  return (Queue *)initializeList(print, delete, compare);
}

void* front(Queue* queue) {
  return getFromFront((List *)queue);
}

void enqueue(Queue* queue, void* dataToBeAdded){
  insertBack((List *)queue, dataToBeAdded);
}

void dequeue(Queue* queue) {
  deleteFromFront((List *)queue);
}

int getQueueLength(Queue* queue) {
  return getLength((List *)queue);
}

int isQueueEmpty(Queue* queue){
  return isEmpty((List *)queue);
}

void printQueue(Queue* queue) {
  printForward((List *)queue);
}

void deleteQueue(Queue* queue) {
  deleteList((List *)queue)
}
