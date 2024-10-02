/**
 * Kosaraju's Algorithm Steps:
 * Topological Sorting based on Finish Time: The first step is to perform a depth-first search (DFS) on the graph and store nodes in a stack based on their finishing times. This is similar to topological sorting but applied to all nodes regardless of whether the graph is a DAG (Directed Acyclic Graph) or not.
 *
 * Transpose the Graph: After the first DFS, we reverse all the edges of the graph (transpose of the graph). This is necessary because, in a transposed graph, a path between two nodes in one SCC can be explored in reverse.
 *
 * DFS on Transposed Graph: Finally, we perform DFS on the transposed graph, processing nodes in the order of their finishing times (retrieved from the stack). Each DFS call that starts from an unvisited node will identify a new SCC.
 *
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Kosaraju's Algorithm for finding strongly connected components (SCC)
 * Step 1: Perform DFS and push nodes into the stack based on their finishing times
 * Step 2: Transpose the graph (reverse all edges)
 * Step 3: Perform DFS on the transposed graph in the order of decreasing finish times
 * Step 4: Count SCCs by processing nodes in order of decreasing finish time
 */

/**
 * Time Complexity: O(V+E) for DFS, O(V+E) for dfsTranspose, (O(V) and O(V+E)) inside Kosaraju => Overall TC: => (V+E)
 * Space Complexity: O(V) for stack and O(V) for Visited array, O(V+E) => Overall SC: => O(V+E)
 */

class Solution
{
    /**
     * DFS Function (dfs): This function performs a depth-first search and pushes nodes into the stack once all adjacent nodes have been explored. The stack helps in sorting nodes based on their finishing times.
     */
    void dfs(int src, vector<bool> &vis, stack<int> &st, vector<vector<int>> &adj)
    {
        vis[src] = true;
        for (auto it : adj[src])
        {
            if (!vis[it])
            {
                dfs(it, vis, st, adj);
            }
        }
        st.push(src); // Push to stack after visiting all neighbors
    }

    /**
     * DFS Function for Transposed Graph (dfsTranspose): This function is used to perform DFS on the transposed graph. It starts at an unvisited node and marks all reachable nodes, effectively identifying an SCC.
    **/
    void dfsTranspose(int src, vector<bool> &vis, unordered_map<int, list<int>> &transposedGraph)
    {
        vis[src] = true;
        for (auto nbr : transposedGraph[src])
        {
            if (!vis[nbr])
            {
                dfsTranspose(nbr, vis, transposedGraph);
            }
        }
    }

public:
    // Function to find the number of strongly connected components in the graph
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        stack<int> st;
        vector<bool> vis(V, false);

        // Step 1: Sort nodes based on finishing times using DFS
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, st, adj);
            }
        }

        // Step 2: Create the transposed graph or Revese the direction of edges
        unordered_map<int, list<int>> transposedGraph;
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                transposedGraph[it].push_back(i); // Reverse edge
            }
        }

        // Step 3: Reset visited array and apply DFS on the transposed graph
        fill(vis.begin(), vis.end(), false);

        // Step 4: Count SCCs by processing nodes in order of decreasing finish time
        int SCC = 0;
        while (!st.empty())
        {
            int top = st.top();
            st.pop();
            if (!vis[top])
            {
                SCC++;
                dfsTranspose(top, vis, transposedGraph);
            }
        }

        return SCC;
    }
};

// Test case for Kosaraju's algorithm
int main()
{
    Solution sol;
    // Sample directed graph with 5 vertices
    vector<vector<int>> adj = {
        {1}, // 0 -> 1
        {2}, // 1 -> 2
        {0}, // 2 -> 0 (Cycle among 0, 1, 2)
        {4}, // 3 -> 4
        {}   // 4 -> (no outgoing edges)
    };

    // Number of vertices
    int n = 5;

    // Call Kosaraju's algorithm to count SCCs
    int numSCC = sol.kosaraju(n, adj);
    cout << "Number of Strongly Connected Components (SCC): " << numSCC << endl;

    return 0;
}
