import java.util.Arrays;

public class FloydWarshall {
    
    final static int INF = 99999;
    
    // Function to implement Floyd-Warshall Algorithm
    public static void floydWarshall(int[][] graph) {
        int V = graph.length;
        int[][] dist = new int[V][V];

        for (int i = 0; i < V; i++)
            dist[i] = Arrays.copyOf(graph[i], V);

        // Adding vertices individually to the shortest path
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF 
                        && dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        // Print final distance matrix
        printSolution(dist);
    }

    // Helper function to print the distance matrix
    public static void printSolution(int[][] dist) {
        int V = dist.length;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] == INF)
                    System.out.print("INF ");
                else
                    System.out.print(dist[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        // Test case
        int[][] graph = { {0, 3, INF, 7},
                          {8, 0, 2, INF},
                          {5, INF, 0, 1},
                          {2, INF, INF, 0} };

        floydWarshall(graph);
    }
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
