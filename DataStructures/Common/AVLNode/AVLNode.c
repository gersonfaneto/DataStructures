#include "./AVLNode.h"
#include <stdio.h>
#include <stdlib.h>

AVLNode* CreateAVLNode(int tValue) {
  AVLNode* newNode = (AVLNode*) malloc(sizeof(AVLNode));

  if (newNode == NULL) {
    printf("Error: Couldn't create a new Node!\n");
    exit(1);
  }

  newNode -> nValue = tValue;
  newNode -> nHeight = 1;
  newNode -> pRight = NULL;
  newNode -> pLeft = NULL;

  return newNode;
}

void DestroyAVLNode(AVLNode* tNode) {
  if (tNode == NULL) {
    printf("Error: Memory out of reach!\n");
    exit(2);
  }
  free(tNode);
}
