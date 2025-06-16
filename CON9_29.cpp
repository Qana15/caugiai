#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

void dfs(int v, const unordered_map<int, set<int>>& graph, set<int>& visited) {
    visited.insert(v);
    for (int neighbor : graph.at(v)) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(neighbor, graph, visited);
        }
    }
}

bool isConnected(const unordered_map<int, set<int>>& graph, int numVertices) {
    set<int> visited;
    // Start DFS from the first vertex in the graph
    dfs(graph.begin()->first, graph, visited);
    return visited.size() == numVertices;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;

        unordered_map<int, set<int>> graph;
        vector<int> degree(V + 1, 0); // Degree of each vertex

        for (int i = 0; i < E; ++i) {
            int u, v;
            cin >> u >> v;
            graph[u].insert(v);
            graph[v].insert(u); // Since the graph is undirected
            degree[u]++;
            degree[v]++;
        }

        // Check the degree of vertices
        int oddCount = 0;
        for (int i = 1; i <= V; ++i) {
            if (degree[i] % 2 != 0) {
                oddCount++;
            }
        }

        // Check if the graph is connected
        bool connected = isConnected(graph, V);

        if (oddCount == 0 && connected) {
            cout << 2 << endl; // Chu trình Euler
        } else if (oddCount == 2 && connected) {
            cout << 1 << endl; // Đường đi Euler
        } else {
            cout << 0 << endl; // Không có
        }
    }
    return 0;
}