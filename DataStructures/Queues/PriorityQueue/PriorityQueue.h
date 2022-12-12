#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "../../Common/PriorityNode/PriorityNode.h"

typedef struct PriorityQueue {

  PriorityNode *qHead;
  char pType;
  int qSize;

  void (*DisplayPQueue)(struct PriorityQueue tQueue);
  void (*FreePQueue)(struct PriorityQueue *tQueue);
  void (*EnqueueP)(struct PriorityQueue *tQueue, int tValue, int pLevel);
  int (*DequeueP)(struct PriorityQueue *tQueue);
  int (*PeekP)(struct PriorityQueue tQueue);

} PriorityQueue;

PriorityQueue PQ_Constructor(char pType);

#endif
