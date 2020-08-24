/*
This is the library for CIS2520, CIS 2520 made by Sooraj Modi
 */
#include "LinkedListAPI.h"
#include "Stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/************************
        FUNCTIONS
************************/

List *initializeList(void (*printFunction)(void *toBePrinted), void (*deleteFucntion)(void *toBeDeleted), int (*compareFunction)(const void *first, const void *second)){
    List *list;
    list = malloc(sizeof(List));

    list->head = NULL;
    list->tail = NULL;

    return list;
}

Node *initializeNode(void *data){
    Node *node;
    node = malloc(sizeof(Node));

    node->data = data;
    node->next = NULL;
    node->previous = NULL;

    return node;
}

void insertFront(List *list, void *toBeAdded) {
    Node * toAdd = (Node *) toBeAdded;
    Node * temp;

    if(list->head == NULL){
        list->head = toAdd;
        list->tail = toAdd;
    } else{
        temp = list->head;
        list->head = toAdd;
	toAdd->next = temp;
	toAdd->previous = NULL;
	temp->previous = toAdd;
    }
}

void insertBack(List *list, void *toBeAdded){
    Node * toAdd = (Node *) toBeAdded;
    Node * last = list->tail;

    if(list->head == NULL){
        list->head = toAdd;
        list->tail = toAdd;
    } else{
     	last->next = toAdd;
	toAdd->previous = last;
	toAdd->next = NULL;
	list->tail = toAdd;
    }
}

void deleteList(List *list){
  int counter = 0;
  Node * temp;
  while(counter == 0){
    Stack *b = ((Stack *)list->head->data);
    b = NULL;
    free(b);
    if(list->head->next == NULL){
      free(list->head);
      list->head = NULL;
      counter = 1;
    } else {
      temp = list->head->next;
      list->head = temp;
      free(list->head->previous);
      list->head->previous = NULL;
    }
  }
}
//TO DO: CLEAN UP CODE
void insertSorted(List *list, void *toBeAdded){
  /*   Node * toAdd = initializeNode(toBeAdded);
   Node * current = list->head;

    if(current == NULL){
        list->head = toAdd;
        list->tail = toAdd;
        return;
    }

    int exit = 0;
    while (exit == 0) {
        if((current == list->head) && (current == list->tail)){
           if(compareCar(toAdd->data, current->data) == -1) {
               toAdd->next = current;
               if(current->previous == NULL){
                   current->previous = toAdd;
                   list->head = toAdd;
                   return;
               } else {
                   toAdd->previous = current->previous;
                   current->previous->next = toAdd;
                   current->previous = toAdd;
                   return;
	       }} else {
              current->next = toAdd;
              toAdd->previous = current;
              list->tail = toAdd;
              return;
           }
       } else if (current == list->head){
             if(compareCar(toAdd->data, current->data) == -1){
                  toAdd->next = current;
                  current->previous = toAdd;
                  list->head = toAdd;
                  return;
             } else if (current->next == NULL) {
                  current->next = toAdd;
                  toAdd->previous = current;
                  list->tail = toAdd;
                  return;
             } else{
                 current = current->next;
             }
        } else if(compareCar(toAdd->data, current->data) == -1){
            toAdd->next = current;
            toAdd->previous = current->previous;
            current->previous->next= toAdd;
            current->previous = toAdd;
        }
        else {
            current = current->next;
        }
	}*/
}

int deleteNodeFromList(List *list, void *toBeDeleted){
    //Check if the list is empty
    if(list->head == NULL){
        return EXIT_FAILURE;
    }

    Node *temp = list->head;
    Node *delete = (Node *)toBeDeleted;

    //Check the head
    if(compare(temp, delete) == 0){
      list->head = temp->next;
      return EXIT_SUCCESS;
    }

    //Step through the list to check for a match
    while(temp->next != NULL){
        if(compare(temp, delete) == 0) {
	  (delete->previous)->next = delete->next;
	  (delete->next)->previous = delete->previous;
	    deleteListNode(delete);
            return EXIT_SUCCESS;
        } else{
            temp = temp->next;
        }
    }

    //test for the tail
    if(compare(temp, delete) == 0) {
      (delete->previous)->next = NULL;
        deleteListNode(delete);
        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}

void *getFromFront(List *list){
  if((list != NULL) && (list->head != NULL)){
        return list->head;
    }

  return NULL;
}


void *getFromBack(List *list){
  if((list != NULL) && (list->head != NULL)){
        return list->tail;
    }

    return NULL;     //TODO: FIX SO IT RETURNS NULL
}

void printForward(List *list){
  Node * temp = list->head;

  if(temp == NULL){
    printf("List is Empty\n");
    return;
  }

  while(temp->next != NULL){
    printInt(temp);
    printf("\n");
    temp = temp->next;
  }

  printInt(temp);
}

void printBackwards(List *list){
  Node * temp = list->tail;

  if(list->head == NULL){
    printf("The list is empty\n");
    return;
  }

  while(temp != list->head){
    printInt(temp);
    printf("\n");
    temp = temp->previous;
  }

  temp = list->head;
  printInt(temp);
}

void deleteListNode(void *toBeDeleted){
  //deleteAndFreeADT();
  //deleteAndFreeNode();
  //cleanPointers();
  Node * temp = (Node *)toBeDeleted;
  /*
  if((temp->next != NULL) && (temp->previous != NULL)){
      (temp->previous)->next = (temp->next);
      (temp->next)->previous = (temp->previous);
  } else if((temp->next == NULL) && (temp->previous != NULL)){
        (temp->previous)->next = NULL;
  } else if((temp->next != NULL) && (temp->previous == NULL)){
        (temp->next)->previous = NULL;
  }
  */
  temp->data = NULL;
  temp->next = NULL;
  temp->previous = NULL;
}

int compare(const void *first, const void *second){
    if(first > second){
        return 1;
    } else if (second > first) {
        return -1;
    } else if (first == second) {
        return 0;
    }

   return 100; //TODO: FIX SO IT RETURNS NULL
}

void printNode(void *toBePrinted){
    //DUMMY FUNCTION
    //SEE PRINTCAR() IN MAIN>C
}
