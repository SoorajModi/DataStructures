/**
 * Sooraj Modi
 * Created September, 2020
 */
#include "LinkedListAPI.h"

/************************
      CORE FUNCTIONS
************************/

List *initializeList(void (*printFunction)(void *toBePrinted), void (*deleteFunction)(void *toBeDeleted),
                     int (*compareFunction)(const void *first, const void *second)) {
    List *list = malloc(sizeof(List));

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    list->print = printFunction;
    list->delete = deleteFunction;
    list->compare = compareFunction;

    return list;
}

Node *initializeNode(void *data) {
    Node *node = malloc(sizeof(Node));

    node->data = data;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

void insertFront(List *list, void *toBeAdded) {
    Node *toAdd = initializeNode(toBeAdded);

    if (getHead(list)) {
        toAdd->next = getHead(list);
        list->head->prev = toAdd;
    } else {
        list->tail = toAdd;
    }
    list->head = toAdd;
    list->length++;
}

void insertBack(List *list, void *toBeAdded) {
    Node *toAdd = initializeNode(toBeAdded);

    if (getTail(list)) {
        toAdd->prev = getTail(list);
        list->tail->next = toAdd;
    } else {
        list->head = toAdd;
    }
    list->tail = toAdd;
    list->length++;
}

void insertSorted(List *list, void *toBeAdded) {
    if (!getHead(list) || compareNode(getHead(list), toBeAdded, list->compare) < 0) {
        insertFront(list, toBeAdded);
    } else if (compareNode(getTail(list), toBeAdded, list->compare) >= 0) {
        insertBack(list, toBeAdded);
    } else {
        insertInorder(list, toBeAdded);
    }
}

void *getDataFromFront(List *list) {
    return getHead(list)->data;
}

void *getDataFromBack(List *list) {
    return getTail(list)->data;
}

void printForward(List *list) {
    Node *node = getHead(list);

    while (node) {
        printNode(node, list->print);
        node = getNext(node);
    }
}

void printBackwards(List *list) {
    Node *node = getTail(list);

    while (node) {
        printNode(node, list->print);
        node = getPrev(node);
    }
}

int isEmpty(List *list) {
    if (getLength(list) == 0) {
        return 1;
    }
    return 0;
}

int getLength(List *list) {
    return list->length;
}

void deleteList(List *list) {
    clearList(list);
    free(list);
}

void clearList(List *list) {
    while (!isEmpty(list)) {
        deleteFromFront(list);
    }
}

void deleteFromFront(List *list) {
    Node *node = getHead(list);
    list->head = getNext(node);
    deleteNode(node, list->delete);
    list->length--;
}

void deleteFromBack(List *list) {
    Node *node = getTail(list);
    list->tail = getPrev(node);
    deleteNode(node, list->delete);
    list->length--;
}

void deleteDataFromList(List *list, void *toBeDeleted) {
    Node *node = list->head;
    while (node) {
        if (list->compare(node->data, toBeDeleted) == 0) {
            deleteNodeFromList(list, node);
        } else {
            node = getNext(node);
        }
    }
}

/************************
    UTILITY FUNCTIONS
************************/

void insertInorder(List *list, void *toBeAdded) {
    Node *toAdd = initializeNode(toBeAdded);
    Node *node = getHead(list);

    while (node) {
        if (compareNode(node, toBeAdded, list->compare) < 0) {
            node->prev->next = toAdd;
            node->next->prev = toAdd;
            toAdd->prev = getPrev(node);
            toAdd->next = getNext(node);
            list->length++;
            return;
        }
        node = getNext(node);
    }
}

void deleteNodeFromList(List *list, Node *node) {
    if (node == list->head) {
        deleteFromFront(list);
    } else if (node == list->tail) {
        deleteFromBack(list);
    } else {
        deleteNodeFromMiddle(list, node);
    }
}

void deleteNodeFromMiddle(List *list, Node *node) {
    node->prev->next = getNext(node);
    node->next->prev = getPrev(node);
    deleteNode(node, list->delete);
    list->length--;
}

Node *getNode(List *list, void *toFind) {
    Node *node = getHead(list);

    while (node) {
        if (compareNode(node, toFind, list->compare) == 0) {
            return node;
        }
    }

    return NULL;
}

Node *getHead(List *list) {
    return list->head;
}

Node *getTail(List *list) {
    return list->tail;
}

Node *getNext(Node *node) {
    return node->next;
}

Node *getPrev(Node *node) {
    return node->prev;
}

void printNode(Node *node, void (*print)(void *toBePrinted)) {
    print(node->data);
}

void deleteNode(Node *toDelete, void (*delete)(void *toBeDeleted)) {
    delete(toDelete->data);
    free(toDelete);
}

int compareNode(Node *first, void *second, int (*compare)(const void *first, const void *second)) {
    return compare((const void *) first->data, second);
}
