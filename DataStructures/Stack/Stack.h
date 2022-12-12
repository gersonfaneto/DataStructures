#ifndef STACK_H
#define STACK_H

#include "../Common/Node/Node.h"

typedef struct Stack {
  Node *sHead;
  int sSize;

  void (*DisplayStack)(struct Stack tStack);
  void (*FreeStack)(struct Stack *tStack);
  void (*Push)(struct Stack *tStack, char *tValue);
  char *(*Pop)(struct Stack *tStack);
  char *(*GetTop)(struct Stack tStack);

} Stack;

Stack S_Constructor(void);

#endif
