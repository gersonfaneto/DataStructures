#ifndef AVLTREE_H
#define AVLTREE_H

#include "../../Common/AVLNode/AVLNode.h"

typedef struct AVLTree {

  AVLNode *tRoot;

  void (*FreeTree_AVL)(AVLNode **tCursor);
  void (*DisplayTree_AVL)(AVLNode *tCursor, int inLevel);
  void (*DisplayPreOrder_AVL)(AVLNode *tCursor);
  void (*DisplayInOrder_AVL)(AVLNode *tCursor);
  void (*DisplayPostOrder_AVL)(AVLNode *tCursor);
  void (*InsertElement_AVL)(AVLNode **tCursor, int tValue);
  int (*RemoveElement_AVL)(AVLNode **tCursor, int tValue);
  int (*FindElement_AVL)(AVLNode *tCursor, int tValue);
  int (*GetHeight_AVL)(AVLNode *tCursor);
  int (*QntNodes_AVL)(AVLNode *tCursor);
  int (*GetMin_AVL)(AVLNode *tCursor);
  int (*GetMax_AVL)(AVLNode *tCursor);

} AVLTree;

AVLTree AVLT_Constructor(void);

#endif
