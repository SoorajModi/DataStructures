#include "QueueAPI.h"

Queue* initializeQueue(void (*printFunction)(void *toBePrinted), void (*deleteFucntion)(void *toBeDeleted), int (*compareFunction)(const void *first, const void *second));
  Queue* queue = malloc(sizeof(Queue));

  queue->head = NULL;
  queue->tail = NULL;
  queue->length = 0;
  queue->print = printFunction;
  queue->delete = deleteFunction;
  queue->compare = compareFunction;

  return queue;
}

Node* initializeNode(void* data) {
  Node* node = malloc(sizeof(Node));

  node->data = data;
  node->next = NULL;
  node->previous = NULL;

  return node;
}

void insertNode(Queue* queue, void* dataToBeAdded){
  Node* toAdd = initializeNode(dataToBeAdded);

  if (queue->tail) {
    queue->tail->next = toAdd;
    toAdd->previous = queue->tail;
  } else {
    queue->head = toAdd;
    queue->tail = toAdd;
  }

  queue->length++;
}

Node* peek(Queue* queue) {
  return queue->head;
}

void dequeue(Queue* queue) {
  Node* toPop = queue->head;
  queue->head = toPop->next;
  queue->delete(toPop->data);
  free(toPop);
}

int getLength(Queue* queue) {
  return queue->length;
}

int isEmpty(Queue* queue){
  if (getLength(queue) == 0) {
    return 0;
  }
  return 1;
}

void deleteQueue(Queue* queue) {
  while(!isEmpty(queue)) {
    pop(queue);
  }
  free(queue);
}
