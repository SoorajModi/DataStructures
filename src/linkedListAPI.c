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

void deleteList(List *list) {
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
  if (list == NULL || toBeDeleted == NULL){
    return NULL;
  }

  Node* tmp = list->head;

  while(tmp != NULL){
    if (list->compare(toBeDeleted, tmp->data) == 0){
      //Unlink the node
      Node* delNode = tmp;

      if (tmp->previous != NULL){
        tmp->previous->next = delNode->next;
      }else{
        list->head = delNode->next;
      }

      if (tmp->next != NULL){
        tmp->next->previous = delNode->previous;
      }else{
        list->tail = delNode->previous;
      }

      void* data = delNode->data;
      free(delNode);

      (list->length)--;

      return data;

    }else{
      tmp = tmp->next;
    }
  }

  return NULL;
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
  if((list == NULL) || (list->head == NULL)) return;
  Node* node = list->head;

  while(node->next != NULL){
    printf("%s ", list->print(node));
    node = node->next;
  }
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
  Node * temp = (Node *)toBeDeleted;
  temp->data = NULL;
  temp->next = NULL;
  temp->previous = NULL;
}

void clearList(List* list){
    if((list == NULL) || ((list->head == NULL) && (list->tail == NULL))) return;

    while(list->head != NULL){
        Node* temp = list->head;
        list->deleteData(temp->data);
        list->head = temp->next;
        free(temp);
    }

    list->length = 0;
    list->head = NULL;
    list->tail = NULL;
}

int getLength(List* list) {
  return list->length;
}
