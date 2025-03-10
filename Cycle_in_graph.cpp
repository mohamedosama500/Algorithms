#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Graph {
public:
    unordered_map<char, vector<char>> adjList;

    // Add edge to the graph
    void addEdge(char u, char v) {
        adjList[u].push_back(v);
    }

    // Helper function for DFS traversal
    bool dfs(char node, unordered_map<char, bool>& visited, unordered_map<char, bool>& recStack) {
        // Mark the current node as visited and add to the recursion stack
        visited[node] = true;
        recStack[node] = true;

        // Recur for all the adjacent vertices of this node
        for (char neighbor : adjList[node]) {
            // If the neighbor is not visited, recurse on it
            if (!visited[neighbor] && dfs(neighbor, visited, recStack))
                return true;
            // If the neighbor is in the recursion stack, it means there's a cycle
            else if (recStack[neighbor]) {
                return true;
            }
        }

        // Remove the node from recursion stack before returning
        recStack[node] = false;
        return false;
    }

    // Function to detect cycle in the graph
    bool detectCycle() {
        unordered_map<char, bool> visited;
        unordered_map<char, bool> recStack;

        // Check for cycle in every vertex
        for (auto& pair : adjList) {
            if (!visited[pair.first]) {
                if (dfs(pair.first, visited, recStack))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    Graph g;

    // Create a graph with edges
    g.addEdge('A', 'B');
    g.addEdge('B', 'C');
    g.addEdge('C', 'A'); // This creates a cycle: A -> B -> C -> A

    if (g.detectCycle())
        cout << "Cycle detected!" << endl;
    else
        cout << "No cycle detected." << endl;

    return 0;
}
