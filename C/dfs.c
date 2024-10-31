#include <stdio.h>

#define MAX 100

// Function to perform DFS
void dfs(int graph[MAX][MAX], int visited[], int node, int n) {
    visited[node] = 1; // Mark the current node as visited
    printf("%d ", node); // Process the current node

    // Recur for all the vertices adjacent to this vertex
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) { // If there's an edge and it's not visited
            dfs(graph, visited, i, n);
        }
    }
}

int main() {
    int graph[MAX][MAX] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };

    int visited[MAX] = {0}; // Visited array
    int n = 5; // Number of vertices

    printf("DFS Traversal starting from vertex 0:\n");
    dfs(graph, visited, 0, n);

    return 0;
}
