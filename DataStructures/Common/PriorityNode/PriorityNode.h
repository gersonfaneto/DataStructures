#ifndef PRIORITYNODE_H
#define PRIORITYNODE_H

typedef struct PriorityNode {

  int nValue;
  int pLevel;
  struct PriorityNode* pNext;

} PriorityNode;

PriorityNode* CreateNode(int tValue, int pLevel);
void DestroyNode(PriorityNode* tNode);

#endif 
