#ifndef _HASH_MAP_API_
#define _HASH_MAP_API_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Node for the Binary Tree
 **/
typedef struct node {
    void* data;
    struct node* left;
    struct node* right;
} Node;

/**
 * Struct for a Queue. Contains a pointer to the front and end of the Queue and to helper functions.
 **/
typedef struct hashMap {
    Node* root;
    void (*delete)(void* toBeDeleted);
    int (*compare)(const void* first, const void* second);
    void (*print)(void* toBePrinted);
} HashMap;

#endif
