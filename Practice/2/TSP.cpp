#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

// Example distance matrix for 4 cities
int dist[4][4] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int tsp(int start, vector<int> cities) {
    int minPath = INT_MAX;
    do {
        int currentCost = 0;
        int k = start;
        for (int i = 0; i < cities.size(); i++) {
            currentCost += dist[k][cities[i]];
            k = cities[i];
        }
        currentCost += dist[k][start]; // Return to start
        minPath = min(minPath, currentCost);
    } while (next_permutation(cities.begin(), cities.end()));
    return minPath;
}

int main() {
    int start = 0;
    vector<int> cities = {1, 2, 3};  // Remaining cities
    cout << "Minimum travel cost: " << tsp(start, cities) << endl;
    return 0;
}
