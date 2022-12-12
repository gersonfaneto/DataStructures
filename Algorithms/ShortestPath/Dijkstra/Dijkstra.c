#include "./Dijkstra.h"
#include <stdio.h>
#include <stdlib.h>

void Dijkstra(Graph tGraph, VPathsInfo *vPathsInfo, int sVertice) {
  PriorityQueue tQueue = PQ_Constructor('C');
  int nVertices = tGraph.nVertices;

  GetVPathsInfo(vPathsInfo, tGraph, sVertice);
  GetPQueue(&tQueue, *vPathsInfo, nVertices);

  while (tQueue.qSize != 0) {
    int currV = tQueue.DequeueP(&tQueue);
    int *adjList = tGraph.GetAdjList(tGraph, currV);

    for (int i = 0; i < nVertices; i++) {
      if (adjList[i] != 0) {
        PathRelaxation(tGraph, vPathsInfo, currV, i);
      }
    }

    UpdateQueue(&tQueue, *vPathsInfo);
  }

  tQueue.FreePQueue(&tQueue);
}
