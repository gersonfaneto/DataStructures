#include "./BinaryNode.h"
#include <stdio.h>
#include <stdlib.h>

BinaryNode *CreateBinaryNode(int tValue) {
  BinaryNode *newNode = (BinaryNode *)malloc(sizeof(BinaryNode));

  if (newNode == NULL) {
    printf("Error: Couldn't create a new node!\n");
    exit(1);
  }

  newNode->nValue = tValue;
  newNode->pRight = NULL;
  newNode->pLeft = NULL;

  return newNode;
}

void DestroyBinaryNode(BinaryNode *tNode) {
  if (tNode == NULL) {
    printf("Error: Memory out of reach!\n");
    exit(2);
  }
  free(tNode);
}
