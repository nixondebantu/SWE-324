#include <bits/stdc++.h>

using namespace std;

// Function to perform Depth-Limited Search
bool DLS(int node, int target, int depth, vector<vector<int>>& graph) {
    if (depth == 0 && node == target) {
        return true; // Target node found within the depth limit
    }
    if (depth > 0) {
        for (int neighbor : graph[node]) {
            if (DLS(neighbor, target, depth - 1, graph)) {
                return true; // Target node found in the subtree
            }
        }
    }
    return false; // Target node not found within the depth limit
}

// Function to perform Depth-First Search
bool DFS(int start, int target, vector<vector<int>>& graph) {
    stack<int> stack;
    vector<bool> visited(graph.size(), false);

    stack.push(start);
    visited[start] = true;

    while (!stack.empty()) {
        int node = stack.top();
        stack.pop();

        if (node == target) {
            return true; // Target node found
        }

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                stack.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    return false; // Target node not found
}

int main() {

    // User input for graph
    int numNodes, numEdges;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<int>> graph(numNodes);

    cout << "Enter the edges (node1 node2):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
    }
    // User input
    int startNode, targetNode, depthLimit;
    cout << "Enter the starting node: ";
    cin >> startNode;
    cout << "Enter the target node: ";
    cin >> targetNode;
    cout << "Enter the depth limit: ";
    cin >> depthLimit;

    // Perform Depth-Limited Search
    bool foundDLS = DLS(startNode, targetNode, depthLimit, graph);

    // Perform Depth-First Search
    bool foundDFS = DFS(startNode, targetNode, graph);

    cout << "Depth-Limited Search: " << (foundDLS ? "Target found" : "Target not found") << endl;
    cout << "Depth-First Search: " << (foundDFS ? "Target found" : "Target not found") << endl;

    return 0;
}
