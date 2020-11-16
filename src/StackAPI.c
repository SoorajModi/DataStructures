#include "StackAPI.h"

Stack* initializeStack(void (*printFunction)(void *toBePrinted), void (*deleteFucntion)(void *toBeDeleted), int (*compareFunction)(const void *first, const void *second)) {
  Stack* stack = malloc(sizeof(Stack));

  stack->top = NULL;
  stack->size = 0;
  stack->print = printFunction;
  stack->delete = deleteFunction;
  stack->compare = compareFunction;

  return stack;
}

Node* initializeNode(void* data) {
  Node* node = malloc(sizeof(Node));

  node->data = data;
  node->next = NULL;

  return node;
}

Node* top(Stack* stack) {
  return stack->top;
}

void pop(Stack* stack) {
  Node* toPop = stack->top;

  stack->top = toPop->next;
  stack->delete(toPop->data);
  free(toPop);
}

void push(Stack* stack, void* toBeAdded) {
  Node* toPush = initializeNode(toBeAdded);

  toPush->next = stack->top;
  stack->top = toPush;
  stack->size++;
}

int getSize(Stack* stack) {
  return stack->size;
}

int isEmpty(Stack* stack) {
  if (getSize(stack) == 0) {
    return 1;
  }
  return 0;
}

void deleteStack(Stack* stack) {
  while(!isEmpty(stack)) {
    pop(stack);
  }
  free(stack);
}
