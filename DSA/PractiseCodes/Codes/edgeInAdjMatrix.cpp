// C++ program to add and remove edge
// in the adjacency matrix of a graph

#include <iostream>
using namespace std;

class Graph {
private:
	// Number of vertices
	int n;

	// Adjacency matrix
	int g[10][10];

public:
	// Constructor
	Graph(int x)
	{
		n = x;

		// Initializing each element of the
		// adjacency matrix to zero
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				g[i][j] = 0;
			}
		}
	}

	// Function to display adjacency matrix
	void displayAdjacencyMatrix()
	{
		// Displaying the 2D matrix
		for (int i = 0; i < n; i++) {
			cout << "\n";
			for (int j = 0; j < n; j++) {
				cout << " " << g[i][j];
			}
		}
	}

	// Function to update adjacency
	// matrix for edge insertion
	void addEdge(int x, int y)
	{
		// Checks if the vertices
		// exist in the graph
		if ((x < 0) || (x >= n)) {
			cout << "Vertex" << x
				<< " does not exist!";
		}
		if ((y < 0) || (y >= n)) {
			cout << "Vertex" << y
				<< " does not exist!";
		}

		// Checks if it is a self edge
		if (x == y) {
			cout << "Same Vertex!";
		}

		else {
			// Insert edge
			g[y][x] = 1;
			g[x][y] = 1;
		}
	}

	// Function to update adjacency
	// matrix for edge removal
	void removeEdge(int x, int y)
	{
		// Checks if the vertices
		// exist in the graph
		if ((x < 0) || (x >= n)) {
			cout << "Vertex" << x
				<< " does not exist!";
		}
		if ((y < 0) || (y >= n)) {
			cout << "Vertex" << y
				<< " does not exist!";
		}

		// Checks if it is a self edge
		if (x == y) {
			cout << "Same Vertex!";
		}

		else {
			// Remove edge
			g[y][x] = 0;
			g[x][y] = 0;
		}
	}
};

// Driver Code
int main()
{
	int N = 6, X = 2, Y = 3;

	Graph obj(N);

	// Adding edges to the graph
	obj.addEdge(0, 1);
	obj.addEdge(0, 2);
	obj.addEdge(0, 3);
	obj.addEdge(0, 4);
	obj.addEdge(1, 3);
	obj.addEdge(2, 3);
	obj.addEdge(2, 4);
	obj.addEdge(2, 5);
	obj.addEdge(3, 5);

	cout << "Adjacency matrix after"
		<< " edge insertions:\n";
	obj.displayAdjacencyMatrix();

	obj.removeEdge(X, Y);

	cout << "\nAdjacency matrix after"
		<< " edge removal:\n";
	obj.displayAdjacencyMatrix();

	return 0;
}
