#include "./AVLTree.h"
#include <stdio.h>
#include <stdlib.h>

void FreeTree_AVL(AVLNode** tCursor) {
  if ((*tCursor) != NULL) {
    FreeTree_AVL(&(*tCursor) -> pLeft);
    FreeTree_AVL(&(*tCursor) -> pRight);
    DestroyAVLNode((*tCursor));
    (*tCursor) = NULL;
  }
}

void DisplayTree_AVL(AVLNode* tCursor, int inLevel) {
  if (tCursor != NULL) {
    DisplayTree_AVL(tCursor -> pRight, inLevel + 1);

    printf("\n");
    for (int i = 0; i < inLevel; i++) {
      printf("    ");
    }

    printf("%d\n", tCursor -> nValue);

    DisplayTree_AVL(tCursor -> pLeft, inLevel + 1);
  }
}

void DisplayPreOrder_AVL(AVLNode* tCursor) {
  if (tCursor != NULL) {
    printf("%d ", tCursor -> nValue);
    DisplayPreOrder_AVL(tCursor -> pLeft);
    DisplayPreOrder_AVL(tCursor -> pRight);
  }
}

void DisplayInOrder_AVL(AVLNode* tCursor) {
  if (tCursor != NULL) {
    DisplayInOrder_AVL(tCursor -> pLeft);
    printf("%d ", tCursor -> nValue);
    DisplayInOrder_AVL(tCursor -> pRight);
  }
}

void DisplayPostOrder_AVL(AVLNode* tCursor) {
  if (tCursor != NULL) {
    DisplayPostOrder_AVL(tCursor -> pLeft);
    DisplayPostOrder_AVL(tCursor -> pRight);
    printf("%d ", tCursor -> nValue);
  }
}

int GetMin_AVL(AVLNode* tCursor) {
  if (tCursor == NULL) {
    return -1;
  }
  else if (tCursor -> pLeft == NULL) {
    return tCursor -> nValue;
  }
  return GetMin_AVL(tCursor -> pLeft);
}

int GetMax_AVL(AVLNode* tCursor) {
  if (tCursor == NULL) {
    return -1;
  }
  else if (tCursor -> pRight == NULL) {
    return tCursor -> nValue;
  }
  return GetMax_AVL(tCursor -> pRight);
}

int QntNodes_AVL(AVLNode* tCursor) {
  if (tCursor == NULL) {
    return 0;
  }
  return 1 + QntNodes_AVL(tCursor -> pLeft) + QntNodes_AVL(tCursor -> pRight);
}

int GetHeight_AVL(AVLNode* tCursor) {
  if (tCursor == NULL) {
    return -1;
  }
  else {
    int leftHeight = GetHeight_AVL(tCursor -> pLeft);
    int rightHeight = GetHeight_AVL(tCursor -> pRight);
    if (leftHeight > rightHeight) {
      return leftHeight + 1;
    }
    else {
      return rightHeight + 1;
    }
  }
}

int FindMax(int firstValue, int secondValue) {
  return (firstValue > secondValue) ? firstValue : secondValue;
}

int GetBalanceFactor(AVLNode* tNode) {
  if (tNode == NULL) {
    return 0;
  }
  return GetHeight_AVL(tNode -> pLeft) - GetHeight_AVL(tNode -> pRight); 
}

AVLNode* RotateLef(AVLNode* tNode) {
  AVLNode* A = tNode -> pRight; 
  AVLNode* B = A -> pLeft; 

  A -> pLeft = tNode;
  tNode -> pRight = B;

  tNode -> nHeight = FindMax(GetHeight_AVL(tNode -> pLeft), GetHeight_AVL(tNode -> pRight)) + 1;
  A -> nHeight = FindMax(GetHeight_AVL(A -> pLeft), GetHeight_AVL(A -> pRight)) + 1;

  return A;
}

AVLNode* RotateRight(AVLNode* tNode) {
  AVLNode* A = tNode -> pLeft; 
  AVLNode* B = A -> pRight; 

  A -> pRight = tNode;
  tNode -> pLeft = B;

  tNode -> nHeight = 1 + FindMax(GetHeight_AVL(tNode -> pLeft), GetHeight_AVL(tNode -> pRight));
  A -> nHeight = 1 + FindMax(GetHeight_AVL(A -> pLeft), GetHeight_AVL(A -> pRight));
  
  return A;
}

int FindElement_AVL(AVLNode* tCursor, int tValue) {
  if (tCursor == NULL) {
    return 0;
  }
  else if (tCursor -> nValue == tValue) {
    return 1;
  }
  else {
    if (tValue > tCursor -> nValue) {
      return FindElement_AVL(tCursor -> pRight, tValue);
    }
    else {
      return FindElement_AVL(tCursor -> pLeft, tValue);
    }
  }
}

void RebalanceNodes(AVLNode** tNode, int tValue) {
  (*tNode) -> nHeight = 1 + FindMax(GetHeight_AVL((*tNode) -> pLeft), 
      GetHeight_AVL((*tNode) -> pRight));

  int BalanceFactor = GetBalanceFactor(*tNode);

  if (BalanceFactor < -1 && GetBalanceFactor((*tNode) -> pRight) <= 0) {
    (*tNode) = RotateLef(*tNode);
  }
  else if (BalanceFactor < -1 && GetBalanceFactor((*tNode) -> pRight) > 0) {
    (*tNode) -> pRight = RotateRight((*tNode) -> pRight);
    (*tNode) = RotateLef((*tNode));
  }
  else if (BalanceFactor > 1 && GetBalanceFactor((*tNode) -> pLeft) >= 0) {
    (*tNode) = RotateRight(*tNode);
  }
  else if (BalanceFactor > 1 && GetBalanceFactor((*tNode) -> pLeft) < 0) {
    (*tNode) -> pLeft = RotateLef((*tNode) -> pLeft);
    (*tNode) = RotateRight((*tNode));
  }
}

void InsertElement_AVL(AVLNode** tCursor, int tValue) {
  if ((*tCursor) == NULL) {
    (*tCursor) = CreateAVLNode(tValue); 
  }
  else if ((*tCursor) -> pRight == NULL && tValue > (*tCursor) -> nValue) {
    (*tCursor) -> pRight = CreateAVLNode(tValue);
  }
  else if ((*tCursor) -> pLeft == NULL && tValue <= (*tCursor) -> nValue) {
    (*tCursor) -> pLeft = CreateAVLNode(tValue);
  }
  else {
    if (tValue > (*tCursor) -> nValue) {
      InsertElement_AVL(&(*tCursor) -> pRight, tValue);
    }
    else {
      InsertElement_AVL(&(*tCursor) -> pLeft, tValue);
    }
  }
  RebalanceNodes(tCursor, tValue);
}

int RemoveElement_AVL(AVLNode** tCursor, int tValue) {
  int currValue = (*tCursor) -> nValue;
  if (*tCursor == NULL) {
    printf("Error: Tree is empty or element wasn't found!\n");
    exit(3);
  }
  else if (tValue > currValue) {
    return RemoveElement_AVL(&(*tCursor) -> pRight, tValue);
  }
  else if (tValue < currValue) {
    return RemoveElement_AVL(&(*tCursor) -> pLeft, tValue);
  }
  else {
    if ((*tCursor) -> pRight == NULL && (*tCursor) -> pLeft == NULL) {
      DestroyAVLNode((*tCursor)), (*tCursor) = NULL;
    }
    else if ((*tCursor) -> pLeft == NULL) {
      AVLNode* toRemove = (*tCursor);
      (*tCursor) = (*tCursor) -> pRight;
      DestroyAVLNode(toRemove);
    }
    else if ((*tCursor) -> pRight == NULL) {
      AVLNode* toRemove = (*tCursor);
      (*tCursor) = (*tCursor) -> pLeft;
      DestroyAVLNode(toRemove);
    }
    else {
      int minValue = GetMin_AVL((*tCursor) -> pRight);
      (*tCursor) -> nValue = minValue;
      RemoveElement_AVL(&(*tCursor) -> pRight, minValue);
    }

  }
  if (*tCursor != NULL) {
    RebalanceNodes(tCursor, tValue);
  }

  return currValue;
}

AVLTree AVLT_Constructor(void) {
  AVLTree AVLTree;

  AVLTree.tRoot = NULL;

  AVLTree.FreeTree_AVL = FreeTree_AVL;
  AVLTree.DisplayTree_AVL = DisplayTree_AVL;
  AVLTree.DisplayPreOrder_AVL = DisplayPreOrder_AVL;
  AVLTree.DisplayInOrder_AVL = DisplayInOrder_AVL;
  AVLTree.DisplayPostOrder_AVL = DisplayPostOrder_AVL;
  AVLTree.InsertElement_AVL = InsertElement_AVL;
  AVLTree.RemoveElement_AVL = RemoveElement_AVL;
  AVLTree.FindElement_AVL = FindElement_AVL;
  AVLTree.QntNodes_AVL = QntNodes_AVL;
  AVLTree.GetHeight_AVL = GetHeight_AVL;
  AVLTree.GetMax_AVL = GetMax_AVL;
  AVLTree.GetMin_AVL = GetMin_AVL;

  return AVLTree;
}
