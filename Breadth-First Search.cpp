#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int start, vector<vector<int>>& graph, int n) {
    // A vector to track whether a node has been visited or not.
    vector<bool> visited(n, false);
    
    // Create a queue to store the nodes to be processed (FIFO).
    queue<int> q;
    
    // Mark the start node as visited and push it to the queue.
    visited[start] = true;
    q.push(start);
    
    // Start BFS loop.
    while (!q.empty()) {
        // Dequeue a node from the queue.
        int node = q.front();
        q.pop();
        
        // Print the node (for demonstration purposes).
        cout << "Visited node: " << node << endl;
        
        // Process all the neighbors of the current node.
        for (int neighbor : graph[node]) {
            // If a neighbor has not been visited, mark it as visited and push it to the queue.
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    // Define the number of nodes in the graph.
    int n = 6;
    
    // Create an adjacency list to represent the graph.
    vector<vector<int>> graph(n);
    
    // Add edges (example graph).
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(0);
    graph[1].push_back(3);
    graph[2].push_back(0);
    graph[2].push_back(4);
    graph[3].push_back(1);
    graph[3].push_back(5);
    graph[4].push_back(2);
    graph[5].push_back(3);
    
    // Start BFS from node 0.
    bfs(0, graph, n);
    
    return 0;
}
