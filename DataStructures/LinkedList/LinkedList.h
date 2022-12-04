#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../Common/Node/Node.h"

typedef struct LinkedList {

  Node* lHead;
  int lSize;

  void (*DisplayContent)(struct LinkedList tList);
  void (*FreeAll)(struct LinkedList* tList);
  void (*InsertEnd)(struct LinkedList* tList, int tValue);
  void (*InsertBeg)(struct LinkedList* tList, int tValue);
  void (*InsertAt)(struct LinkedList* tList, int tValue, int tIndex);
  int (*FindValue)(struct LinkedList tList, int tIndex);
  int (*FindIndex)(struct LinkedList tList, int tValue);
  int (*PopEnd)(struct LinkedList* tList);
  int (*PopBeg)(struct LinkedList* tList);
  int (*PopAt)(struct LinkedList* tList, int tIndex);

} LinkedList;

LinkedList LL_Constructor(void);

#endif
