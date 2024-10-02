import heapq

# Helper function to perform Dijkstra's Algorithm
def dijkstra(graph, src, V):
    dist = [float('inf')] * V
    dist[src] = 0
    pq = [(0, src)]  # (distance, vertex)
    
    while pq:
        current_dist, u = heapq.heappop(pq)
        
        if current_dist > dist[u]:
            continue
            
        for v, weight in graph[u]:
            if dist[u] + weight < dist[v]:
                dist[v] = dist[u] + weight
                heapq.heappush(pq, (dist[v], v))
    
    return dist

# Helper function to perform Bellman-Ford Algorithm
def bellman_ford(graph, src, V):
    dist = [float('inf')] * V
    dist[src] = 0
    
    for i in range(V - 1):
        for u in range(V):
            for v, weight in graph[u]:
                if dist[u] != float('inf') and dist[u] + weight < dist[v]:
                    dist[v] = dist[u] + weight
                    
    # Check for negative-weight cycles
    for u in range(V):
        for v, weight in graph[u]:
            if dist[u] != float('inf') and dist[u] + weight < dist[v]:
                return None  # Negative cycle detected
    
    return dist

# Johnson's Algorithm
def johnson_algorithm(edges, V):
    # Add a new vertex s connected to all vertices with weight 0
    new_graph = [[] for _ in range(V + 1)]
    
    for u, v, w in edges:
        new_graph[u].append((v, w))
    
    # Add the additional vertex and edges
    for i in range(V):
        new_graph[V].append((i, 0))
    
    # Run Bellman-Ford to calculate h function
    h = bellman_ford(new_graph, V, V + 1)
    
    if h is None:
        return "Negative-weight cycle detected!"
    
    # Reweight edges to remove negative weights
    reweighted_graph = [[] for _ in range(V)]
    for u, v, w in edges:
        reweighted_graph[u].append((v, w + h[u] - h[v]))
    
    # Run Dijkstra's for each vertex and restore original weights
    distances = [[float('inf')] * V for _ in range(V)]
    for u in range(V):
        dist_u = dijkstra(reweighted_graph, u, V)
        for v in range(V):
            distances[u][v] = dist_u[v] + h[v] - h[u]
    
    return distances

# Input handling
def main():
    V = int(input("Enter the number of vertices: "))
    E = int(input("Enter the number of edges: "))
    
    edges = []
    print("Enter the edges in the format: source destination weight")
    for _ in range(E):
        u, v, w = map(int, input().split())
        edges.append((u, v, w))
    
    result = johnson_algorithm(edges, V)
    
    if isinstance(result, str):
        print(result)
    else:
        print("Shortest distances between every pair of vertices:")
        for i in range(V):
            for j in range(V):
                print(f"Distance from {i} to {j}: {result[i][j]}")

if __name__ == "__main__":
    main()
