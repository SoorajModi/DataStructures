/**
 * Sooraj Modi
 * Created November, 2020
 */
#include "SinglyLinkedListAPI.h"

/************************
      CORE FUNCTIONS
************************/

List* initializeList(void (*printFunction)(void* toBePrinted), void (*deleteFunction)(void* toBeDeleted), int (*compareFunction)(const void* first, const void* second)) {
    List* list = malloc(sizeof(List));

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    list->print = printFunction;
    list->delete = deleteFunction;
    list->compare = compareFunction;

    return list;
}

Node* initializeNode(void* data){
    Node* node = malloc(sizeof(Node));

    node->data = data;
    node->next = NULL;

    return node;
}

void insertFront(List* list, void* toBeAdded) {
    Node* toAdd = initializeNode(toBeAdded);

    if (getHead(list)) {
      toAdd->next = getHead(list);
    } else {
      list->tail = toAdd;
    }
    list->head = toAdd;
    list->length++;
}

void insertBack(List* list, void* toBeAdded) {
    Node* toAdd = initializeNode(toBeAdded);

    if (getTail(list)) {
      list->tail->next = toAdd;
    } else {
      list->head = toAdd;
    }
    list->tail = toAdd;
    list->length++;
}

void insertSorted(List* list, void* toBeAdded){
  if (!getHead(list) || compareNode(getHead(list), toBeAdded, list->compare) < 0) {
    insertFront(list, toBeAdded);
  } else if (compareNode(getTail(list), toBeAdded, list->compare) >= 0) {
    insertBack(list, toBeAdded);
  } else {
    insertInorder(list, toBeAdded);
  }
}

void* getDataFromFront(List *list) {
  return getHead(list)->data;
}

void* getDataFromBack(List *list) {
    return getTail(list)->data;
}

void printForward(List* list) {
  Node* node = getHead(list);

  while (node) {
    printNode(node, list->print);
    node = getNext(node);
  }
}

void printBackwards(List* list) {
  Node* node = getHead(list);
  if(node->next) {
    printNodesBackwards(node->next, list->print);
  }
  printNode(node, list->print);
}

int isEmpty(List* list) {
  if(getLength(list) == 0) {
    return 1;
  }
  return 0;
}

int getLength(List* list) {
  return list->length;
}

void deleteList(List* list) {
  clearList(list);
  free(list);
}

void clearList(List* list) {
  while (!isEmpty(list)) {
    deleteFromFront(list);
  }
}

void deleteFromFront(List* list) {
  Node* node = list->head;
  list->head = node->next;
  deleteNode(node, list->delete);
  list->length--;
}

void deleteFromBack(List* list) {
  Node* tail = getTail(list);
  Node* node = getHead(list);

  while (getNext(node) != tail) {
    node = getNext(node);
  }
  deleteNode(tail, list->delete);

  list->tail = node;
  list->length--;
}

/************************
    UTILITY FUNCTIONS
************************/

void insertInorder(List* list, void* toBeAdded) {
  Node* toAdd = initializeNode(toBeAdded);
  Node* node = getHead(list);

  while (node) {
    if (compareNode(node->next, toBeAdded, list->compare) < 0) {
      toAdd->next = getNext(node);
      node->next = toAdd;
      list->length++;
      return;
    }
    node = getNext(node);
  }
}

void printNodesBackwards(Node* node, void (*print)(void* toBePrinted)){
  if (node->next) {
    printNodesBackwards(node, print);
  }
  printNode(node, print);
}

Node* getNode(List* list, void* toFind) {
  Node* node = getHead(list);

  while (node) {
    if (compareNode(node, toFind, list->compare) == 0) {
      return node;
    }
  }

  return NULL;
}

Node* getHead(List* list) {
  return list->head;
}

Node* getTail(List* list) {
  return list->tail;
}

Node* getNext(Node* node) {
  return node->next;
}

void printNode(Node* node, void (*print)(void* toBePrinted)) {
  print(node->data);
}

void deleteNode(Node* toDelete, void (*delete)(void* toBeDeleted)) {
  delete(toDelete->data);
  free(toDelete);
}

int compareNode(Node* first, void* second, int (*compare)(const void* first, const void* second)) {
  return compare((const void*)first->data, second);
}
