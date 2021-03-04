#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 9
#define INF 9999

int minKey(int key[], bool mstSet[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

int printMST(int parent[], int graph[V][V])
{
	printf("Edge \tWeight\n");
	for (int i = 1; i < V; i++)
		printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V])
{
	int parent[V];
	int key[V];
	bool mstSet[V];

	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	key[0] = 0;
	parent[0] = -1;

	for (int count = 0; count < V - 1; count++) {
		int u = minKey(key, mstSet);

    mstSet[u] = true;

    for (int v = 0; v < V; v++)
        if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            parent[v] = u, key[v] = graph[u][v];
	}
	printMST(parent, graph);
}

int main()
{

int graph[V][V] = {
    {0,4,INF,INF,INF,INF,INF,8,INF},
    {4,0,8,INF,INF,INF,INF,11,INF},
    {INF,8,0,7,INF,4,INF,INF,2},
    {INF,INF,7,0,9,14,INF,INF,INF},
    {INF,INF,INF,9,0,10,INF,INF,INF},
    {INF,INF,4,14,10,0,2,INF,INF},
    {INF,INF,INF,INF,INF,2,0,1,6},
    {8,11,INF,INF,INF,INF,1,0,7},
    {INF,INF,2,INF,INF,INF,6,7,0}
  };
	primMST(graph);

	return 0;
}

