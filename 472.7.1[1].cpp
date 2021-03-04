#include<bits/stdc++.h>
using namespace std;
map<char ,int > mp;
//Class to represent undirected graph
class Graph 
{ 
	public :
	int V;
	list<int> *adj; 
	string str;
	Graph(int V,string str) 
	{ 
		this->V = V; 
		this->str = str;
		adj = new list<int>[V]; 
	} 
	void addEdge(int v, int w) 
	{ 
		adj[v].push_back(w);  
		adj[w].push_back(v);
	}
	
//prints bfs traversal from given source
	void BFS(int s)
	{
		
	//mark all the vertices as not visited
		bool *visited=new bool[V];
		for(int i=0;i<V;i++)
		{
			visited[i]=false;
		}
		//create a queue for BFS
		list<int > queue;
		//mark the current(starting) node as visited and enqueue it
		visited[s]=true;
		queue.push_back(s);
		//i will be used to get all the adjacent verticesof a vertex
		list<int >::iterator i;
		while(!queue.empty())
		{
			//dequeue a vertex from queue and print it
			s=queue.front();
			cout<<str[s]<<" ";
			queue.pop_front();
			//get all adjacent vertices og the dequeued vertex s. If a adjacent vertex has not been visited then mark it visited and enqueue it
			for(i=adj[s].begin();i!=adj[s].end();++i)//E component of time comes from this for loop
			{
				if(!visited[*i])
				{
					visited[*i]=true;
					queue.push_back(*i);
				}
			}
		}
	} 
	bool isCyclicUtil(int v, bool visited[], int parent) 
	{ 
	    visited[v] = true; 
	    list<int>::iterator i; 
	    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
	    { 
	        if (!visited[*i]) 
	        { 
	           if (isCyclicUtil(*i, visited, v)) 
	              return true; 
	        }  
	        else if (*i != parent) 
	           return true; 
	    } 
	    return false; 
	} 
	bool isCyclic() 
	{ 
	    bool *visited = new bool[V]; 
	    for (int i = 0; i < V; i++) 
	        visited[i] = false; 
	    for (int u = 0; u < V; u++) 
	    { 
	        if (!visited[u])  
	          if (isCyclicUtil(u, visited, -1)) 
	             return true; 
	    } 
	    return false; 
	}
}; 
int main()
{
	string s = "rstuvwxy";
	Graph g(8,s); 
	for(int i=0;i<s.length();i++)
	{
		mp[s[i]]=i;
	}
	g.addEdge(mp['r'],mp['s']);
	g.addEdge(mp['r'],mp['v']);
	g.addEdge(mp['s'],mp['v']);
	g.addEdge(mp['s'],mp['w']);
	g.addEdge(mp['t'],mp['w']);
	g.addEdge(mp['t'],mp['x']);
	g.addEdge(mp['v'],mp['w']);
	g.addEdge(mp['w'],mp['x']);
	g.addEdge(mp['v'],mp['u']);
	g.addEdge(mp['v'],mp['y']);
	g.addEdge(mp['u'],mp['y']);
	cout<<"BFS Traversal with root as v is : ";
	g.BFS(4);
	cout<<endl;
	if(g.isCyclic())
	cout<<"\nGraph contains Cycle.\n";
	else
	cout<<"\nGraph doesn't contains Cycle.\n";
	return 0;
} 
