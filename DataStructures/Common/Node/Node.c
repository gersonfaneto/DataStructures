#include "./Node.h"
#include <stdio.h>
#include <stdlib.h>

Node *CreateNode(char *tValue) {
  Node *newNode = (Node *)malloc(sizeof(Node));

  if (newNode == NULL) {
    printf("Error: Couldn´t create a new Node!\n");
    exit(1);
  }

  newNode->nValue = tValue;
  newNode->pNext = NULL;

  return newNode;
}

void DestroyNode(Node *tNode) {
  if (tNode == NULL) {
    printf("Error: Memory out of reach!\n");
    exit(2);
  }
  free(tNode);
}
