#include "./PriorityQueue.h"
#include <stdio.h>
#include <stdlib.h>

void DisplayContent(PriorityQueue tQueue) {
	if (tQueue.qHead == NULL) {	
		printf("[]\n");
	}
	else {
		PriorityNode* qCursor = tQueue.qHead;
		printf("[");
		while (qCursor -> pNext != NULL) {
			printf("%d, ", qCursor -> nValue);
			qCursor = qCursor -> pNext;
		}
		printf("%d]\n", qCursor -> nValue);
	}
}

void FreeAll(PriorityQueue* tQueue) {
  if (tQueue -> qHead != NULL) {
    PriorityNode* qCursor = tQueue -> qHead;
    while (qCursor -> pNext != NULL) {
      PriorityNode* toDestroy = qCursor;
      qCursor = qCursor -> pNext;
      DestroyNode(toDestroy);
    }
    DestroyNode(qCursor);
    tQueue -> qHead = NULL;
    tQueue -> qSize = 0;
  }
}

void InsertPriorityNode(PriorityQueue* tQueue, int tValue, int pLevel) {
	PriorityNode* toInsert = CreateNode(tValue, pLevel);

  if (tQueue -> qHead == NULL) {
    tQueue -> qHead = toInsert;
  }
  else if (tQueue -> qHead -> pLevel < pLevel) {
    toInsert -> pNext = tQueue -> qHead;
    tQueue -> qHead = toInsert;
  }
  else {
    PriorityNode* qCursor = tQueue -> qHead;
    while (qCursor -> pNext != NULL)
  {
    if (qCursor -> pNext -> pLevel < pLevel) {
      toInsert -> pNext = qCursor -> pNext;
      qCursor -> pNext = toInsert;
      tQueue -> qSize++;
      return;
    }
    qCursor = qCursor -> pNext;
  }
  qCursor -> pNext = toInsert;
  }
  
  tQueue -> qSize++;
}

int RemovePriorityNode(PriorityQueue* tQueue) {
  int removedValue = -1;

	if (tQueue -> qHead == NULL) {
		printf("Error! Index Out Of Range...\n");
    exit(1);
	}
	else {
		PriorityNode* newHead = tQueue -> qHead;
		tQueue -> qHead = newHead -> pNext;
		free(newHead);
		tQueue -> qSize--;
	}

  return removedValue;
}

int GetFirst(PriorityQueue tQueue) {
  if (tQueue.qHead == NULL) {
    printf("Error: Index out of range!\n");
		return -1;
  }
  return tQueue.qHead -> nValue;
}

PriorityQueue PQ_Constructor(void) {
	PriorityQueue PriorityQueue;

	PriorityQueue.qHead = NULL;
	PriorityQueue.qSize = 0;

	PriorityQueue.DisplayContent = DisplayContent; 
  PriorityQueue.FreeAll = FreeAll;
	PriorityQueue.Enqueue = InsertPriorityNode;
	PriorityQueue.Dequeue = RemovePriorityNode;
  PriorityQueue.Peek = GetFirst;

	return PriorityQueue;
}
