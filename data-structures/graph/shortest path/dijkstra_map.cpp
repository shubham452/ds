#include <bits/stdc++.h>
using namespace std;

vector<int> calculateDijkstra(int n, int m, vector<vector<int>> edges, int start_vertex) {
    unordered_map<int, vector<pair<int, int>>> adj;

    // Build the adjacency list
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});  // If the graph is directed, remove this line
    }

    unordered_map<int, int> dist;
    unordered_map<int, bool> visited;

    // Initialize distances and visited
    for (auto pair : adj) {
        int vertex = pair.first;
        dist[vertex] = INT_MAX;
        visited[vertex] = false;
    }

    dist[start_vertex] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start_vertex});

    // Dijkstra's algorithm
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        
        visited[u] = true;

        for (auto pair : adj[u]) {
            int v = pair.first;
            int weight = pair.second;

            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    vector<int> distances(n, INT_MAX);
    for (auto pair : dist) {
        distances[pair.first] = pair.second;
    }

    return distances;
}

int main() {
    int n = 9; // Number of vertices
    int m = 14; // Number of edges
    vector<vector<int>> edges = {
        {0, 1, 4},
        {0, 7, 8},
        {1, 2, 8},
        {1, 7, 11},
        {2, 3, 7},
        {2, 8, 2},
        {2, 5, 4},
        {3, 4, 9},
        {3, 5, 14},
        {4, 5, 10},
        {5, 6, 2},
        {6, 7, 1},
        {6, 8, 6},
        {7, 8, 7}
    };
    int start_vertex = 0;
    vector<int> distances = calculateDijkstra(n, m, edges, start_vertex);

    cout << "Shortest distances from vertex " << start_vertex << ":" << endl;
    for (int i = 0; i < distances.size(); i++) {
        cout << "Vertex " << i << ": " << distances[i] << endl;
    }

    return 0;
}
