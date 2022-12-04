#include "./LinkedList.h"

#include <stdio.h>
#include <stdlib.h>

void DisplayContent(LinkedList tList) {
  if (tList.lHead == NULL) {
    printf("[]\n");
  }
  else {
    Node* lCursor = tList.lHead;
    printf("[");
    while (lCursor -> pNext != NULL) {
      printf("%s, ", lCursor -> nValue);
      lCursor = lCursor -> pNext;
    }
    printf("%s]\n", lCursor -> nValue);
  }
}

void FreeAll(LinkedList* tList) {
  if (tList -> lHead != NULL) {
    Node* lCursor = tList -> lHead;
    while (lCursor -> pNext != NULL) {
      Node* currNode = lCursor;
      lCursor = lCursor -> pNext;
      DestroyNode(currNode);
    }
    DestroyNode(lCursor);
    tList -> lHead = NULL;
    tList -> lSize = 0;
  }
}

void InsertEnd(LinkedList* tList, char* tValue) {
  Node* toInsert = CreateNode(tValue);
  if (tList -> lHead == NULL) {
    tList -> lHead = toInsert;
  }
  else {
    Node* lCursor = tList -> lHead;
    while (lCursor -> pNext != NULL) {
      lCursor = lCursor -> pNext;
    }
    lCursor -> pNext = toInsert;
  }
  tList -> lSize++;
}

void InsertBeg(LinkedList* tList, char* tValue) {
  Node* toInsert = CreateNode(tValue);
  if (tList -> lHead == NULL) {
    tList -> lHead = toInsert;
  }
  else {
    toInsert -> pNext = tList -> lHead;
    tList -> lHead = toInsert;
  }
  tList -> lSize++;
}

void InsertAt(LinkedList* tList, char* tValue, int tIndex) {
  if (tIndex < 0 || tIndex > (tList -> lSize)) {
    printf("Error: Index out of range!\n");
    FreeAll(tList);
    exit(1);
  }
  else if (tIndex == 0) {
    InsertBeg(tList, tValue);
    return;
  }
  else if (tIndex == tList -> lSize) {
    InsertEnd(tList, tValue);
    return;
  }
  Node* lCursor = tList -> lHead;
  Node* toInsert = CreateNode(tValue);
  for (int i = 0; i < (tIndex - 1); i++) {
    lCursor = lCursor -> pNext;
  }
  toInsert -> pNext = lCursor -> pNext;
  lCursor -> pNext = toInsert;
  tList -> lSize++;
}

char* FindValue(LinkedList tList, int tIndex) {
  if (tIndex < 0 || tIndex > (tList.lSize - 1)) {
    printf("Error: Index out of range!\n");
    return NULL;
  }
  Node* lCursor = tList.lHead;
  for (int i = 0; i < tIndex; i++) {
    lCursor = lCursor -> pNext;
  }
  return lCursor -> nValue;
}

int FindIndex(LinkedList tList, char* tValue) {
  if (tList.lHead != NULL) {
    Node* lCursor = tList.lHead;
    int tIndex = 0;
    while (lCursor != NULL) {
      if (lCursor -> nValue == tValue) {
        return tIndex;
      }
      lCursor = lCursor -> pNext;
      tIndex++;
    }
  }
  return -1;
}

char* PopEnd(LinkedList* tList) {
  char* removedValue = NULL;
  if (tList -> lHead == NULL) {
    printf("Error: Index out of range!\n");
    FreeAll(tList);
    exit(3);
  }
  else if (tList -> lHead -> pNext == NULL) {
    Node* toRemove = tList -> lHead;
    removedValue = toRemove -> nValue;

    tList -> lHead = NULL;
    tList -> lSize = 0;

    free(toRemove);
  }
  else {    
    Node* lCursor = tList -> lHead;
    while (lCursor -> pNext -> pNext != NULL) {
      lCursor = lCursor -> pNext;
    }
    Node* toRemove = lCursor -> pNext;
    removedValue = toRemove -> nValue;
    
    lCursor -> pNext = NULL;
    tList -> lSize--;

    free(toRemove);
  }

  return removedValue;
}

char* PopBeg(LinkedList* tList) {
  char* removedValue = NULL;

  if (tList -> lHead == NULL) {
    printf("Error! List Index Out Of Range...\n");
    FreeAll(tList);
    exit(4);
  }
  else  {
    Node* toRemove = tList -> lHead;
    removedValue = toRemove -> nValue;

    tList -> lHead = tList -> lHead -> pNext;
    tList -> lSize--;

    free(toRemove);
  }

  return removedValue;
}

char* PopAt(LinkedList* tList, int targetIndex) {
  char* removedValue = NULL;

  if (targetIndex < 0 || targetIndex >= tList -> lSize ||
        tList -> lHead == NULL) {
    printf("Error! List Index Out Of Range...\n");
    FreeAll(tList);
    exit(5);
  }
  else {
    if (targetIndex == 0) {
      removedValue = PopBeg(tList);
    }
    else if (targetIndex == (tList -> lSize - 1)) {
      removedValue = PopEnd(tList);
    }
    else {
      Node* lCursor = tList -> lHead;
      for (int i = 0; i < targetIndex - 1; i++) {
        lCursor = lCursor -> pNext;
      }
      Node* toRemove = lCursor -> pNext;
      removedValue = toRemove -> nValue;

      lCursor -> pNext = lCursor -> pNext -> pNext;
      tList -> lSize--;

      free(toRemove);
    }
  }

  return removedValue;
}

LinkedList LL_Constructor(void) {
  LinkedList LinkesList;

  LinkesList.lHead = NULL;
  LinkesList.lSize = 0;

  LinkesList.DisplayContent = DisplayContent;
  LinkesList.FreeAll = FreeAll;
  LinkesList.InsertEnd = InsertEnd;
  LinkesList.InsertBeg = InsertBeg;
  LinkesList.InsertAt = InsertAt;
  LinkesList.FindValue = FindValue;
  LinkesList.FindIndex = FindIndex;
  LinkesList.PopEnd = PopEnd;
  LinkesList.PopBeg = PopBeg;
  LinkesList.PopAt = PopAt;

  return LinkesList;
}

