/**
 * Sooraj Modi
 * Created September, 2020
 */
#include "LinkedListAPI.h"

/************************
        FUNCTIONS
************************/

List* initializeList(void (*printFunction)(void* toBePrinted), void (*deleteFunction)(void* toBeDeleted), int (*compareFunction)(const void* first, const void* second)){
    List* list = malloc(sizeof(List));

    list->head = NULL;
    list->tail = NULL;
    list->length = 0
    list->print = printFunction;
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
    Node* toAdd = initializeNode(toBeAdded);
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
    Node* toAdd = initializeNode(toBeAdded);
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

void insertSorted(List* list, void* toBeAdded){
  if (list->head == NULL || list->compare(list->head->data, toBeAdded) < 0) {
    insertFront(list, toBeAdded);
  } else if (list->compare(list->tail->data, toBeAdded) >= 0) {
    insertBack(list, toBeAdded);
  } else {
    Node* node = list->head;
    while (node) {
      if (list->compare(node->data, toBeAdded) < 0) {
        Node* toAdd = initializeNode(toBeAdded);
        node->prev->next = toAdd;
        node->next->prev = toAdd;
        toAdd->prev = node->prev;
        toAdd->next = node->next;
        list->length++;
        return;
      }
      node = node->next;
    }
  }
}

void* getFromFront(List *list) {
  return (void*)(list->head);
}

void* getFromBack(List *list) {
    return (void*)(list->tail);
}

void* getNode(List* list, void* toFind) {
  Node* node = list->head;

  while (node) {
    if (list->compare(node->data, toFind) == 0) {
      return (void *)node;
    }
  }

  return NULL;
}

void printForward(List* list) {
  Node* node = list->head;

  while (node) {
    printNode(node, list->print);
    node = node->next;
  }
}

void printBackwards(List* list) {
  Node* node = list->tail;

  while (node) {
    printNode(node, list->print);
    node = node->previous;
  }
}

void printNode(Node* node, void (*print)(void* toBePrinted)) {
  print(node->data);
}

int getLength(List* list) {
  return list->length;
}

int isEmpty(List* list) {
  if(getLength(list) == 0) {
    return 1;
  }
  return 0;
}

void deleteList(List* list) {
  clearList(list);
  free(list);
}

void clearList(List* list) {
  while (!isEmpty(list)) {
    deleteNodeFromList(list, list->head->data);
  }
}

void deleteNodeFromList(List* list, void* toBeDeleted) {
  Node* node = list->head;
  while (node) {
    if (list->compare(node->data, toBeDeleted) == 0) {
      node->previous->next = node->next;
      node->next->previous = node->previous;
      deleteNode(node, list->delete);
      list->length--;
    }
    node = node->next;
  }
}

void deleteNode(Node* toDelete, void (*delete)(void* toBeDeleted)) {
  delete(toDelete->data);
  free(toDelete);
}
