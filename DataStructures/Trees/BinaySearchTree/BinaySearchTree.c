#include "./BinaySearchTree.h"
#include <stdio.h>
#include <stdlib.h>

void FreeAll(BinaryNode** tCursor) {
  if ((*tCursor) != NULL) {
    FreeAll(&(*tCursor) -> pLeft);
    FreeAll(&(*tCursor) -> pRight);
    DestroyNode((*tCursor));
    (*tCursor) = NULL;
  }
}

void DisplayTree(BinaryNode* tCursor, int inLevel) {
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

void DisplayPreOder(BinaryNode* tCursor) {
  if (tCursor != NULL) {
    printf("%d ", tCursor -> nValue);
    DisplayPreOder(tCursor -> pLeft);
    DisplayPreOder(tCursor -> pRight);
  }
}

void DisplayInOrder(BinaryNode* tCursor) {
  if (tCursor != NULL) {
    DisplayInOrder(tCursor -> pLeft);
    printf("%d ", tCursor -> nValue);
    DisplayInOrder(tCursor -> pRight);
  }
}

void DisplayPostOrder(BinaryNode* tCursor) {
  if (tCursor != NULL) {
    DisplayPostOrder(tCursor -> pLeft);
    DisplayPostOrder(tCursor -> pRight);
    printf("%d ", tCursor -> nValue);
  }
}

void InsertElement(BinaryNode** tCursor, int tValue) {
  if ((*tCursor) == NULL) {
    (*tCursor) = CreateNode(tValue); 
  }
  else if ((*tCursor) -> pRight == NULL && tValue > (*tCursor) -> nValue) {
    (*tCursor) -> pRight = CreateNode(tValue);
  }
  else if ((*tCursor) -> pLeft == NULL && tValue <= (*tCursor) -> nValue) {
    (*tCursor) -> pLeft = CreateNode(tValue);
  }
  else {
    if (tValue > (*tCursor) -> nValue) {
      InsertElement(&(*tCursor) -> pRight, tValue);
    }
    else {
      InsertElement(&(*tCursor) -> pLeft, tValue);
    }
  }
}

int GetMin(BinaryNode* tCursor) {
  if (tCursor == NULL) {
    return -1;
  }
  else if (tCursor -> pLeft == NULL) {
    return tCursor -> nValue;
  }
  return GetMin(tCursor -> pLeft);
}

int GetMax(BinaryNode* tCursor) {
  if (tCursor == NULL) {
    return -1;
  }
  else if (tCursor -> pRight == NULL) {
    return tCursor -> nValue;
  }
  return GetMax(tCursor -> pRight);
}

int QntNodes(BinaryNode* tCursor) {
  if (tCursor == NULL) {
    return 0;
  }
  return 1 + QntNodes(tCursor -> pLeft) + QntNodes(tCursor -> pRight);
}

int GetHeight(BinaryNode* tCursor) {
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

int FindElement(BinaryNode* tCursor, int tValue) {
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

int RemoveElement(BinaryNode** tCursor, int tValue) {
  if (*tCursor == NULL) {
    printf("Error: Tree is empty or element wasn't found!\n");
    exit(3);
  }
  else if (tValue > (*tCursor) -> nValue) {
    return RemoveElement(&(*tCursor) -> pRight, tValue);
  }
  else if (tValue < (*tCursor) -> nValue) {
    return RemoveElement(&(*tCursor) -> pLeft, tValue);
  }
  else {
    int removedValue = (*tCursor) -> nValue;

    if ((*tCursor) -> pRight == NULL && (*tCursor) -> pLeft == NULL) {
      DestroyNode((*tCursor)), (*tCursor) = NULL;
    }
    else if ((*tCursor) -> pLeft == NULL) {
      BinaryNode* toRemove = (*tCursor);
      (*tCursor) = (*tCursor) -> pRight;
      DestroyNode(toRemove);
    }
    else if ((*tCursor) -> pRight == NULL) {
      BinaryNode* toRemove = (*tCursor);
      (*tCursor) = (*tCursor) -> pLeft;
      DestroyNode(toRemove);
    }
    else {
      int minValue = GetMin((*tCursor) -> pRight);
      (*tCursor) -> nValue = minValue;
      RemoveElement(&(*tCursor) -> pRight, minValue);
    }
    return removedValue;
  }
}

BinarySearchTree BST_Constructor(void) {
  BinarySearchTree BinarySearchTree;

  BinarySearchTree.tRoot = NULL;

  BinarySearchTree.FreeAll = FreeAll;
  BinarySearchTree.DisplayTree = DisplayTree;
  BinarySearchTree.DisplayPreOrder = DisplayPreOder;
  BinarySearchTree.DisplayInOrder = DisplayInOrder;
  BinarySearchTree.DisplayPostOrder = DisplayPostOrder;
  BinarySearchTree.InsertElement = InsertElement;
  BinarySearchTree.RemoveElement = RemoveElement;
  BinarySearchTree.FindElement = FindElement;
  BinarySearchTree.QntNodes = QntNodes;
  BinarySearchTree.GetHeight = GetHeight;
  BinarySearchTree.GetMax = GetMax;
  BinarySearchTree.GetMin = GetMin;

  return BinarySearchTree;
}
