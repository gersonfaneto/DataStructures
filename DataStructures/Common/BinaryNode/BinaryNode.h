#ifndef BINARYNODE_H
#define BINARYNODE_H

typedef struct BinaryNode {

  int nValue;
  struct BinaryNode* pRight;
  struct BinaryNode* pLeft;

} BinaryNode;

BinaryNode* CreateNode(int tValue);
void DestroyNode(BinaryNode* tNode);

#endif 
