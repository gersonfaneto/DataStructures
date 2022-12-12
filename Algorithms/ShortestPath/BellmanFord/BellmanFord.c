#include "./BellmanFord.h"
#include <stdio.h>
#include <stdlib.h>

int GetPairsList(Graph tGraph, IntTuple *vPairs, int nVertices) {
  int pCounter = 0;
  for (int i = 0; i < nVertices; i++) {
    for (int j = 0; j < nVertices; j++) {
      if (tGraph.AdjMatrix[i][j] != 0) {
        vPairs[pCounter].fValue = i;
        vPairs[pCounter].sValue = j;
        pCounter++;
      }
    }
  }
  return pCounter;
}

int BellmanFord(Graph tGraph, VPathsInfo *vPathsInfo, int sVertice) {
  int nVertices = tGraph.nVertices;
  int nEdges = tGraph.nEdges;
  int currDist = 0;

  IntTuple *vPairs = (IntTuple *)malloc(nEdges * sizeof(IntTuple));
  int nPairs = GetPairsList(tGraph, vPairs, nVertices);

  GetVPathsInfo(vPathsInfo, tGraph, sVertice);

  for (int i = 0; i < nVertices - 1; i++) {
    for (int j = 0; j < nPairs; j++) {
      PathRelaxation(tGraph, vPathsInfo, vPairs[j].fValue, vPairs[j].sValue);
    }
  }

  for (int i = 0; i < nPairs; i++) {
    currDist = vPathsInfo->vDist[i];
    PathRelaxation(tGraph, vPathsInfo, vPairs[i].fValue, vPairs[i].sValue);
    if (vPathsInfo->vDist[i] != currDist) {
      printf("Negative Cycle Found...The Sortest Path Can't Be Defined!\n");
      free(vPairs);
      return 0;
    }
  }

  free(vPairs);
  return 1;
}