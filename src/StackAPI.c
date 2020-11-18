/**
 * Sooraj Modi
 * Created September, 2020
 */
#include "StackAPI.h"

/************************
      CORE FUNCTIONS
************************/

Stack* initializeStack(void (*printFunction)(void *toBePrinted), void (*deleteFunction)(void *toBeDeleted), int (*compareFunction)(const void *first, const void *second)) {
  return (Stack *)initializeList(printFunction, deleteFunction, compareFunction);
}

void* top(Stack* stack) {
  return getDataFromFront((List*)stack);
}

void pop(Stack* stack) {
  deleteFromFront((List*)stack);
}

void push(Stack* stack, void* toBeAdded) {
  insertFront((List*)stack, toBeAdded);
}

void printStack(Stack* stack) {
  printForward((List*)stack);
}

int getSize(Stack* stack) {
  return getLength((List *)stack);
}

int isStackEmpty(Stack* stack) {
  return isEmpty((List *)stack);
}

void clearStack(Stack* stack) {
  clearList((List *)stack);
}

void deleteStack(Stack* stack) {
  deleteList((List *)stack);
}
