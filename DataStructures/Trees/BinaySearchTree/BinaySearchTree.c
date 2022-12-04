#include "./BinaySearchTree.h"
#include <stdio.h>
#include <stdlib.h>

void FreeTree_Binary(BinaryNode** tCursor) {
  if ((*tCursor) != NULL) {
    FreeTree_Binary(&(*tCursor) -> pLeft);
    FreeTree_Binary(&(*tCursor) -> pRight);
    DestroyBinaryNode((*tCursor));
    (*tCursor) = NULL;
  }
}

void DisplayTree_Binary(BinaryNode* tCursor, int inLevel) {
  if (tCursor != NULL) {
    DisplayTree_Binary(tCursor -> pRight, inLevel + 1);

    printf("\n");
    for (int i = 0; i < inLevel; i++) {
      printf("    ");
    }

    printf("%d\n", tCursor -> nValue);

    DisplayTree_Binary(tCursor -> pLeft, inLevel + 1);
  }
}

void DisplayPreOder_Binary(BinaryNode* tCursor) {
  if (tCursor != NULL) {
    printf("%d ", tCursor -> nValue);
    DisplayPreOder_Binary(tCursor -> pLeft);
    DisplayPreOder_Binary(tCursor -> pRight);
  }
}

void DisplayInOrder_Binary(BinaryNode* tCursor) {
  if (tCursor != NULL) {
    DisplayInOrder_Binary(tCursor -> pLeft);
    printf("%d ", tCursor -> nValue);
    DisplayInOrder_Binary(tCursor -> pRight);
  }
}

void DisplayPostOrder_Binary(BinaryNode* tCursor) {
  if (tCursor != NULL) {
    DisplayPostOrder_Binary(tCursor -> pLeft);
    DisplayPostOrder_Binary(tCursor -> pRight);
    printf("%d ", tCursor -> nValue);
  }
}

void InsertElement_Binary(BinaryNode** tCursor, int tValue) {
  if ((*tCursor) == NULL) {
    (*tCursor) = CreateBinaryNode(tValue); 
  }
  else if ((*tCursor) -> pRight == NULL && tValue > (*tCursor) -> nValue) {
    (*tCursor) -> pRight = CreateBinaryNode(tValue);
  }
  else if ((*tCursor) -> pLeft == NULL && tValue <= (*tCursor) -> nValue) {
    (*tCursor) -> pLeft = CreateBinaryNode(tValue);
  }
  else {
    if (tValue > (*tCursor) -> nValue) {
      InsertElement_Binary(&(*tCursor) -> pRight, tValue);
    }
    else {
      InsertElement_Binary(&(*tCursor) -> pLeft, tValue);
    }
  }
}

int GetMin_Binary(BinaryNode* tCursor) {
  if (tCursor == NULL) {
    return -1;
  }
  else if (tCursor -> pLeft == NULL) {
    return tCursor -> nValue;
  }
  return GetMin_Binary(tCursor -> pLeft);
}

int GetMax_Binary(BinaryNode* tCursor) {
  if (tCursor == NULL) {
    return -1;
  }
  else if (tCursor -> pRight == NULL) {
    return tCursor -> nValue;
  }
  return GetMax_Binary(tCursor -> pRight);
}

int QntNodes_Binary(BinaryNode* tCursor) {
  if (tCursor == NULL) {
    return 0;
  }
  return 1 + QntNodes_Binary(tCursor -> pLeft) + QntNodes_Binary(tCursor -> pRight);
}

int GetHeight_Binary(BinaryNode* tCursor) {
  if (tCursor == NULL) {
    return -1;
  }
  else {
    int leftHeight = GetHeight_Binary(tCursor -> pLeft);
    int rightHeight = GetHeight_Binary(tCursor -> pRight);
    if (leftHeight > rightHeight) {
      return leftHeight + 1;
    }
    else {
      return rightHeight + 1;
    }
  }
}

int FindElement_Binary(BinaryNode* tCursor, int tValue) {
  if (tCursor == NULL) {
    return 0;
  }
  else if (tCursor -> nValue == tValue) {
    return 1;
  }
  else {
    if (tValue > tCursor -> nValue) {
      return FindElement_Binary(tCursor -> pRight, tValue);
    }
    else {
      return FindElement_Binary(tCursor -> pLeft, tValue);
    }
  }
}

int RemoveElement_Binary(BinaryNode** tCursor, int tValue) {
  if (*tCursor == NULL) {
    printf("Error: Tree is empty or element wasn't found!\n");
    exit(3);
  }
  else if (tValue > (*tCursor) -> nValue) {
    return RemoveElement_Binary(&(*tCursor) -> pRight, tValue);
  }
  else if (tValue < (*tCursor) -> nValue) {
    return RemoveElement_Binary(&(*tCursor) -> pLeft, tValue);
  }
  else {
    int removedValue = (*tCursor) -> nValue;

    if ((*tCursor) -> pRight == NULL && (*tCursor) -> pLeft == NULL) {
      DestroyBinaryNode((*tCursor)), (*tCursor) = NULL;
    }
    else if ((*tCursor) -> pLeft == NULL) {
      BinaryNode* toRemove = (*tCursor);
      (*tCursor) = (*tCursor) -> pRight;
      DestroyBinaryNode(toRemove);
    }
    else if ((*tCursor) -> pRight == NULL) {
      BinaryNode* toRemove = (*tCursor);
      (*tCursor) = (*tCursor) -> pLeft;
      DestroyBinaryNode(toRemove);
    }
    else {
      int minValue = GetMin_Binary((*tCursor) -> pRight);
      (*tCursor) -> nValue = minValue;
      RemoveElement_Binary(&(*tCursor) -> pRight, minValue);
    }
    return removedValue;
  }
}

BinarySearchTree BST_Constructor(void) {
  BinarySearchTree BinarySearchTree;

  BinarySearchTree.tRoot = NULL;

  BinarySearchTree.FreeAll_Binary = FreeTree_Binary;
  BinarySearchTree.DisplayTree_Binary = DisplayTree_Binary;
  BinarySearchTree.DisplayPreOrder_Binary = DisplayPreOder_Binary;
  BinarySearchTree.DisplayInOrder_Binary = DisplayInOrder_Binary;
  BinarySearchTree.DisplayPostOrder_Binary = DisplayPostOrder_Binary;
  BinarySearchTree.InsertElement_Binary = InsertElement_Binary;
  BinarySearchTree.RemoveElement_Binary = RemoveElement_Binary;
  BinarySearchTree.FindElement_Binary = FindElement_Binary;
  BinarySearchTree.QntNodes_Binary = QntNodes_Binary;
  BinarySearchTree.GetHeight_Binary = GetHeight_Binary;
  BinarySearchTree.GetMax_Binary = GetMax_Binary;
  BinarySearchTree.GetMin_Binary = GetMin_Binary;

  return BinarySearchTree;
}
