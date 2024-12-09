#include <iostream>

using namespace std;

// Node to store adjacency list
class AdjNode {
public:
    int vertex;
    AdjNode* next;
    AdjNode(int data)
    {
        vertex = data;
        next = NULL;
    }
};

// Adjacency List representation
class AdjList {
private:
    int v;
    AdjNode** graph;

public:
    AdjList(int vertices)
    {
        v = vertices;
        graph = new AdjNode*[v];
        for (int i = 0; i < v; ++i)
            graph[i] = NULL;
    }

    // Function to add an edge from a source vertex
    // to a destination vertex
    void addEdge(int source, int destination)
    {
        AdjNode* node = new AdjNode(destination);
        node->next = graph[source];
        graph[source] = node;
    }

    // Function to add a vertex between two vertices
    void addVertex(int vk, int source, int destination)
    {
        addEdge(source, vk);
        addEdge(vk, destination);
    }

    // Function to print the graph
    void printGraph()
    {
        for (int i = 0; i < v; ++i) {
            cout << i << " ";
            AdjNode* temp = graph[i];
            while (temp != NULL) {
                cout << "-> " << temp->vertex << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    // Function to delete a vertex
    void delVertex(int k)
    {
        // Iterate through all the vertices of the graph
        for (int i = 0; i < v; ++i) {
            AdjNode* temp = graph[i];
            if (i == k) {
                graph[i] = temp->next;
                temp = graph[i];
            }
            // Delete the vertex using linked list concept
            while (temp != NULL) {
                if (temp->vertex == k) {
                    break;
                }
                AdjNode* prev = temp;
                temp = temp->next;
                if (temp == NULL) {
                    continue;
                }
                prev->next = temp->next;
                temp = NULL;
            }
        }
    }
};

int main()
{
    int V = 6;
    AdjList graph(V);
    graph.addEdge(0, 1);
    graph.addEdge(0, 3);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(3, 2);
    graph.addEdge(4, 3);

    cout << "Initial adjacency list" << endl;
    graph.printGraph();

    // Add vertex
    graph.addVertex(5, 3, 2);
    cout << "Adjacency list after adding vertex" << endl;
    graph.printGraph();

    // Delete vertex
    graph.delVertex(4);
    cout << "Adjacency list after deleting vertex" << endl;
    graph.printGraph();

    return 0;
}