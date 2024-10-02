INF = float('inf')

# Function to implement Floyd-Warshall Algorithm
def floyd_warshall(graph):
    V = len(graph)
    dist = [list(row) for row in graph]

    # Adding vertices individually to the shortest path
    for k in range(V):
        for i in range(V):
            for j in range(V):
                if dist[i][k] != INF and dist[k][j] != INF and dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]

    # Print final distance matrix
    for row in dist:
        print(" ".join([str(x) if x != INF else "INF" for x in row]))

# Test case
graph = [
    [0, 3, INF, 7],
    [8, 0, 2, INF],
    [5, INF, 0, 1],
    [2, INF, INF, 0]
]

floyd_warshall(graph)

"""
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
"""
