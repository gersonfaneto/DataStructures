#include "./Common.h"

#include <stdio.h>
#include <stdlib.h> 

void GetVPathsInfo(VPathsInfo* vPathsInfo, Graph tGraph, int sVertice) {
  vPathsInfo -> vPred = (int*) malloc(tGraph.nVertices * sizeof(int));
  vPathsInfo -> vDist = (int*) malloc(tGraph.nVertices * sizeof(int));
  vPathsInfo -> maxWeight = tGraph.MaxGraphDegree(tGraph) * (tGraph.nVertices - 1) + 1;

  for (int i = 0; i < tGraph.nVertices; i++) {
    vPathsInfo -> vDist[i] = vPathsInfo -> maxWeight;
    vPathsInfo -> vPred[i] = -1;
  }
  vPathsInfo -> vDist[sVertice] = 0;
}

void GetPQueue(PriorityQueue* tQueue, VPathsInfo vPathsInfo, int nVertices) {
  for (int i = 0; i < nVertices; i++) {
    tQueue -> Enqueue(tQueue, i, vPathsInfo.vDist[i]);
  }
}

void GetVColorsInfo(VColorsInfo* vColorsInfo, int nVertices) {
  vColorsInfo -> vColor = (int*) malloc(nVertices * sizeof(int));
  vColorsInfo -> vGTime = (int*) malloc(nVertices * sizeof(int));
  vColorsInfo -> vBTime = (int*) malloc(nVertices * sizeof(int));
  vColorsInfo -> vTimeSorted = (IntTuple*) malloc(nVertices * sizeof(IntTuple));

  vColorsInfo -> currTime = 1;

  for (int i = 0; i < nVertices; i++) {
    vColorsInfo -> vColor[i] = White;
  }
}

void PathRelaxation(Graph tGraph, VPathsInfo* vPathsInfo , int currV, int nextV) {
  int newDistance = vPathsInfo -> vDist[currV] + tGraph.AdjMatrix[currV][nextV];
  int currDistance = vPathsInfo -> vDist[nextV];

  if (currDistance > newDistance) {
    vPathsInfo -> vPred[nextV] = currV;
    vPathsInfo -> vDist[nextV] = newDistance;
  }
}

void UpdateQueue(PriorityQueue* tQueue, VPathsInfo vPathsInfo) {
  int* rVertices = (int*) malloc(tQueue -> qSize * sizeof(int));
  int qSize = tQueue -> qSize;

  for (int i = 0; i < qSize; i++) {
    rVertices[i] = tQueue -> Dequeue(tQueue);
  }

  for (int j = 0; j < qSize; j++) {
    tQueue -> Enqueue(tQueue, rVertices[j], vPathsInfo.vDist[rVertices[j]]);
  }

  free(rVertices);
}

void DepthFirstVisit(Graph tGraph, VColorsInfo* vColorsInfo, int tVertice) {
  vColorsInfo -> vColor[tVertice] = Grey;
  vColorsInfo -> vGTime[tVertice] = vColorsInfo -> currTime;
  vColorsInfo -> currTime++;

  int nVertices = tGraph.nVertices;

  for (int i = 0; i < nVertices; i++) {
    if (tGraph.AdjMatrix[tVertice][i] != 0 && vColorsInfo -> vColor[i] == White) {
      DepthFirstVisit(tGraph, vColorsInfo, i);
    }
  }

  vColorsInfo -> vColor[tVertice] = Black;
  vColorsInfo -> vBTime[tVertice] = vColorsInfo -> currTime;
  vColorsInfo -> vTimeSorted[tVertice].fValue = tVertice;
  vColorsInfo -> vTimeSorted[tVertice].sValue = vColorsInfo -> currTime;
  vColorsInfo -> currTime++;
}

void DepthFirstSearch(Graph tGraph, VColorsInfo* vColorsInfo, int sVertice) {
  int nVertices = tGraph.nVertices;

  GetVColorsInfo(vColorsInfo, nVertices);

  DepthFirstVisit(tGraph, vColorsInfo, sVertice);

  for (int i = 0; i < nVertices; i++) {
    if (vColorsInfo -> vColor[i] == White) {
      DepthFirstVisit(tGraph, vColorsInfo, i);
    }
  }
}

void TopologicalSort(VColorsInfo* vColorsInfo, int nVertices) {
  int minValue = 0, minIndex = 0;
  IntTuple auxTuple;

  for (int i = 0; i < nVertices; i++) {
    minValue = vColorsInfo -> vTimeSorted[i].sValue, minIndex = i;
    for (int j = i; j < nVertices; j++) {
      if (vColorsInfo -> vTimeSorted[j].sValue >= minValue) {
        minValue = vColorsInfo -> vTimeSorted[j].sValue;
        minIndex = j;
      }
    auxTuple.fValue = vColorsInfo -> vTimeSorted[minIndex].fValue;
    }
    auxTuple.sValue = vColorsInfo -> vTimeSorted[minIndex].sValue;
    vColorsInfo -> vTimeSorted[minIndex] = vColorsInfo -> vTimeSorted[i];
    vColorsInfo -> vTimeSorted[i] = auxTuple;
  }
}

void ClearVPathsInfo(VPathsInfo* vPathsInfo) {
  if (vPathsInfo -> maxWeight = 0) {
    return;
  }
  free(vPathsInfo -> vDist);
  free(vPathsInfo -> vPred);
  vPathsInfo -> maxWeight = 0;
}

void ClearVColorsInfo(VColorsInfo* vColorsInfo) {
  if (vColorsInfo -> currTime == 0) {
    return;
  }
  free(vColorsInfo -> vColor);
  free(vColorsInfo -> vGTime);
  free(vColorsInfo -> vBTime);
  free(vColorsInfo -> vTimeSorted);
  vColorsInfo -> currTime = 0;
}