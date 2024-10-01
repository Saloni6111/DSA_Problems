#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

#define INF INT_MAX

struct Edge {
    int u, v, w;
};

struct Graph {
    int V, E;
    vector<Edge> edges;
    Graph(int V, int E) : V(V), E(E) {
        edges.resize(E);
    }
};

bool bellmanFord(Graph& g, int src, vector<int>& dist) {
    dist.assign(g.V, INF);
    dist[src] = 0;
    for (int i = 0; i < g.V - 1; i++) {
        for (const auto& e : g.edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v])
                dist[e.v] = dist[e.u] + e.w;
        }
    }
    for (const auto& e : g.edges) {
        if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v])
            return false;
    }
    return true;
}

void dijkstra(vector<vector<int>>& adj, int src, vector<int>& dist) {
    int V = adj.size();
    vector<int> sptSet(V, 0);
    dist.assign(V, INF);
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        int u = -1;
        for (int j = 0; j < V; j++) {
            if (!sptSet[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        }
        if (dist[u] == INF) break;
        sptSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && adj[u][v] != INF && dist[u] + adj[u][v] < dist[v])
                dist[v] = dist[u] + adj[u][v];
        }
    }
}

void johnson(Graph& g) {
    int V = g.V;
    Graph newG(V + 1, g.E + V);

    for (int i = 0; i < g.E; i++) {
        newG.edges[i] = g.edges[i];
    }
    for (int i = 0; i < V; i++) {
        newG.edges[g.E + i] = {V, i, 0};
    }

    vector<int> h;
    if (!bellmanFord(newG, V, h)) {
        cout << "Negative weight cycle\n";
        return;
    }

    vector<vector<int>> adj(V, vector<int>(V, INF));
    for (const auto& e : g.edges) {
        adj[e.u][e.v] = e.w + h[e.u] - h[e.v];
    }

    for (int u = 0; u < V; u++) {
        vector<int> dist;
        dijkstra(adj, u, dist);
        for (int v = 0; v < V; v++) {
            if (dist[v] != INF)
                dist[v] = dist[v] - h[u] + h[v];
            cout << u << " -> " << v << ": " << dist[v] << endl;
        }
        cout << endl;
    }
}

int main() {
    int V = 5, E = 8;
    Graph g(V, E);

    g.edges[0] = {0, 1, -1};
    g.edges[1] = {0, 2, 4};
    g.edges[2] = {1, 2, 3};
    g.edges[3] = {1, 3, 2};
    g.edges[4] = {1, 4, 2};
    g.edges[5] = {3, 2, 5};
    g.edges[6] = {3, 1, 1};
    g.edges[7] = {4, 3, -3};

    johnson(g);

    return 0;
}
