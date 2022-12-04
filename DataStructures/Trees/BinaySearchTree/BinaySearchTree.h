#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "../../Common/BinaryNode/BinaryNode.h"

typedef struct BinarySearchTree {

  BinaryNode* tRoot;

  void (*FreeAll_Binary)(BinaryNode** tCursor);
  void (*DisplayTree_Binary)(BinaryNode* tCursor, int inLevel);
  void (*DisplayPreOrder_Binary)(BinaryNode* tCursor);
  void (*DisplayInOrder_Binary)(BinaryNode* tCursor);
  void (*DisplayPostOrder_Binary)(BinaryNode* tCursor);
  void (*InsertElement_Binary)(BinaryNode** tCursor, int tValue);
  int (*RemoveElement_Binary)(BinaryNode** tCursor, int tValue);
  int (*FindElement_Binary)(BinaryNode* tCursor, int tValue);
  int (*GetHeight_Binary)(BinaryNode* tCursor);
  int (*QntNodes_Binary)(BinaryNode* tCursor);
  int (*GetMin_Binary)(BinaryNode* tCursor);
  int (*GetMax_Binary)(BinaryNode* tCursor);

} BinarySearchTree;

BinarySearchTree BST_Constructor(void);

#endif 
