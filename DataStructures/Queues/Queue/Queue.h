#ifndef QUEUE_H
#define QUEUE_H

#include "../../Common/Node/Node.h"

typedef struct Queue {

	Node* qHead;
	int qSize;

	void (*DisplayContent)(struct Queue tQueue);
  void (*FreeAll)(struct Queue* tQueue);
	void (*Enqueue)(struct Queue* tQueue, char* tValue);
	char* (*Dequeue)(struct Queue* tQueue);
  char* (*Peek)(struct Queue tQueue);

} Queue;

Queue Q_Constructor(void); 

#endif 
