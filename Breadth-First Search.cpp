#include <bits/stdc++.h>
using namespace std;

// Function for BFS traversal
void BFS(vector<vector<int>> &adj, int s) {
    int V = adj.size();  // Number of vertices

    // Create a visited array to mark visited nodes
    vector<bool> visited(V, false);

    // Create a queue for BFS
    queue<int> q;

    // Mark the starting node as visited and enqueue it
    visited[s] = true;
    q.push(s);

    cout << "BFS traversal starting from node " << s << ": ";

    // Loop until the queue is empty
    while (!q.empty()) {
        // Dequeue a node from the queue and print it
        int node = q.front();
        cout << node << " ";
        q.pop();

        // Get all adjacent vertices of the dequeued node
        for (int neighbor : adj[node]) {
            // If the neighbor has not been visited, mark it as visited and enqueue it
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    cout << endl;
}

// To add an edge in an undirected graph
void addEdge(vector<vector<int>> &adj, int s, int t) {
    adj[s].push_back(t);
    adj[t].push_back(s);  // As it's an undirected graph, we add the reverse edge too
}

int main() {
    int V = 5;  // Number of vertices
    vector<vector<int>> adj(V);

    // Add edges (as per the example graph)
    vector<vector<int>> edges = {{1, 2}, {1, 0}, {2, 0}, {2, 3}, {2, 4}};
    for (auto &e : edges) {
        addEdge(adj, e[0], e[1]);
    }

    int s = 1;  // Starting vertex for BFS
    BFS(adj, s);  // Perform BFS starting from node '1'

    return 0;
}
