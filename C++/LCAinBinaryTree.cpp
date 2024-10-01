// C++ program to print right view of Binary Tree
// using recursion
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

void RecursiveRightView(Node* root, int level, 
                        int& maxLevel, vector<int>& result) {
    if (!root) return;

    if (level > maxLevel) {
        result.push_back(root->data);
        maxLevel = level;
    }

    RecursiveRightView(root->right, level + 1,
                       maxLevel, result);
    RecursiveRightView(root->left, level + 1,
                       maxLevel, result);
}

vector<int> rightView(Node *root) {
    vector<int> result;
    int maxLevel = -1;
    RecursiveRightView(root, 0, maxLevel, result);
    
    return result;
}

void printArray(vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    vector<int> result = rightView(root);
    
    printArray(result);
    
    return 0;
}
