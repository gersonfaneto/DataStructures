#include "./PriorityQueue.h"
#include <stdio.h>
#include <stdlib.h>

void DisplayPQueue(PriorityQueue tQueue) {
  if (tQueue.qHead == NULL) {
    printf("[]\n");
  } else {
    PriorityNode *qCursor = tQueue.qHead;
    printf("[");
    while (qCursor->pNext != NULL) {
      printf("%d, ", qCursor->nValue);
      qCursor = qCursor->pNext;
    }
    printf("%d]\n", qCursor->nValue);
  }
}

void FreePQueue(PriorityQueue *tQueue) {
  if (tQueue->qHead != NULL) {
    PriorityNode *qCursor = tQueue->qHead;
    while (qCursor->pNext != NULL) {
      PriorityNode *toDestroy = qCursor;
      qCursor = qCursor->pNext;
      DestroyPriorityNode(toDestroy);
    }
    DestroyPriorityNode(qCursor);
    tQueue->qHead = NULL;
    tQueue->qSize = 0;
  }
}

void EnqueuePMin(PriorityQueue *tQueue, int tValue, int pLevel) {
  PriorityNode *toInsert = CreatePriorityNode(tValue, pLevel);

  if (tQueue->qHead == NULL) {
    tQueue->qHead = toInsert;
  } else if (tQueue->qHead->pLevel > pLevel) {
    toInsert->pNext = tQueue->qHead;
    tQueue->qHead = toInsert;
  } else {
    PriorityNode *qCursor = tQueue->qHead;
    while (qCursor->pNext != NULL) {
      if (qCursor->pNext->pLevel > pLevel) {
        toInsert->pNext = qCursor->pNext;
        qCursor->pNext = toInsert;
        tQueue->qSize++;
        return;
      }
      qCursor = qCursor->pNext;
    }
    qCursor->pNext = toInsert;
  }

  tQueue->qSize++;
}

void EnqueuePMax(PriorityQueue *tQueue, int tValue, int pLevel) {
  PriorityNode *toInsert = CreatePriorityNode(tValue, pLevel);

  if (tQueue->qHead == NULL) {
    tQueue->qHead = toInsert;
  } else if (tQueue->qHead->pLevel < pLevel) {
    toInsert->pNext = tQueue->qHead;
    tQueue->qHead = toInsert;
  } else {
    PriorityNode *qCursor = tQueue->qHead;
    while (qCursor->pNext != NULL) {
      if (qCursor->pNext->pLevel < pLevel) {
        toInsert->pNext = qCursor->pNext;
        qCursor->pNext = toInsert;
        tQueue->qSize++;
        return;
      }
      qCursor = qCursor->pNext;
    }
    qCursor->pNext = toInsert;
  }

  tQueue->qSize++;
}

void EnqueueP(PriorityQueue *tQueue, int tValue, int pLevel) {
  if (tQueue->pType == 'C') {
    EnqueuePMin(tQueue, tValue, pLevel);
  } else {
    EnqueuePMax(tQueue, tValue, pLevel);
  }
}

int DequeueP(PriorityQueue *tQueue) {
  if (tQueue->qHead == NULL) {
    printf("Error! Index Out Of Range...\n");
    exit(1);
  }

  PriorityNode *removedNode = tQueue->qHead;
  int removedValue = removedNode->nValue;
  tQueue->qHead = removedNode->pNext;
  free(removedNode);
  tQueue->qSize--;

  return removedValue;
}

int PeekP(PriorityQueue tQueue) {
  if (tQueue.qHead == NULL) {
    printf("Error: Index out of range!\n");
    return -1;
  }
  return tQueue.qHead->nValue;
}

PriorityQueue PQ_Constructor(char pType) {
  PriorityQueue PriorityQueue;

  if (pType != 'C' && pType != 'D') {
    printf("Error: Priority Type value isn't valid!\n");
    printf("Use: 'C' for Crescent/Min Priority\n");
    printf("     'D' for Decrescent/Max Priority\n");
    exit(2);
  }

  PriorityQueue.qHead = NULL;
  PriorityQueue.pType = pType;
  PriorityQueue.qSize = 0;

  PriorityQueue.DisplayPQueue = DisplayPQueue;
  PriorityQueue.FreePQueue = FreePQueue;
  PriorityQueue.EnqueueP = EnqueueP;
  PriorityQueue.DequeueP = DequeueP;
  PriorityQueue.PeekP = PeekP;

  return PriorityQueue;
}
