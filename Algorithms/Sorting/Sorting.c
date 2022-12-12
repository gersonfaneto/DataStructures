#include "Sorting.h"

void BubbleSort(int *toSort, int arrSize) {
  for (int i = 0; i < arrSize; i++) {
    for (int j = 0; j < (arrSize - i - 1); j++) {
      if (toSort[j] > toSort[j + 1]) {
        int auxValue = toSort[j];
        toSort[j] = toSort[j + 1];
        toSort[j + 1] = auxValue;
      }
    }
  }
}

void InsertionSort(int *toSort, int arrSize) {
  for (int i = 1; i < arrSize; i++) {
    int targetValue = toSort[i], arrCursor = i - 1;
    while (arrCursor >= 0 && targetValue < toSort[arrCursor]) {
      toSort[arrCursor + 1] = toSort[arrCursor];
      arrCursor--;
    }
    toSort[arrCursor + 1] = targetValue;
  }
}

void SelectionSort(int *toSort, int arrSize) {
  for (int i = 0; i < arrSize; i++) {
    int targetIndex = i;
    for (int j = i + 1; j < arrSize; j++) {
      if (toSort[j] < toSort[targetIndex]) {
        targetIndex = j;
      }
    }
    int auxValue = toSort[i];
    toSort[i] = toSort[targetIndex];
    toSort[targetIndex] = auxValue;
  }
}

void QuickSort(int *toSort, int lValue, int rValue) {
  if (lValue < rValue) {
    int pivotIndex = (int)(rValue + lValue) / 2;
    int arrPivot = toSort[pivotIndex];
    int auxValue = 0;

    toSort[pivotIndex] = toSort[rValue];
    toSort[rValue] = arrPivot;

    int i = lValue, j = rValue - 1;
    while (i < j) {
      while (toSort[i] < arrPivot && i < rValue) {
        i++;
      }
      while (toSort[j] > arrPivot && j > lValue) {
        j--;
      }
      if (i < j) {
        auxValue = toSort[i];
        toSort[i] = toSort[j];
        toSort[j] = auxValue;
      }
    }

    toSort[rValue] = toSort[i];
    toSort[i] = arrPivot;

    QuickSort(toSort, lValue, i - 1);
    QuickSort(toSort, i + 1, rValue);
  }
}

void Merge(int *toMerge, int lValue, int mValue, int rValue) {
  int i = 0, j = 0, k = 0;
  int fSize = (mValue - lValue) + 1;
  int sSize = rValue - mValue;

  int lHalf[fSize], rHalf[sSize];

  for (i = 0; i < fSize; i++) {
    lHalf[i] = toMerge[lValue + i];
  }

  for (j = 0; j < sSize; j++) {
    rHalf[j] = toMerge[mValue + 1 + j];
  }

  i = 0, j = 0;
  k = lValue;
  while (i < fSize && j < sSize) {
    if (lHalf[i] <= rHalf[j]) {
      toMerge[k] = lHalf[i];
      i++;
    } else {
      toMerge[k] = rHalf[j];
      j++;
    }
    k++;
  }

  while (i < fSize) {
    toMerge[k] = lHalf[i];
    i++, k++;
  }

  while (j < sSize) {
    toMerge[k] = rHalf[j];
    j++, k++;
  }
}

void MergeSort(int *toSort, int lValue, int rValue) {
  if (lValue < rValue) {
    int mValue = (lValue + rValue) / 2;

    MergeSort(toSort, lValue, mValue);
    MergeSort(toSort, mValue + 1, rValue);

    Merge(toSort, lValue, mValue, rValue);
  }
}
