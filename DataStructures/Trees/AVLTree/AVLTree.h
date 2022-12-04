#ifndef AVLTREE_H
#define AVLTREE_H

#include "../../Common/AVLNode/AVLNode.h"

typedef struct AVLTree {

  AVLNode* tRoot;

  void (*FreeAll)(AVLNode** tCursor);
  void (*DisplayTree)(AVLNode* tCursor, int inLevel);
  void (*DisplayPreOrder)(AVLNode* tCursor);
  void (*DisplayInOrder)(AVLNode* tCursor);
  void (*DisplayPostOrder)(AVLNode* tCursor);
  void (*InsertElement)(AVLNode** tCursor, int tValue);
  int (*RemoveElement)(AVLNode** tCursor, int tValue);
  int (*FindElement)(AVLNode* tCursor, int tValue);
  int (*GetHeight)(AVLNode* tCursor);
  int (*QntNodes)(AVLNode* tCursor);
  int (*GetMin)(AVLNode* tCursor);
  int (*GetMax)(AVLNode* tCursor);

} AVLTree;

AVLTree AVLT_Constructor(void);

#endif
