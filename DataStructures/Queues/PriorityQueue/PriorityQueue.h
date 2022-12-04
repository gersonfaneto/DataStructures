#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "../../Common/PriorityNode/PriorityNode.h"

typedef struct PriorityQueue {

	PriorityNode* qHead;
	int qSize;

	void (*DisplayContent)(struct PriorityQueue tQueue);
  void (*FreeAll)(struct PriorityQueue* tQueue);
	void (*Enqueue)(struct PriorityQueue* tQueue, int tValue, int pLevel);
	int (*Dequeue)(struct PriorityQueue* tQueue);
  int (*Peek)(struct PriorityQueue tQueue);

} PriorityQueue;

PriorityQueue PQ_Constructor(void);

#endif 
