#ifndef GRAPH_H
#define GRAPH_H

typedef struct Graph {

  int nVertices;
  int nEdges;
  int** AdjMatrix;

  void (*InsertEdge)(struct Graph* tGraph, int sVertice, int tVertice, int eWeight);
  void (*RemoveEdge)(struct Graph* tGraph, int sVvertice, int tVertice);
  int (*HasEdge)(struct Graph tGraph, int sVertice, int tVertice);
  void (*DisplayAdjMatrix)(struct Graph tGraph);
  void (*FreeGraph)(struct Graph* tGraph);
  void (*ClearEdges)(struct Graph* tGraph);

  int (*VerticeDegree)(struct Graph tGraph, int tVertice);
  int (*VerticeInDegree)(struct Graph tGraph, int tVertice);
  int (*VerticeOutDegree)(struct Graph tGraph, int tVertice);
  int (*MinGraphDegree)(struct Graph tGraph);
  int (*MaxGraphDegree)(struct Graph tGraph);
  int (*IsPath)(struct Graph tGraph, int* pPoints, int pSize);
  int* (*GetAdjList)(struct Graph tGraph, int tVertice);

} Graph;

Graph G_Constructor(int nVertices);
void ReadFromFile(Graph* tGraph, char* fileName);
void WriteToFile(Graph tGraph, char* fileName);

#endif
