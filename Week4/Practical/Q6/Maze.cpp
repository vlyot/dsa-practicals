#include <iostream>
#include <stack>
#include "Maze.h"
#include <cstring>

using namespace std;

Cell hasNeighbor(char maze[N][N], Cell current){
    int dirRow[] = {0, 1, 0, -1};
    int dirCol[] = {1, 0, -1, 0};
    for (int i = 0; i < 4; i++) {
        int newRow = current.row + dirRow[i];
        int newCol = current.col + dirCol[i];

        // Check if the move is within bounds and is not a wall or already visited
        if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < N) {
            if (maze[newRow][newCol] == '.') {
                return {newRow, newCol};
            }
        }
    }

    // If no valid neighbor found, return {-1, -1}
    return {-1, -1};
}

void display(char maze[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << maze[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "-----------------------------" << endl;
}