import java.util.ArrayList;

public class DepthFirstSearch {
    // Function to perform DFS traversal
    public ArrayList<Integer> dfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj) {
        boolean[] visited = new boolean[V]; // Track visited vertices
        ArrayList<Integer> result = new ArrayList<>(); // Store DFS traversal
        // Start DFS from the first vertex (0)
        helper(0, visited, result, adj);
        return result; // Return the result list
    }

    // Helper function for DFS
    void helper(int vertex, boolean[] visited, ArrayList<Integer> result, ArrayList<ArrayList<Integer>> adjList) {
        visited[vertex] = true; // Mark the current vertex as visited
        result.add(vertex); // Add the current vertex to the result list
        
        // Explore neighbors of the current vertex
        for (int neighbour : adjList.get(vertex)) {
            if (!visited[neighbour]) { // If the neighbor hasn't been visited
                helper(neighbour, visited, result, adjList); // Recursive call for DFS
            }
        }
    }

    public static void main(String[] args) {
        // Example usage
        int V = 5; // Number of vertices
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        
        // Initialize adjacency list for the graph
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }

        // Adding edges (example for an undirected graph)
        adj.get(0).add(1);
        adj.get(0).add(2);
        adj.get(1).add(3);
        adj.get(1).add(4);
        adj.get(2).add(4);
        
        // Create an instance of DepthFirstSearch and perform DFS
        DepthFirstSearch dfs = new DepthFirstSearch();
        ArrayList<Integer> dfsResult = dfs.dfsOfGraph(V, adj);
        
        // Print the DFS traversal result
        System.out.println("DFS Traversal: " + dfsResult);
    }
}