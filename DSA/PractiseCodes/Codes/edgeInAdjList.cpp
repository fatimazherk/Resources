// C++ implementation of the above approach

#include <bits/stdc++.h>
using namespace std;

// A utility function to add an edge in an
// undirected graph.
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

// A utility function to delete an edge in an
// undirected graph.
void delEdge(vector<int> adj[], int u, int v)
{
	// Traversing through the first vector list
	// and removing the second element from it
	for (int i = 0; i < adj[u].size(); i++) {
		if (adj[u][i] == v) {
			adj[u].erase(adj[u].begin() + i);
			break;
		}
	}

	// Traversing through the second vector list
	// and removing the first element from it
	for (int i = 0; i < adj[v].size(); i++) {
		if (adj[v][i] == u) {
			adj[v].erase(adj[v].begin() + i);
			break;
		}
	}
}

// A utility function to print the adjacency list
// representation of graph
void printGraph(vector<int> adj[], int V)
{
	for (int v = 0; v < V; ++v) {
		cout << "vertex " << v << " ";
		for (auto x : adj[v])
			cout << "-> " << x;
		printf("\n");
	}
	printf("\n");
}

// Driver code
int main()
{
	int V = 5;
	vector<int> adj[V];

	// Adding edge as shown in the example figure
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 4);
	addEdge(adj, 1, 2);
	addEdge(adj, 1, 3);
	addEdge(adj, 1, 4);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 4);

	// Printing adjacency matrix
	printGraph(adj, V);

	// Deleting edge (1, 4)
	// as shown in the example figure
	delEdge(adj, 1, 4);

	// Printing adjacency matrix
	printGraph(adj, V);

	return 0;
}
