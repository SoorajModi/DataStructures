#include "HashMapAPI.h"

/************************
      CORE FUNCTIONS
************************/

HashMap *initializeHashMap(unsigned int capacity, int (*hash)(void *toHash), void (*print)(void *toBePrinted),
                           void (*delete)(void *toBeDeleted),
                           int (*compare)(const void *first, const void *second)) {
    HashMap *map = malloc(sizeof(HashMap));

    map->capacity = capacity;
    map->numElements = 0;
    map->map = initializeList(print, delete, compare);
    map->print = print;
    map->delete = delete;
    map->compare = compare;

    return map;
}

HashNode *initializeHashNode(int key, void *data) {
    HashNode *node = malloc(sizeof(HashNode));

    node->key = key;
    node->data = initializeNode(data);

    return node;
}

void insertIntoTable(HashMap *map, void *data) {
}

int lookup(HashMap *map, int key) {
    return 0;
}

/************************
    UTILITY FUNCTIONS
************************/

void printHashNode(HashNode *node, void (*print)(void *toBePrinted)) {
    printNode(node->data, print);
}

void deleteHashNode(HashNode *node, void (*delete)(void *toBeDeleted)) {
    deleteNode(node->data, delete);
    free(node);
}

int compareHashNode(Node *first, void *second, int (*compare)(const void *first, const void *second)) {
    return compareNode(first->data, second, compare);
}
