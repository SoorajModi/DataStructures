/**
 * Sooraj Modi
 * Created September, 2020
 */
#include "BinaryTreeAPI.h"

/************************
        FUNCTIONS
************************/

BinaryTree* initializeTree(void (*printFunction)(void *toBePrinted), void (*deleteFucntion)(void *toBeDeleted), int (*compareFunction)(const void *first, const void *second)) {
  BinaryTree* tree = malloc(sizeof(BinaryTree));

  tree->root = NULL;
  tree->print = printFunction;
  tree->delete = deleteFunction;
  tree->compare = compareFunction;

  return tree;
}

Node* initializeNode(void* data) {
  Node* node = malloc(sizeof(Node));

  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return node;
}

void insertData(BinaryTree* tree, void* toInsert) {
  insertNode(tree->root, toInsert, tree->compare);
}

void insertNode(Node* node, void* toInsert, int (*compare)(const void *first, const void *second)) {
  if(compare(node->data, toInsert) >= 0) {
    if (node->right) {
      insertNode(node->right, toInsert, compare);
    } else {
      root->right = initializeNode(toInsert);
    }
  } else {
    if (node->left) {
      insertNode(node->left, toInsert, compare);
    } else {
      root->left = initializeNode(toInsert);
    }
  }
}

void removeData(BinaryTree* tree, void* toBeRemoved) {
  removeNode(tree, tree->root, toBeRemoved);
}

void removeNode(BinaryTree* tree, Node* node, void* toBeRemoved) {
  int result = tree->compare(node->data, toBeRemoved);
  if(result == 0) {
    freeRoot(node, tree->delete);
  } else if (result > 0) {
    removeNode(tree, node->right, toBeRemoved);
  } else {
    removeNode(tree, node->left, toBeRemoved);
  }
}

void printPostorder(BinaryTree* tree) {
  printPostorderNode(tree->root, tree->print);
}

void printPreorder(BinaryTree* tree) {
  printPreorderNode(tree->root, tree->print);
}

void printInorder(BinaryTree* tree) {
  printInorderNode(tree->root, tree->print);
}

void printPostorderNode(Node* node, void (*print)(void *toBePrinted)) {
  if (node == NULL) return;
  printPostorderNode(node->left);
  printPostorderNode(node->right);
  print(node->data);
}

void printPreorderNode(Node* node, void (*print)(void *toBePrinted)) {
  if (node == NULL) return;
  print(node->data);
  printPreorderNode(node->left);
  printPreorderNode(node->right);
}

void printInorderNode(Node* node, void (*print)(void *toBePrinted)) {
  if (node == NULL) return;
  printInorderNode(node->left);
  print(node->data);
  printInorderNode(node->right);
}

int sizeTree(BinaryTree* tree) {
  return sizeNode(tree->root);
}

int sizeNode(Node* node) {
  if(node == NULL) return 0;

  int num = 1;
  num += sizeNode(node->left);
  num += sizeNode(node->right);

  return num;
}

void freeNode(Node* node, void (*delete)(void *toBeDeleted)) {
  delete(node->data);
  free(node);
}

void freeRoot(Node* root, void (*delete)(void *toBeDeleted)) {
  if(root == NULL) return;

  freeTree(root->left, delete);
  freeTree(root->right, delete);
  freeNode(root, delete);
}

void freeTree(BinaryTree* tree) {
  freeRoot(tree->root, tree->delete);
  free(tree);
}