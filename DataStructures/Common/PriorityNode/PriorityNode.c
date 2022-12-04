#include "./PriorityNode.h"
#include <stdio.h>
#include <stdlib.h>

PriorityNode* CreateNode(int tValue, int pLevel) {
  PriorityNode* newNode = (PriorityNode*) malloc(sizeof(PriorityNode));

  if (newNode == NULL) {
    printf("Error: Couldn't create a new Node!\n");
    exit(1);
  }

  newNode -> nValue = tValue;
  newNode -> pLevel = pLevel; 
  newNode -> pNext = NULL;
  
  return newNode;
}

void DestroyNode(PriorityNode* tNode) {
  if (tNode == NULL) {
    printf("Error: Memory out of reach!\n");
    exit(2);
  }
  free(tNode);
}