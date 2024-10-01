#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to implement Floyd-Warshall Algorithm
void floydWarshall(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<vector<int>> dist = graph;

    // Adding vertices individually to the shortest path
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX 
                    && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print final distance matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Test case
    vector<vector<int>> graph = {{0, 3, INT_MAX, 7},
                                 {8, 0, 2, INT_MAX},
                                 {5, INT_MAX, 0, 1},
                                 {2, INT_MAX, INT_MAX, 0}};

    floydWarshall(graph);
    return 0;
}

/*
Test case:
Graph:
0 3 INF 7
8 0 2 INF
5 INF 0 1
2 INF INF 0
Expected output:
0 3 5 6
5 0 2 3
3 6 0 1
2 5 7 0
*/
