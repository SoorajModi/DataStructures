#ifndef _HASH_MAP_API_
#define _HASH_MAP_API_

/************************
     CORE LIBARIES
************************/

#include "LinkedListAPI.h"

/************************
       CORE OBJECTS
************************/

/**
 * Node for the HashMap
 **/
typedef struct hashNode {
    int key;
    Node *data;
} HashNode;

/**
 * Struct for a HashMap. Contains a pointer to the front and end of the Queue and to helper functions.
 **/
typedef struct hashMap {
    unsigned int capacity;
    unsigned int numElements;
    List *map;

    int (*hash)(void *toHash);

    void (*print)(void *toBePrinted);

    int (*compare)(const void *first, const void *second);

    void (*delete)(void *toBeDeleted);
} HashMap;

/************************
      CORE FUNCTIONS
************************/

HashMap *initializeHashMap(unsigned int capacity, int (*hash)(void *toHash), void (*print)(void *toBePrinted),
                           void (*delete)(void *toBeDeleted),
                           int (*compareFunction)(const void *first, const void *second));

HashNode *initializeHashNode(int key, void *data);

void insertIntoTable(HashMap *map, void *data);

int lookup(HashMap *map, int key);

/************************
    UTILITY FUNCTIONS
************************/

void printHashNode(HashNode *node, void (*print)(void *toBePrinted));

void deleteHashNode(HashNode *node, void (*delete)(void *toBeDeleted));

int compareHashNode(Node *first, void *second, int (*compare)(const void *first, const void *second));

#endif
