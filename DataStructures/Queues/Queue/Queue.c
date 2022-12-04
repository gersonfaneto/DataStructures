#include "./Queue.h"

#include <stdio.h>
#include <stdlib.h>

void DisplayContent(Queue tQueue) {
	if (tQueue.qHead == NULL) {	
		printf("[]\n");
	}
	else {
		Node* qCursor = tQueue.qHead;
		printf("[");
		while (qCursor -> pNext != NULL) {
			printf("%d, ", qCursor -> nValue);
			qCursor = qCursor -> pNext;
		}
		printf("%d]\n", qCursor -> nValue);
	}
}

void FreeAll(Queue* tQueue) {
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

void InsertNode(Queue* tQueue, int tValue) {
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

int RemoveNode(Queue* tQueue) {
  int removedValue = -1;

	if (tQueue -> qHead == NULL) {
		printf("Error: Index out of range!\n");
    FreeAll(tQueue);
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

int GetFirst(Queue tQueue) {
  if (tQueue.qHead == NULL) {
    printf("Error: Index out of range!\n");
		return -1;
  }
  return tQueue.qHead -> nValue;
}

Queue Q_Constructor(void) {
	Queue Queue;

	Queue.qHead = NULL;
	Queue.qSize = 0;

	Queue.DisplayContent = DisplayContent; 
  Queue.FreeAll = FreeAll;
	Queue.Enqueue = InsertNode;
	Queue.Dequeue = RemoveNode;
  Queue.Peek = GetFirst;

	return Queue;
}
