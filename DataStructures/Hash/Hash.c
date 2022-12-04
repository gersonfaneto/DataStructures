#include "./Hash.h"
#include <stdio.h>
#include <stdlib.h>

void DisplayTable(Hash* toDisplay) {
  for (unsigned int i = 0; i < toDisplay -> hashSize; i++) {
    if (toDisplay -> hashTables[i] != NULL) {
      printf("{%d: [", i + 1);
      Node* lCursor = toDisplay -> hashTables[i];
      while (lCursor -> pNext != NULL) {
        printf("%s, ", lCursor -> nValue);
        lCursor = lCursor -> pNext;
      }
      printf("%s]}\n", lCursor -> nValue);
    }
  }
}

void FreeAll(Hash* tHash) {
  for (unsigned int i = 0; i < tHash -> hashSize; i++) {
    Node* lCursor = tHash -> hashTables[i];
    while (lCursor != NULL) {
      Node* toDestroy = lCursor;
      lCursor = lCursor -> pNext;
      DestroyNode(toDestroy);
    }
  }
  free(tHash -> hashTables);
}

void InsertNode(Hash* tHash, char* tValue) {
  Node* toInsert = CreateNode(tValue);
  unsigned int hashSize = tHash -> hashSize;
  unsigned int i = GetHashCode(tValue, hashSize);

  toInsert -> pNext = tHash -> hashTables[i];
  tHash -> hashTables[i] = toInsert;

  tHash -> hashPopulation++;

  if (tHash -> hashPopulation / (float) tHash -> hashSize >= 0.7) {
    *tHash = RehashTable(tHash);
  }
}

char* RemoveNode(Hash* tHash, char* tValue) {
  char* removedValue = NULL;
  unsigned int hashSize = tHash -> hashSize;
  unsigned int i = GetHashCode(tValue, hashSize);

  Node* lCursor = tHash -> hashTables[i];

  if (lCursor == NULL || (lCursor -> pNext == NULL && 
      lCursor -> nValue != tValue)) {
    printf("Error: Key not found!\n");
    exit(1);
  }
  else if (lCursor -> nValue == tValue) {
    Node* removedNode = lCursor;
    removedValue = lCursor -> nValue; 
    tHash -> hashTables[i] = removedNode -> pNext;
    DestroyNode(removedNode);
  }
  else {
    while (lCursor -> pNext -> pNext != NULL 
        && lCursor -> nValue != tValue) {
      lCursor = lCursor -> pNext;
    }

    if (lCursor -> pNext -> nValue == tValue) {
      Node* removedNode = lCursor -> pNext;
      removedValue = removedNode -> nValue;
      removedValue = removedNode -> nValue;
      lCursor -> pNext = removedNode -> pNext;
      DestroyNode(removedNode);
    }
  }

  tHash -> hashPopulation--;

  return removedValue;
}

char* GetNode(Hash* tHash, char* tValue) {
  char* foundValue = NULL;
  unsigned int hashSize = tHash -> hashSize;
  unsigned int i = GetHashCode(tValue, hashSize);

  Node* lCursor = tHash -> hashTables[i];

  if (lCursor == NULL || (lCursor -> pNext == NULL && 
      lCursor -> nValue != tValue)) {
    printf("Error! Key Not Found...\n");
    exit(2);
  }

  while (lCursor -> pNext != NULL && lCursor -> nValue != tValue) {
    lCursor = lCursor -> pNext;
  }

  foundValue = lCursor -> nValue;

  return foundValue;
}

unsigned int GetHashCode(char* tValue, unsigned int hashSize) {
  unsigned int hashCode = 0;
  int i = 0;

  while (tValue[i] != '\0') {
    hashCode += tValue[i] * (i * i);
    i++;
  }

  return hashCode % hashSize;
}

Hash RehashTable(Hash* tHash) {
  unsigned int oldSize = tHash -> hashSize;
  unsigned int newSize = oldSize * 2;

  Hash reHashed = H_Constructor(newSize);

  for (unsigned int i = 0; i < oldSize; i++) {
      Node* lCursor = tHash -> hashTables[i];
      while (lCursor != NULL) {
        char* toRealoc = lCursor -> nValue;
        lCursor = lCursor -> pNext;
        InsertNode(&reHashed, toRealoc);
        RemoveNode(tHash, toRealoc);
      }
  }

  tHash -> FreeAll(tHash);

  return reHashed;
}

Hash H_Constructor(unsigned int hashSize) {
  Hash Hash;

  Hash.hashTables = (Node**) malloc(hashSize * sizeof(Node*));
  for (unsigned int i = 0; i < hashSize; i++) {
    Hash.hashTables[i] = NULL;
  }
  
  Hash.hashPopulation = 0;
  Hash.hashSize = hashSize;
  Hash.Find = GetNode;
  Hash.Insert = InsertNode;
  Hash.Remove = RemoveNode;
  Hash.DisplayTable = DisplayTable;
  Hash.FreeAll = FreeAll;

  return Hash;
}

