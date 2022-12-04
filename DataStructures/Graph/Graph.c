#include "./Graph.h"
#include <stdio.h>
#include <stdlib.h>

void DisplayAdjMatrix(Graph tGraph) {
  int nVertices = tGraph.nVertices;
  for (int i = 0; i < nVertices; i++) {
    for (int j = 0; j < nVertices; j++) {
      int currEdge = tGraph.AdjMatrix[i][j];
      (j != nVertices) ? printf("[%d] ", currEdge) : printf("[%d]\n", currEdge);
    }
    printf("\n");
  }
}

void InsertEdge (Graph* tGraph, int sVertice, int tVertice, int eWeight) {
  tGraph -> AdjMatrix[sVertice][tVertice] = eWeight;
  tGraph -> nEdges++;
}

void RemoveEdge (Graph* tGraph, int sVertice, int tVertice) {
  tGraph -> AdjMatrix[sVertice][tVertice] = 0;
  tGraph -> nEdges--;
}

void ClearEdges(Graph* tGraph) {
  int nVertices = tGraph -> nVertices;
  for (int i = 0; i < nVertices; i++) {
    for (int j = 0; j < nVertices; j++) {
      tGraph -> AdjMatrix[i][j] = 0;
    }
  }
  tGraph -> nEdges = 0;
}

int HasEdge (Graph tGraph, int sVertice, int tVertice) {
  return (tGraph.AdjMatrix[sVertice][tVertice] != 0) ? 1 : 0;
}

int GetEdgeWeight (Graph tGraph, int sVertice, int tVertice) {
  if (!HasEdge(tGraph, sVertice, tVertice)) {
    printf("Vertices are not connected!\n");
    return -1;
  }
  return tGraph.AdjMatrix[sVertice][tVertice];
}

int* GetAdjList(Graph tGraph, int tVertice) {
  return tGraph.AdjMatrix[tVertice];
}

int VerticeDegree(Graph tGraph, int tVertice) {
  int nVertices = tGraph.nVertices;
  int vDegree = 0;

  for (int i = 0; i < nVertices; i++) {
    if (tGraph.AdjMatrix[tVertice][i] != 0) {
      vDegree++;
    }
  }

  return vDegree;
}

int VerticeInDegree(Graph tGraph, int tVertice) {
  return VerticeDegree(tGraph, tVertice);
}

int VerticeOutDegree(Graph tGraph, int tVertice) {
  int n = tGraph.nVertices;
  int vDegree = 0;

  for (int i = 0; i < n; i++) {
    if (tGraph.AdjMatrix[i][tVertice] != 0) {
      vDegree++;
    }
  }

  return vDegree;
}

int MinGraphDegree(Graph tGraph) {
  int nVertices = tGraph.nVertices;
  int minDegree = 0, auxValue = 0;

  for (int i = 0; i < nVertices; i++) {
    auxValue = VerticeDegree(tGraph, i);
    if (auxValue < minDegree || i == 0) {
      minDegree = auxValue;
    }
  }

  return minDegree;
}

int MaxGraphDegree(Graph tGraph) {
  int nVertices = tGraph.nVertices;
  int maxDegree = 0, auxValue = 0;

  for (int i = 0; i < nVertices; i++) {
    auxValue = VerticeDegree(tGraph, i);
    if (auxValue > maxDegree || i == 0) {
      maxDegree = auxValue;
    }
  }

  return maxDegree;
}

int IsPath(Graph tGraph, int* pEdges, int pSize) {
  int auxValue = 0;

  for (int i = 0; i < pSize; i++) {
    auxValue = pEdges[i];
    for (int j = (i + 1); j < pSize; j++) {
      if (pEdges[j] == auxValue) {
        return 0;
      }
    }
  }

  for (int i = 0; i < (pSize - 1); i++) {
    if (tGraph.AdjMatrix[pEdges[i]][pEdges[i + 1]] == 0) {
      return 0;
    }
  }

  return 1;
}

void ReadFromFile(Graph* tGraph, char* fileName) {
  FILE* tFile = fopen(fileName, "r");
  int nVertices, currEdge;

  fscanf(tFile, "%d", &nVertices);

  tGraph -> FreeGraph(tGraph);
  *tGraph = G_Constructor(nVertices);

  for (int i = 0; i < nVertices; i++) {
    for (int j = 0; j < nVertices; j++) {
      fscanf(tFile, "%d", &currEdge);
      tGraph -> AdjMatrix[i][j] = currEdge;
      if (currEdge != 0) {
        tGraph -> nEdges++;
      }
    }
  }

  fclose(tFile);
}

void WriteToFile(Graph tGraph, char* fileName) {
  FILE* tFile = fopen(fileName, "w");
  fprintf(tFile, "%d\n", tGraph.nVertices); 

  for (int i = 0; i < tGraph.nVertices; i++) {
    for (int j = 0; j < tGraph.nVertices; j++) {
      fprintf(tFile, "%d ", tGraph.AdjMatrix[i][j]);
    }
    fprintf(tFile, "\n");
  }

  fclose(tFile);
}

void FreeGraph(Graph* tGraph) {
  int nVertices = tGraph -> nVertices;
  for (int i = 0; i < nVertices; i++) {
    free(tGraph -> AdjMatrix[i]);
  }
  free(tGraph -> AdjMatrix);
  tGraph -> nVertices = 0;
  tGraph -> nEdges = 0;
}

Graph G_Constructor(int nVertices) {
  Graph Graph;

  Graph.nVertices = nVertices;
  Graph.nEdges = 0;
  
  Graph.AdjMatrix = (int**) malloc(nVertices * sizeof(int*));
  for (int i = 0; i < nVertices; i++) {
    Graph.AdjMatrix[i] = (int*) malloc(nVertices * sizeof(int));
  }

  Graph.InsertEdge = InsertEdge;
  Graph.RemoveEdge = RemoveEdge;
  Graph.HasEdge = HasEdge;
  Graph.DisplayAdjMatrix = DisplayAdjMatrix;
  Graph.FreeGraph = FreeGraph;
  Graph.ClearEdges = ClearEdges;

  Graph.VerticeDegree = VerticeDegree;
  Graph.VerticeInDegree = VerticeInDegree;
  Graph.VerticeOutDegree = VerticeOutDegree;
  Graph.MaxGraphDegree = MaxGraphDegree;
  Graph.MinGraphDegree = MinGraphDegree;
  Graph.IsPath = IsPath;
  Graph.GetAdjList = GetAdjList;

  return Graph;
}
