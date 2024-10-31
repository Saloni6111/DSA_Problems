#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure for the queue
typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

// Function to create a queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == -1;
}

// Function to enqueue an element
void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0; // First element to be enqueued
    }
    q->rear++;
    q->items[q->rear] = value;
}

// Function to dequeue an element
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) { // Reset the queue
        q->front = q->rear = -1;
    }
    return item;
}

// Function to perform BFS
void bfs(int graph[MAX][MAX], int start, int visited[MAX], int n) {
    Queue* q = createQueue();
    enqueue(q, start);
    visited[start] = 1; // Mark the starting node as visited

    while (!isEmpty(q)) {
        int current = dequeue(q);
        printf("%d ", current); // Process the current node

        // Explore neighbors
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) { // If edge exists and not visited
                enqueue(q, i);
                visited[i] = 1; // Mark neighbor as visited
            }
        }
    }

    free(q);
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

    printf("BFS Traversal starting from vertex 0:\n");
    bfs(graph, 0, visited, n);

    return 0;
}
