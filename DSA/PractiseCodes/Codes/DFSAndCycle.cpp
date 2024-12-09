#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS and detect cycle
bool DFSCycleUnd(int vertex, int parent, const vector<vector<int>> &adjList, vector<bool> &visited) {
    visited[vertex] = true;

    // Traverse through all adjacent vertices
    for (int neighbor : adjList[vertex]) {
        if (!visited[neighbor]) {
            // Recursive DFS call
            if (DFSCycleUnd(neighbor, vertex, adjList, visited)) {
                return true;
            }
        } else if (neighbor != parent) {
            // If visited and not the parent, it's a cycle
            return true;
        }
    }

    return false;
}

int main() {
    int n = 5; // Number of vertices
    vector<vector<int>> adjList = {
        {1, 2},    // Edges from vertex 0
        {0, 3, 4}, // Edges from vertex 1
        {0},       // Edges from vertex 2
        {1},       // Edges from vertex 3
        {1}        // Edges from vertex 4
    }
}