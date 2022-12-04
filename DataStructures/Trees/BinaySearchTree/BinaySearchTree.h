#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "../../Common/BinaryNode/BinaryNode.h"

typedef struct BinarySearchTree {

  BinaryNode* tRoot;

  void (*FreeAll)(BinaryNode** tCursor);
  void (*DisplayTree)(BinaryNode* tCursor, int inLevel);
  void (*DisplayPreOrder)(BinaryNode* tCursor);
  void (*DisplayInOrder)(BinaryNode* tCursor);
  void (*DisplayPostOrder)(BinaryNode* tCursor);
  void (*InsertElement)(BinaryNode** tCursor, int tValue);
  int (*RemoveElement)(BinaryNode** tCursor, int tValue);
  int (*FindElement)(BinaryNode* tCursor, int tValue);
  int (*GetHeight)(BinaryNode* tCursor);
  int (*QntNodes)(BinaryNode* tCursor);
  int (*GetMin)(BinaryNode* tCursor);
  int (*GetMax)(BinaryNode* tCursor);

} BinarySearchTree;

BinarySearchTree BST_Constructor(void);

#endif 
