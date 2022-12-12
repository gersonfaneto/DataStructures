#ifndef PRIORITYNODE_H
#define PRIORITYNODE_H

typedef struct PriorityNode {

  int nValue;
  int pLevel;
  struct PriorityNode *pNext;

} PriorityNode;

PriorityNode *CreatePriorityNode(int tValue, int pLevel);
void DestroyPriorityNode(PriorityNode *tNode);

#endif
