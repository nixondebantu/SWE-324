#include <bits/stdc++.h>

using namespace std;

// Function to perform Depth First Search (DFS)
bool DFS(int start, int target, vector<vector<int>>& graph) {
    stack<int> st;
    vector<bool> visited(graph.size(), false);

    st.push(start);
    visited[start] = true;

    while (!st.empty()) {
        int current = st.top();
        st.pop();

        if (current == target) {
            return true;
        }

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                st.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    return false;
}

// Function to perform Iterative Deepening Search (IDS)
bool IDS(int start, int target, vector<vector<int>>& graph) {
    int maxDepth = graph.size(); // Maximum depth to explore

    for (int depth = 0; depth <= maxDepth; depth++) {
        stack<int> st;
        vector<bool> visited(graph.size(), false);

        st.push(start);
        visited[start] = true;

        while (!st.empty()) {
            int current = st.top();
            st.pop();

            if (current == target) {
                return true;
            }

            if (depth > 0) {
                // Check if the current depth is within the limit
                if (depth >= st.size()) {
                    continue;
                }
            }

            for (int neighbor : graph[current]) {
                if (!visited[neighbor]) {
                    st.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

    return false;
}

int main() {
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

    int startNode, targetNode;
    cout << "Enter the start node: ";
    cin >> startNode;
    cout << "Enter the target node: ";
    cin >> targetNode;

    // Perform Depth First Search (DFS)
    bool dfsResult = DFS(startNode, targetNode, graph);
    cout << "DFS Result: " << (dfsResult ? "Found" : "Not Found") << endl;

    // Perform Iterative Deepening Search (IDS)
    bool idsResult = IDS(startNode, targetNode, graph);
    cout << "IDS Result: " << (idsResult ? "Found" : "Not Found") << endl;

    return 0;
}
