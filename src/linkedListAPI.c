/*
This is the library for a Linked List, made by Sooraj Modi
 */
#include "LinkedListAPI.h"

/************************
        FUNCTIONS
************************/

List* initializeList(void (*printFunction)(void* toBePrinted), void (*deleteFucntion)(void* toBeDeleted), int (*compareFunction)(const void* first, const void* second)){
    List* list = malloc(sizeof(List));

    list->head = NULL;
    list->tail = NULL;
    list->length = 0
    list->print = printFucntion;
    list->delete = deleteFunction;
    list->compare = compareFunction;

    return list;
}

Node* initializeNode(void* data){
    Node* node = malloc(sizeof(Node));

    node->data = data;
    node->next = NULL;
    node->previous = NULL;

    return node;
}

void insertFront(List* list, void* toBeAdded) {
    Node* toAdd = (Node*)toBeAdded;
    Node* head = list->head;

    if (head == NULL) {
        list->head = toAdd;
        list->tail = toAdd;
    } else {
	      toAdd->next = head;
	      toAdd->previous = NULL;
	      head->previous = toAdd;
        list->head = toAdd;
        list->length++;
    }
}

void insertBack(List* list, void* toBeAdded) {
    Node* toAdd = (Node *)toBeAdded;
    Node* tail = list->tail;

    if (tail == NULL) {
        list->head = toAdd;
        list->tail = toAdd;
    } else {
	      toAdd->previous = tail;
	      toAdd->next = NULL;
        tail->next = toAdd;
	      list->tail = toAdd;
        list->length++;
    }
}

void insertSorted(List *list, void *toBeAdded){
}

void deleteList(List *list) {
}

int deleteNodeFromList(List *list, void *toBeDeleted){
   return -1;
}

void deleteNode(void *toBeDeleted) {
  Node* node = (Node *)toBeDeleted;

}

void* getFromFront(List *list){
  if((list == NULL) && (list->head == NULL)) {
        return NULL;
  }

  return list->head;
}


void* getFromBack(List *list){
  if((list != NULL) && (list->head != NULL)) {
        return NULL;
    }

    return list->tail;
}

void printForward(List *list){
}

void printBackwards(List *list){
}

void clearList(List* list) {
}

int getLength(List* list) {
  return list->length;
}
