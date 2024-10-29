#include <iostream>
#include <stack>
using namespace std;

#define N 5 // Size of the maze (5x5 grid)

// Maze representation
int maze[N][N] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0}
};

// Direction vectors (right, down, left, up)
int dirX[] = {0, 1, 0, -1};
int dirY[] = {1, 0, -1, 0};

// Function to check if a cell is within bounds and walkable
bool isValidMove(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 0);
}

void mazeTraversal(int startX, int startY, int endX, int endY) {
    // Stack to store (x, y) positions
    stack<pair<int, int>> path;

    // Start from the initial position
    path.push({startX, startY});
    maze[startX][startY] = 2; // Mark starting cell as visited

    while (!path.empty()) {
        // Get the current position
        int currX = path.top().first;
        int currY = path.top().second;

        // Check if we have reached the exit
        if (currX == endX && currY == endY) {
            cout << "Path found:" << endl;
            stack<pair<int, int>> printStack = path;
            while (!printStack.empty()) {
                cout << "(" << printStack.top().first << ", " << printStack.top().second << ") ";
                printStack.pop();
            }
            cout << endl;
            return;
        }

        // Flag to check if a valid move was found
        bool foundMove = false;

        // Try all four possible directions
        for (int i = 0; i < 4; i++) {
            int newX = currX + dirX[i];
            int newY = currY + dirY[i];

            // If the move is valid, push it onto the stack
            if (isValidMove(newX, newY)) {
                path.push({newX, newY});
                maze[newX][newY] = 2; // Mark new cell as visited
                foundMove = true;
                break; // Move in this direction
            }
        }

        // If no valid move is found, backtrack
        if (!foundMove) {
            path.pop();
        }
    }

    // If we reach here, there is no solution
    cout << "No path found." << endl;
}

int main() {
    // Start at (0, 0) and try to reach (4, 4)
    mazeTraversal(0, 0, 4, 4);
    return 0;
}
