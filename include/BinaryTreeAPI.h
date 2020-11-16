#ifndef _BINARY_TREE_API_
#define _BINARY_TREE_API_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Struct for Binary Tree Nodes.
 **/
typedef struct node {
  void* data;
  struct node* left;
  struct node* right;
} Node;

/**
 * Struct for a Binary Tree. Contains a pointer to the root, number of nodes, and pointer to helper functions.
 **/
typedef struct binaryTree {
    Node* root;
    void (*delete)(void* toBeDeleted);
    int (*compare)(const void* first, const void* second);
    void (*print)(void* toBePrinted);
} BinaryTree;

BinaryTree* initializeTree(void (*printFunction)(void *toBePrinted), void (*deleteFucntion)(void *toBeDeleted), int (*compareFunction)(const void *first, const void *second));
Node* initializeNode(void* data);

void insertData(BinaryTree* tree, void* toInsert);
void insertNode(Node* node, void* toInsert, int (*compare)(const void *first, const void *second));

void removeData(BinaryTree* tree, void* toBeRemoved);
void removeNode(BinaryTree* tree, Node* node, void* toBeRemoved);

void printPostorder(BinaryTree* tree);
void printPreorder(BinaryTree* tree);
void printInorder(BinaryTree* tree);
void printPostorderNode(Node* node, void (*print)(void *toBePrinted));
void printPreorderNode(Node* node, void (*print)(void *toBePrinted));
void printInorderNode(Node* node, void (*print)(void *toBePrinted));

int sizeTree(BinaryTree* tree);
itn sizeNode(Node* node);

void freeNode(Node* node, void (*delete)(void *toBeDeleted));
void freeRoot(Node* root, void (*delete)(void *toBeDeleted));
void freeTree(BinaryTree* tree);

#endif
