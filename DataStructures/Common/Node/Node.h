#ifndef NODE_H
#define NODE_H

typedef struct Node {

  char *nValue;
  struct Node *pNext;

} Node;

Node *CreateNode(char *tValue);
void DestroyNode(Node *tNode);

#endif
