#include "./DAG.h"
#include <stdio.h>
#include <stdlib.h>

void DAG(Graph tGraph, VPathsInfo *vPathsInfo, VColorsInfo *vColorsInfo,
         int sVertice) {
  int nVertices = tGraph.nVertices;
  int currVertice = 0;

  GetVPathsInfo(vPathsInfo, tGraph, sVertice);
  DepthFirstSearch(tGraph, vColorsInfo, sVertice);
  TopologicalSort(vColorsInfo, nVertices);

  for (int i = 0; i < nVertices; i++) {
    currVertice = vColorsInfo->vTimeSorted[i].fValue;
    for (int j = 0; j < nVertices; j++) {
      if (tGraph.AdjMatrix[currVertice][j] != 0) {
        PathRelaxation(tGraph, vPathsInfo, currVertice, j);
      }
    }
  }
}