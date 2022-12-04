#ifndef AVLNODE_H
#define AVLNODE_H

typedef struct AVLNode {

  int nValue;
  int nHeight;
  struct AVLNode* pRight;
  struct AVLNode* pLeft;

} AVLNode;

AVLNode* CreateNode(int tValue);
void DestroyNode(AVLNode* tNode);

#endif
