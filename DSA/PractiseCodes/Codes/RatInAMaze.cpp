#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// Define the maze dimensions
const int ROWS = 6;
const int COLS = 7;

// Directions for moving in the maze
const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Up, Down, Left, Right
const char directionSymbols[4] = {'^', 'v', '<', '>'}; // For debugging

// Function to print the maze
void printMaze(const vector<vector<char>>& maze) {
    for (const auto& row : maze) {
        for (char cell : row) {
            cout << cell;
        }
        cout << endl;
    }
}

// Function to find the path from exit to mouse
bool findPath(vector<vector<char>>& maze, int x, int y, vector<pair<int, int>>& path) {
    if (maze[x][y] == 'm') {
        path.push_back({x, y}); // Add the mouse position to the path
        return true; // Exit found
    }

    // Mark the cell as part of the path
    maze[x][y] = '.';

    // Explore the adjacent cells
    for (int dir = 0; dir < 4; dir++) {
        int newX = x + directions[dir][0];
        int newY = y + directions[dir][1];

        // Check boundaries and if the cell is valid
        if (newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS && 
            (maze[newX][newY] == '0' || maze[newX][newY] == 'm')) {

            // Recur to the next cell
            if (findPath(maze, newX, newY, path)) {
                path.push_back({x, y}); // Add the current cell to the path
                
                // Change the maze representation
                if (path.size() > 1) {
                    auto last = path[path.size() - 2];
                    if (last.first == x) { // Same row
                        maze[x][min(y, last.second) + 1] = '-'; // Add horizontal path
                    } else { // Same column
                        maze[min(x, last.first) + 1][y] = '|'; // Add vertical path
                    }
                }
                return true; // Found a path
            }
        }
    }

    // Mark the cell back as a wall if no path is found
    maze[x][y] = '0'; // If dead end, reset it to '0'
    return false; // No path found
}

int main() {
    // Define the maze
    vector<vector<char>> maze = {
        {'1', '1', '1', '1', '1', '1', '1'},
        {'1', 'e', '0', '0', '0', '0', '1'},
        {'1', '1', '1', '0', '1', '1', '1'},
        {'1', '0', '0', '0', '0', '1', '1'},
        {'1', '0', 'm', '0', '0', '1', '1'},
        {'1', '1', '1', '1', '1', '1', '1'},
    };

    // Print the original maze
    cout << "Original Maze:" << endl;
    printMaze(maze);
    
    // Define the path vector to hold the positions
    vector<pair<int, int>> path;
    
    // Find the path from exit (1, 1) to mouse (4, 2)
    if (findPath(maze, 1, 1, path)) {
        cout << "\nProcessed Maze with Path:" << endl;
        printMaze(maze);
        
        cout << "\nPath from Exit to Mouse:" << endl;
        for (auto it = path.rbegin(); it != path.rend(); ++it) {
            cout << "[" << it->first << "\t" << it->second << "] ";
        }
        cout << endl;
        cout << "Success" << endl;
    } else {
        cout << "No path found from exit to mouse." << endl;
    }

    return 0;
}
