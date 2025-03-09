#include <bits/stdc++.h>  // Includes all standard C++ libraries in one go
using namespace std;  // Standard namespace for convenience

// Recursive function for DFS traversal
void DFSRec(vector<vector<int>> &adj, vector<bool> &visited, int s) {
    visited[s] = true;  // Mark the current node as visited

    cout << s << " ";  // Print the current node (vertex) number

    // Recursively visit all adjacent vertices that are not visited yet
    for (int i : adj[s])  // Loop through all the neighbors of the current node (s)
        if (visited[i] == false)  // If the neighbor is not visited
            DFSRec(adj, visited, i);  // Recurse and visit that neighbor
}

// Main DFS function that initializes the visited array and calls DFSRec
void DFS(vector<vector<int>> &adj, int s) {
    vector<bool> visited(adj.size(), false);  // Initialize a visited array with false (none of the nodes are visited)
    DFSRec(adj, visited, s);  // Call the recursive DFS function from the starting node
}

// Function to add an edge between two nodes in an undirected graph
void addEdge(vector<vector<int>> &adj, int s, int t) {
    adj[s].push_back(t);  // Add an edge from node s to node t
    adj[t].push_back(s);  // Since it's an undirected graph, add an edge from node t to node s too
}

int main() {
    int V = 5;  // Define the number of vertices (nodes) in the graph
    vector<vector<int>> adj(V);  // Create an adjacency list for the graph with V nodes
  
    // Add edges between nodes
    vector<vector<int>> edges = {{1, 2}, {1, 0}, {2, 0}, {2, 3}, {2, 4}};  // List of edges to be added
    for (auto &e : edges)  // Loop through the list of edges
        addEdge(adj, e[0], e[1]);  // For each edge (e[0], e[1]), add the edge to the graph

    int s = 1;  // Choose the starting vertex for DFS (starting at node 1)
    cout << "DFS from source: " << s << endl;  // Print the starting node
    DFS(adj, s);  // Call DFS starting from the node `s`

    return 0;  // Return 0 to indicate successful execution
}
