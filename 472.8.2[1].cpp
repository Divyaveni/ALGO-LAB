#include <stdio.h>
#include <stdlib.h>

struct Edge {

  int start;
  int end;
  int weight;
};

struct Graph {

  int E;
  int V;
  struct Edge* edge;
};

struct subset {

  int parent;
  int rank;

};

struct Graph* createGraph(int E, int V)
{
    struct Graph* graph = (struct Graph*) malloc (sizeof(struct Graph));

    graph->E = E;
    graph->V = V;
    graph->edge = (struct Edge*) malloc (graph->E * sizeof(struct Edge));
    return graph;
}

int Find(struct subset subsets[], int i) {

  if (subsets[i].parent != i) {

    subsets[i].parent = Find(subsets, subsets[i].parent);

  }
  return subsets[i].parent;
}


void Union(struct subset subsets[], int vertXSubset, int vertYSubset) {

  int rootOfX = Find(subsets, vertXSubset);
    int rootOfY = Find(subsets, vertYSubset);

    if (subsets[rootOfX].rank < subsets[rootOfY].rank) {

        subsets[rootOfX].parent = rootOfY;

    }
    else if (subsets[rootOfX].rank > subsets[rootOfY].rank) {

        subsets[rootOfY].parent = rootOfX;

    }
    else {

        subsets[rootOfY].parent = rootOfX;
        subsets[rootOfX].rank++;
    }
}


void sort(struct Graph* graph) {


  int i, j, noOfEdges = graph->E;
  struct Edge* tempEdge = (struct Edge*) malloc (sizeof(struct Edge));

  for (i = 1; i < noOfEdges; i++) {
    for (j = 0; j < noOfEdges - i; j++) {

      if (graph->edge[j].weight > graph->edge[j+1].weight) {

        tempEdge->start = graph->edge[j].start;
        tempEdge->end = graph->edge[j].end;
        tempEdge->weight = graph->edge[j].weight;

        graph->edge[j] = graph->edge[j+1];

        graph->edge[j+1].start = tempEdge->start;
        graph->edge[j+1].end = tempEdge->end;
        graph->edge[j+1].weight = tempEdge->weight;
      }
    }
  }

}

void displayMST(struct Graph* graphMST) {
  int i, noOfEdges = graphMST->E;
  for (i = 0; i < noOfEdges; i++) {
    printf("Edge %d-->%d Weight: %d\n", graphMST->edge[i].start, graphMST->edge[i].end, graphMST->edge[i].weight);

  }
}

int hasCycle(struct Graph* graph) {


  int i, j, vertXSubset, vertYSubset;
  int V = graph->V;
  int E = graph->E;

  struct subset* subsets = (struct subset*) malloc (V * sizeof(struct subset));
  for (i = 0; i < V; i++) {

    subsets[i].parent = i;
    subsets[i].rank = 0;
  }

  for (j = 0; j < E; j++)
  {
    vertXSubset = Find(subsets, graph->edge[j].start);
    vertYSubset = Find(subsets, graph->edge[j].end);

    if (vertXSubset == vertYSubset)
    {
      return 1;
    }
    Union(subsets, vertXSubset, vertYSubset);
  }
  return 0;

}

void kruskal(struct Graph* graph) {
  int i, j;
  int E = graph->E;
  int V = graph->V;
  sort(graph);
  struct Graph* graphMST = createGraph(V - 1, V);
  for (i = 0, j = 0; i < E && j < V - 1; i++) {

    graphMST->edge[j] = graph->edge[i];
    graphMST->E = j + 1;

    if (!hasCycle(graphMST)) {

      j++;
    }
  }
  displayMST(graphMST);
}

int main (void) {
  int E = 14;
  int V = 9;

  struct Graph* graph = createGraph(E, V);
  graph->edge[0].start = 0;
  graph->edge[0].end = 1;
  graph->edge[0].weight = 4;

  graph->edge[1].start = 0;
  graph->edge[1].end = 7;
  graph->edge[1].weight = 8;

  graph->edge[2].start = 1;
  graph->edge[2].end = 7;
  graph->edge[2].weight = 11;

  graph->edge[3].start = 1;
  graph->edge[3].end = 2;
  graph->edge[3].weight = 8;

  graph->edge[4].start = 2;
  graph->edge[4].end = 8;
  graph->edge[4].weight = 2;

  graph->edge[5].start = 8;
  graph->edge[5].end = 7;
  graph->edge[5].weight = 7;

  graph->edge[6].start = 8;
  graph->edge[6].end = 6;
  graph->edge[6].weight = 6;

  graph->edge[7].start = 7;
  graph->edge[7].end = 8;
  graph->edge[7].weight = 1;

  graph->edge[8].start = 2;
  graph->edge[8].end = 5;
  graph->edge[8].weight = 4;

  graph->edge[9].start = 5;
  graph->edge[9].end = 6;
  graph->edge[9].weight = 2;

  graph->edge[10].start = 2;
  graph->edge[10].end = 3;
  graph->edge[10].weight = 7;

  graph->edge[11].start = 3;
  graph->edge[11].end = 5;
  graph->edge[11].weight = 14;

  graph->edge[12].start = 5;
  graph->edge[12].end = 4;
  graph->edge[12].weight = 10;

  graph->edge[13].start = 3;
  graph->edge[13].end = 4;
  graph->edge[13].weight = 9;

  kruskal(graph);

  return 0;
}

