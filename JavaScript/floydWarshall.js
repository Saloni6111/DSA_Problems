const INF = Number.MAX_SAFE_INTEGER;

// Function to implement Floyd-Warshall Algorithm
function floydWarshall(graph) {
    const V = graph.length;
    const dist = graph.map(row => [...row]);

    // Adding vertices individually to the shortest path
    for (let k = 0; k < V; k++) {
        for (let i = 0; i < V; i++) {
            for (let j = 0; j < V; j++) {
                if (dist[i][k] !== INF && dist[k][j] !== INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print final distance matrix
    for (let i = 0; i < V; i++) {
        let row = '';
        for (let j = 0; j < V; j++) {
            if (dist[i][j] === INF) row += 'INF ';
            else row += dist[i][j] + ' ';
        }
        console.log(row);
    }
}

// Test case
const graph = [
    [0, 3, INF, 7],
    [8, 0, 2, INF],
    [5, INF, 0, 1],
    [2, INF, INF, 0]
];

floydWarshall(graph);

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
