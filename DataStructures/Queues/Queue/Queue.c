#include "./Queue.h"
#include <stdio.h>
#include <stdlib.h>

void DisplayQueue(Queue tQueue) {
	if (tQueue.qHead == NULL) {	
		printf("[]\n");
	}
	else {
		Node* qCursor = tQueue.qHead;
		printf("[");
		while (qCursor -> pNext != NULL) {
			printf("%s, ", qCursor -> nValue);
			qCursor = qCursor -> pNext;
		}
		printf("%s]\n", qCursor -> nValue);
	}
}

void FreeQueue(Queue* tQueue) {
  if (tQueue -> qHead != NULL) {
    Node* qCursor = tQueue -> qHead;
    while (qCursor -> pNext != NULL) {
      Node* toDestroy = qCursor;
      qCursor = qCursor -> pNext;
      DestroyNode(toDestroy);
    }
    DestroyNode(qCursor);
    tQueue -> qHead = NULL;
    tQueue -> qSize = 0;
  }
}

void Enqueue(Queue* tQueue, char* tValue) {
	Node* toInsert = CreateNode(tValue);

  if (tQueue -> qHead == NULL) {
	 	tQueue -> qHead = toInsert;
  }
  else {
	 	Node* qCursor = tQueue -> qHead;
	 	while (qCursor -> pNext != NULL) {
	 		qCursor = qCursor -> pNext;
	 	}
	 	qCursor -> pNext = toInsert;
	 }

	tQueue -> qSize++;
}

char* Dequeue(Queue* tQueue) {
  char* removedValue = NULL;

	if (tQueue -> qHead == NULL) {
		printf("Error: Index out of range!\n");
    FreeQueue(tQueue);
    exit(1);
	}
	else {
		Node* newHead = tQueue -> qHead;
    removedValue = newHead -> nValue;
		tQueue -> qHead = newHead -> pNext;
		free(newHead);
		tQueue -> qSize--;
	}

  return removedValue;
}

char* Peek(Queue tQueue) {
  if (tQueue.qHead == NULL) {
    printf("Error: Index out of range!\n");
		return NULL;
  }
  return tQueue.qHead -> nValue;
}

Queue Q_Constructor(void) {
	Queue Queue;

	Queue.qHead = NULL;
	Queue.qSize = 0;

	Queue.DisplayQueue = DisplayQueue; 
  Queue.FreeQueue = FreeQueue;
	Queue.Enqueue = Enqueue;
	Queue.Dequeue = Dequeue;
  Queue.Peek = Peek;

	return Queue;
}
