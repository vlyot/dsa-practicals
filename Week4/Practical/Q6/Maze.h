#pragma once
#include <iostream>
#include <stack>

#define N 12

struct Cell
{
	int row;
	int col;

};

Cell hasNeighbor(char [N][N], Cell);

void display(char[N][N]);
