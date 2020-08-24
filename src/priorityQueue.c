#include <stdio.h>
#include <stdlib.h>

#include "LinkedListAPI.h"
#include "PriorityQueue.h"

List *create(void (*printFunction)(void *toBePrinted), void (*deleteFucntion)(void *toBeDeleted), int (*compareFunction)(const void *first, const void *second)){
  List *list;
  list = malloc(sizeof(List));

  list->head = NULL;
  list->tail = NULL;

  return list;
}

void destroy(List *list){
  deleteList(list);
}

void insert(List *list, void *dataToBeAdded){
    insertSorted(list, toBeAdded);
}

void pop(Llist *list){
    removeFront(list);
}

void *peek(List *list){
   return getFromFront(list);
}

void removeNode(List *list, void *toBeDeleted){
  deleteNodeFromList(list, toBeDeleted);
}

void isEmpty(list){
    return getFromFront(list);
}
