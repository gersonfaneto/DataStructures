#ifndef COMMON_H
#define COMMON_H

#include "../../../DataStructures/Graph/Graph.h"
#include "../../../DataStructures/Queues/PriorityQueue/PriorityQueue.h"

enum VerticeColors { White, Grey, Black };

typedef struct IntTuple {

  int fValue;
  int sValue;

} IntTuple;

typedef struct VerticePathsInfo {

  int maxWeight;
  int *vPred;
  int *vDist;

} VPathsInfo;

typedef struct VerticeColorsInfo {

  int currTime;
  int *vColor;
  int *vGTime;
  int *vBTime;
  IntTuple *vTimeSorted;

} VColorsInfo;

void GetVPathsInfo(VPathsInfo *vPathsInfo, Graph tGraph, int sVertice);
void GetVColorsInfo(VColorsInfo *vColorInfo, int nVertices);
void GetPQueue(PriorityQueue *tQueue, VPathsInfo vPathsInfo, int nVertices);
void PathRelaxation(Graph tGraph, VPathsInfo *vPathsInfo, int currV, int nextV);
void UpdateQueue(PriorityQueue *tQueue, VPathsInfo vPathsInfo);
void DepthFirstVisit(Graph tGraph, VColorsInfo *vColorsInfo, int tVertice);
void DepthFirstSearch(Graph tGraph, VColorsInfo *vColorsInfo, int sVertice);
void TopologicalSort(VColorsInfo *vColorsInfo, int nVertices);
void ClearVPathsInfo(VPathsInfo *vPathsInfo);
void ClearVColorsInfo(VColorsInfo *vColorsInfo);

#endif