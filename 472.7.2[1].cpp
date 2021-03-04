#include<bits/stdc++.h> 
using namespace std;
//Class to represent undirected graph
class Graph 
{ 
	public:
	int V; // No. of vertices 
	// Pointer to an array containing adjacency lists
	list<int> *adj;
	//constructor
	Graph(int V) 
	{ 
		this->V = V; 
		adj = new list<int>[V]; 
	} 
	// function to add an edge to graph 
	void addEdge(int v, int w) 
	{ 
		adj[v].push_back(w);// Add w to v’s list. 
		adj[w].push_back(v); // Add v to w’s list. 
	}
	// A recursive function used by DFS 
	void DFSUtil(int v, bool visited[]) 
	{ 
		visited[v] = true; 
		cout << v+1 << " ";
		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i) 
			if (!visited[*i]) 
				DFSUtil(*i, visited); 
	} 
	// DFS traversal of the vertices reachable from v 
	// DFS traversal of the vertices reachable from v. 
	// It uses recursive DFSUtil() 
	void DFS(int v) 
	{
		// Mark all the vertices as not visited 
		bool *visited = new bool[V]; 
		for (int i = 0; i < V; i++) 
			visited[i] = false;
		// Call the recursive helper function 
		// to print DFS traversal 
		DFSUtil(v, visited); 
	} 
    bool isCyclicUtil(int v, bool visited[], int parent) 
	{
		// Mark the current node as visited and 
		// print it 
	    visited[v] = true;
	    list<int>::iterator i; 
	    // Recur for all the vertices adjacent 
		// to this vertex
	    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
	    { 
	    	// If an adjacent is not visited,then recur for that adjacent
	        if (!visited[*i]) 
	        { 
	           if (isCyclicUtil(*i, visited, v)) 
	              return true; 
	        }
        // If an adjacent is visited and not parent of current vertex,then there is a cycle. 
	        else if (*i != parent) 
	           return true; 
	    } 
	    return false; 
	} 
	bool isCyclic() 
	{
			
    // Mark all the vertices as not visited and not part of recursion stack 
	    bool *visited = new bool[V]; 
	    for (int i = 0; i < V; i++) 
	        visited[i] = false; 
    // Call the recursive helper function to detect cycle in different DFS trees 
	    for (int u = 0; u < V; u++) 
	    {
	    	// Don't recur for u if it is already visited 
	        if (!visited[u])  
	          if (isCyclicUtil(u, visited, -1)) 
	             return true; 
	    } 
	    return false; 
	}
	void APUtil(int u, bool visited[], int disc[], int low[], int parent[], bool ap[]) 
	{ 
		// A static variable is used for simplicity, we can avoid use of static variable by passing a pointer. 
	    static int time = 0; 
	    // Count of children in DFS Tree 
	    int children = 0; 
	    // Mark the current node as visited 
	    visited[u] = true;  // Initialize discovery time and low value 
	    disc[u] = low[u] = ++time; 
	    list<int>::iterator i; 
	    for (i = adj[u].begin(); i != adj[u].end(); ++i) 
	    { 
	        int v = *i;   // v is current adjacent of u 
        // If v is not visited yet, then make it a child of u in DFS tree and recur for it 
	        if (!visited[v]) 
	        { 
	            children++; 
	            parent[v] = u; 
	            APUtil(v, visited, disc, low, parent, ap); 
            // Check if the subtree rooted with v has a connection to one of the ancestors of u 
	            low[u]  = min(low[u], low[v]); 
            // u is an articulation point in following cases 
            // (1) u is root of DFS tree and has two or more chilren. 
	            if (parent[u] == -1 && children > 1) 
	               ap[u] = true;
            // (2) If u is not root and low value of one of its child is more 
            // than discovery value of u.  
	            if (parent[u] != -1 && low[v] >= disc[u]) 
	               ap[u] = true; 
	        } 
        // Update low value of u for parent function calls.
	        else if (v != parent[u]) 
	            low[u]  = min(low[u], disc[v]); 
	    } 
	} 
	// prints articulation points
	void AP() 
	{ 
	    bool *visited = new bool[V]; 
	    int *disc = new int[V]; 
	    int *low = new int[V]; 
	    int *parent = new int[V]; 
	    bool *ap = new bool[V]; // To store articulation points 
    // Initialize parent and visited, and ap(articulation point) arrays 
	    for (int i = 0; i < V; i++) 
	    { 
	        parent[i] = -1; 
	        visited[i] = false; 
	        ap[i] = false; 
	    } 
    // Call the recursive helper function to find articulation points 
    // in DFS tree rooted with vertex 'i' 
	    for (int i = 0; i < V; i++) 
	    {
	    	if (visited[i] == false) 
	            APUtil(i, visited, disc, low, parent, ap); 
		}
    // Now ap[] contains articulation points, print them 
	    cout<<"\nThe articulation point int the given graph are :\nVertex : ";
	    for (int i = 0; i < V; i++) 
	    {
	    	if (ap[i] == true) 
	            cout << i+1 << " "; 
		}
	} 
}; 
int main() 
{
	Graph g(8); 
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(0,3);
	g.addEdge(1,2);
	g.addEdge(1,4);
	g.addEdge(1,5);
	g.addEdge(2,5);
	g.addEdge(4,5);
	g.addEdge(3,7);
	g.addEdge(3,6);
	g.addEdge(6,7);
	cout<<"DFS Traversal with root as 4 is : ";
	g.DFS(3);
	cout<<endl;
	if(g.isCyclic())
	cout<<"\nGraph contains Cycle.\n";
	else
	cout<<"\nGraph doesn't contains Cycle.\n";
	g.AP();
	return 0; 
} 
