#ifndef STACK_H
#define STACK_H

#include "../Common/Node/Node.h"

typedef struct Stack {
  Node* sHead;
  int sSize;

  void (*DisplayContent)(struct Stack tStack);
  void (*FreeAll)(struct Stack* tStack);
  void (*Insert)(struct Stack* tStack, int tValue);
  int (*Remove)(struct Stack* tStack);
  int (*Peek)(struct Stack tStack);

} Stack;

Stack S_Constructor(void);

#endif 
