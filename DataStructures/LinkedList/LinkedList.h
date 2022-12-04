#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../Common/Node/Node.h"

typedef struct LinkedList {

  Node* lHead;
  int lSize;

  void (*DisplayList)(struct LinkedList tList);
  void (*FreeList)(struct LinkedList* tList);
  void (*InsertEnd)(struct LinkedList* tList, char* tValue);
  void (*InsertBeg)(struct LinkedList* tList, char* tValue);
  void (*InsertAt)(struct LinkedList* tList, char* tValue, int tIndex);
  char* (*FindValue)(struct LinkedList tList, int tIndex);
  int (*FindIndex)(struct LinkedList tList, char* tValue);
  char* (*PopEnd)(struct LinkedList* tList);
  char* (*PopBeg)(struct LinkedList* tList);
  char* (*PopAt)(struct LinkedList* tList, int tIndex);

} LinkedList;

LinkedList LL_Constructor(void);

#endif
