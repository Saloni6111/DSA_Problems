#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

// Function to perform topological sort
vector<char> findAlienOrder(vector<char>& characters, vector<pair<char, char>>& dependencies) {
    unordered_map<char, vector<char>> graph;  // Adjacency list for the graph
    unordered_map<char, int> inDegree;  // Track in-degrees for each character
    
    // Initialize in-degrees and graph structure
    for (char ch : characters) {
        inDegree[ch] = 0;
        graph[ch] = {};
    }

    // Build the graph and calculate in-degrees
    for (auto& dep : dependencies) {
        char u = dep.first;
        char v = dep.second;
        graph[u].push_back(v);
        inDegree[v]++;
    }

    // Queue for nodes with 0 in-degree
    queue<char> q;
    for (auto& ch : inDegree) {
        if (ch.second == 0) {
            q.push(ch.first);
        }
    }

    vector<char> result;
    while (!q.empty()) {
        char node = q.front();
        q.pop();
        result.push_back(node);

        // Reduce the in-degree of adjacent nodes
        for (char neighbor : graph[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // If the result size is equal to the number of characters, it's a valid order
    if (result.size() == characters.size()) {
        return result;
    } else {
        return {};  // Return an empty vector if a valid topological order is not possible
    }
}

int main() {
    // Example input: alien language characters and dependencies
    vector<char> characters = {'a', 'b', 'c', 'd'};
    vector<pair<char, char>> dependencies = { {'a', 'c'}, {'b', 'c'}, {'c', 'd'} };

    vector<char> result = findAlienOrder(characters, dependencies);

    if (!result.empty()) {
        cout << "A valid sequence of characters in the alien language is: ";
        for (char ch : result) {
            cout << ch << " ";
        }
        cout << endl;
    } else {
        cout << "No valid sequence exists (circular dependency detected)." << endl;
    }

    return 0;
}
