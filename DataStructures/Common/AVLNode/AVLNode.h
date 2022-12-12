#ifndef AVLNODE_H
#define AVLNODE_H

typedef struct AVLNode {

  int nValue;
  int nHeight;
  struct AVLNode *pRight;
  struct AVLNode *pLeft;

} AVLNode;

AVLNode *CreateAVLNode(int tValue);
void DestroyAVLNode(AVLNode *tNode);

#endif
