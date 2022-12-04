#ifndef BINARYNODE_H
#define BINARYNODE_H

typedef struct BinaryNode {

  int nValue;
  struct BinaryNode* pRight;
  struct BinaryNode* pLeft;

} BinaryNode;

BinaryNode* CreateBinaryNode(int tValue);
void DestroyBinaryNode(BinaryNode* tNode);

#endif 
