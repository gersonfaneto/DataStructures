#include "./Stack.h"
#include <stdio.h>
#include <stdlib.h>

void DisplayStack(Stack tStack) {
  if (tStack.sHead == NULL) {
    printf("[]\n");
  } else {
    Node *sCursor = tStack.sHead;
    printf("[");
    while (sCursor->pNext != NULL) {
      printf("%s, ", sCursor->nValue);
      sCursor = sCursor->pNext;
    }
    printf("%s]\n", sCursor->nValue);
  }
}

void FreeStack(Stack *tStack) {
  if (tStack->sHead != NULL) {
    Node *sCursor = tStack->sHead;
    while (sCursor->pNext != NULL) {
      Node *toDestroy = sCursor;
      sCursor = sCursor->pNext;
      DestroyNode(toDestroy);
    }
    DestroyNode(sCursor);
    tStack->sHead = NULL;
    tStack->sSize = 0;
  }
}

void Push(Stack *tStack, char *targetValue) {
  Node *toInsert = CreateNode(targetValue);
  if (tStack->sHead == NULL) {
    tStack->sHead = toInsert;
  } else {
    toInsert->pNext = tStack->sHead;
    tStack->sHead = toInsert;
  }
  tStack->sSize++;
}

char *Pop(Stack *tStack) {
  char *RemovedValue = NULL;

  if (tStack->sHead == NULL) {
    printf("Error: Index out of range!\n");
    FreeStack(tStack);
    exit(1);
  } else {
    Node *toRemove = tStack->sHead;
    RemovedValue = toRemove->nValue;

    tStack->sHead = tStack->sHead->pNext;
    tStack->sSize--;

    free(toRemove);
  }

  return RemovedValue;
}

char *GetTop(Stack tStack) {
  if (tStack.sHead == NULL) {
    printf("Error: Index out of range!\n");
    return NULL;
  }
  return tStack.sHead->nValue;
}

Stack S_Constructor(void) {
  Stack Stack;

  Stack.sHead = NULL;
  Stack.sSize = 0;

  Stack.DisplayStack = DisplayStack;
  Stack.FreeStack = FreeStack;
  Stack.Push = Push;
  Stack.Pop = Pop;
  Stack.GetTop = GetTop;

  return Stack;
}
