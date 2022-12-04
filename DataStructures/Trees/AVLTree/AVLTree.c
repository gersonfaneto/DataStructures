#include "./AVLTree.h"
#include <stdio.h>
#include <stdlib.h>

void FreeAll(AVLNode** tCursor) {
  if ((*tCursor) != NULL) {
    FreeAll(&(*tCursor) -> pLeft);
    FreeAll(&(*tCursor) -> pRight);
    DestroyAVLNode((*tCursor));
    (*tCursor) = NULL;
  }
}

void DisplayTree(AVLNode* tCursor, int inLevel) {
  if (tCursor != NULL) {
    DisplayTree(tCursor -> pRight, inLevel + 1);

    printf("\n");
    for (int i = 0; i < inLevel; i++) {
      printf("    ");
    }

    printf("%d\n", tCursor -> nValue);

    DisplayTree(tCursor -> pLeft, inLevel + 1);
  }
}

void DisplayPreOder(AVLNode* tCursor) {
  if (tCursor != NULL) {
    printf("%d ", tCursor -> nValue);
    DisplayPreOder(tCursor -> pLeft);
    DisplayPreOder(tCursor -> pRight);
  }
}

void DisplayInOrder(AVLNode* tCursor) {
  if (tCursor != NULL) {
    DisplayInOrder(tCursor -> pLeft);
    printf("%d ", tCursor -> nValue);
    DisplayInOrder(tCursor -> pRight);
  }
}

void DisplayPostOrder(AVLNode* tCursor) {
  if (tCursor != NULL) {
    DisplayPostOrder(tCursor -> pLeft);
    DisplayPostOrder(tCursor -> pRight);
    printf("%d ", tCursor -> nValue);
  }
}

int GetMin(AVLNode* tCursor) {
  if (tCursor == NULL) {
    return -1;
  }
  else if (tCursor -> pLeft == NULL) {
    return tCursor -> nValue;
  }
  return GetMin(tCursor -> pLeft);
}

int GetMax(AVLNode* tCursor) {
  if (tCursor == NULL) {
    return -1;
  }
  else if (tCursor -> pRight == NULL) {
    return tCursor -> nValue;
  }
  return GetMax(tCursor -> pRight);
}

int QntNodes(AVLNode* tCursor) {
  if (tCursor == NULL) {
    return 0;
  }
  return 1 + QntNodes(tCursor -> pLeft) + QntNodes(tCursor -> pRight);
}

int GetHeight(AVLNode* tCursor) {
  if (tCursor == NULL) {
    return -1;
  }
  else {
    int leftHeight = GetHeight(tCursor -> pLeft);
    int rightHeight = GetHeight(tCursor -> pRight);
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
  return GetHeight(tNode -> pLeft) - GetHeight(tNode -> pRight); 
}

AVLNode* RotateLef(AVLNode* tNode) {
  AVLNode* A = tNode -> pRight; 
  AVLNode* B = A -> pLeft; 

  A -> pLeft = tNode;
  tNode -> pRight = B;

  tNode -> nHeight = FindMax(GetHeight(tNode -> pLeft), GetHeight(tNode -> pRight)) + 1;
  A -> nHeight = FindMax(GetHeight(A -> pLeft), GetHeight(A -> pRight)) + 1;

  return A;
}

AVLNode* RotateRight(AVLNode* tNode) {
  AVLNode* A = tNode -> pLeft; 
  AVLNode* B = A -> pRight; 

  A -> pRight = tNode;
  tNode -> pLeft = B;

  tNode -> nHeight = 1 + FindMax(GetHeight(tNode -> pLeft), GetHeight(tNode -> pRight));
  A -> nHeight = 1 + FindMax(GetHeight(A -> pLeft), GetHeight(A -> pRight));
  
  return A;
}

int FindElement(AVLNode* tCursor, int tValue) {
  if (tCursor == NULL) {
    return 0;
  }
  else if (tCursor -> nValue == tValue) {
    return 1;
  }
  else {
    if (tValue > tCursor -> nValue) {
      return FindElement(tCursor -> pRight, tValue);
    }
    else {
      return FindElement(tCursor -> pLeft, tValue);
    }
  }
}

void RebalanceNodes(AVLNode** tNode, int tValue) {
  (*tNode) -> nHeight = 1 + FindMax(GetHeight((*tNode) -> pLeft), 
      GetHeight((*tNode) -> pRight));
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

void InsertElement(AVLNode** tCursor, int tValue) {
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
      InsertElement(&(*tCursor) -> pRight, tValue);
    }
    else {
      InsertElement(&(*tCursor) -> pLeft, tValue);
    }
  }
  RebalanceNodes(tCursor, tValue);
}

int RemoveElement(AVLNode** tCursor, int tValue) {
  int currValue = (*tCursor) -> nValue;
  if (*tCursor == NULL) {
    printf("Error: Tree is empty or element wasn't found!\n");
    exit(3);
  }
  else if (tValue > currValue) {
    return RemoveElement(&(*tCursor) -> pRight, tValue);
  }
  else if (tValue < currValue) {
    return RemoveElement(&(*tCursor) -> pLeft, tValue);
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
      int minValue = GetMin((*tCursor) -> pRight);
      (*tCursor) -> nValue = minValue;
      RemoveElement(&(*tCursor) -> pRight, minValue);
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

  AVLTree.FreeAll = FreeAll;
  AVLTree.DisplayTree = DisplayTree;
  AVLTree.DisplayPreOrder = DisplayPreOder;
  AVLTree.DisplayInOrder = DisplayInOrder;
  AVLTree.DisplayPostOrder = DisplayPostOrder;
  AVLTree.InsertElement = InsertElement;
  AVLTree.RemoveElement = RemoveElement;
  AVLTree.FindElement = FindElement;
  AVLTree.QntNodes = QntNodes;
  AVLTree.GetHeight = GetHeight;
  AVLTree.GetMax = GetMax;
  AVLTree.GetMin = GetMin;

  return AVLTree;
}
