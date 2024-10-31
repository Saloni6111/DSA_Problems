#include <stdio.h>
#include <stdlib.h>

#define MAXN 10000
#define MAXV 10000

// Node for the segment tree
typedef struct Node {
    int sum;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int sum) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->sum = sum;
    node->left = node->right = NULL;
    return node;
}

// Build the initial segment tree
Node* build(int start, int end, int arr[]) {
    if (start == end) {
        return createNode(arr[start]);
    }
    int mid = (start + end) / 2;
    Node* node = createNode(0);
    node->left = build(start, mid, arr);
    node->right = build(mid + 1, end, arr);
    node->sum = node->left->sum + node->right->sum;
    return node;
}

// Update the segment tree to create a new version
Node* update(Node* prev, int start, int end, int idx, int value) {
    if (start == end) {
        return createNode(value);
    }
    int mid = (start + end) / 2;
    Node* node = createNode(0);
    if (idx <= mid) {
        node->left = update(prev->left, start, mid, idx, value);
        node->right = prev->right;
    } else {
        node->left = prev->left;
        node->right = update(prev->right, mid + 1, end, idx, value);
    }
    node->sum = node->left->sum + node->right->sum;
    return node;
}

// Query the sum in the range [L, R]
int query(Node* node, int start, int end, int L, int R) {
    if (L > end || R < start) return 0;
    if (L <= start && end <= R) return node->sum;
    int mid = (start + end) / 2;
    return query(node->left, start, mid, L, R) + query(node->right, mid + 1, end, L, R);
}

int main() {
    int arr[MAXN] = {1, 2, 3, 4, 5};  // Original array
    int n = 5;

    // Build the initial version of the segment tree
    Node* version[MAXV];
    version[0] = build(0, n - 1, arr);

    // Create a new version with an update
    version[1] = update(version[0], 0, n - 1, 2, 10); // arr[2] = 10

    // Query different versions
    printf("Version 0, sum of range [0, 2]: %d\n", query(version[0], 0, n - 1, 0, 2));
    printf("Version 1, sum of range [0, 2]: %d\n", query(version[1], 0, n - 1, 0, 2));

    // Freeing memory (optional in competitive programming)
    // Implement a recursive function to free nodes if needed.

    return 0;
}
