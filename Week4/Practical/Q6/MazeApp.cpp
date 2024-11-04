// MazeApp.cpp
#include "Maze.h"
#include <cstring>  // For memcpy()

using namespace std;

int main() {
    char maze[N][N] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
        {'.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
        {'#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.'},
        {'#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
        {'#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
        {'#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    char visited[N][N];
    memcpy(visited, maze, sizeof(maze));  // Copy the original maze to the visited array

    stack<Cell> pathStack;

    // Start from (1, 1) - assuming start position is always (1, 1)
    Cell start = {1, 1};
    Cell end = {10, 10};  // Assuming end position is (10, 10)

    pathStack.push(start);
    visited[start.row][start.col] = 'v';

    while (!pathStack.empty()) {
        Cell current = pathStack.top();

        // Display the maze with the current path
        display(visited);

        if (current.row == end.row && current.col == end.col) {
            cout << "Reached the end of the maze!" << endl;
            break;
        }

        Cell next = hasNeighbor(visited, current);
        if (next.row != -1 && next.col != -1) {
            // Move to the next cell
            pathStack.push(next);
            visited[next.row][next.col] = 'v';
        } else {
            // Backtrack if no neighbor is available
            pathStack.pop();
        }
    }

    if (pathStack.empty()) {
        cout << "No path found." << endl;
    }

    return 0;
}
