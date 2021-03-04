#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// data structure to store graph edges
struct Edge {
	int src, dest;
};

// class to represent a graph object
class Graph
{
public:
	// construct a vector of vectors to represent an adjacency list
	vector<vector<int>> adjList;

	// Graph Constructor
	Graph(vector<Edge> const &edges, int N)
	{
		// resize the vector to N elements of type vector<int>
		adjList.resize(N + 1);

		// add edges to the graph
		for (auto &edge: edges)
			adjList[edge.src].push_back(edge.dest);
	}
};

// class to represent a disjoint set
class Main
{
	unordered_map<int, int> parent;
public:
	// perform MakeSet operation
	void makeSet(int N)
	{
		// create N disjoint sets (one for each vertex)
		for (int i = 1; i <= N; i++)
			parent[i] = i;
	}

	// Find the root of the set in which element k belongs
	int Find(int k)
	{
		// if k is root
		if (parent[k] == k)
			return k;

		// recur for parent until we find root
		return Find(parent[k]);
	}

	// Perform Union of two subsets
	void Union(int a, int b)
	{
		// find root of the sets in which elements
		// x and y belongs
		int x = Find(a);
		int y = Find(b);

		parent[x] = y;
	}
};

// Returns true if graph has cycle
bool findCycle(Graph const &graph, int N)
{
	// initialize Main class
	Main ds;

	// create singleton set for each element of universe
	ds.makeSet(N);

	// consider every edge (u, v)
	for (int u = 1; u <= N; u++)
	{
		// Recur for all adjacent vertices
		for (int v : graph.adjList[u])
		{
			// find root of the sets to which elements
			// u and v belongs
			int x = ds.Find(u);
			int y = ds.Find(v);

			// both u and v have same parent, cycle is found
			if (x == y)
				return true;
			else
				ds.Union(x, y);
		}
	}

	return false;
}

// Union-Find Algorithm for Cycle Detection in graph
int main()
{
	// vector of graph edges as per above diagram
	vector<Edge> edges =
	{
		{1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4},
		{3, 5}, {8, 9}, {8, 12}, {9, 10}, {9, 11}, {11, 12}
		// edge (11, 12) introduces a cycle in the graph
	};

	// Number of nodes in the graph
	int N = 12;

	// create a graph from edges
	Graph graph(edges, N);

	if (findCycle(graph, N))
		cout << "Cycle is Found";
	else
		cout << "No Cycle Found";

	return 0;
}
