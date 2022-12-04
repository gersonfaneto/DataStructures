#ifndef NODE_H
#define NODE_H

typedef struct Node {

  int nValue;
  struct Node* pNext;

} Node;

Node* CreateNode(int tValue);
void DestroyNode(Node* tNode);

#endif 
