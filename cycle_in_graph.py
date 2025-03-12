class Graph:
    def __init__(self):
        self.adj_list = {}

    # Add edge to the graph
    def add_edge(self, u, v):
        if u not in self.adj_list:
            self.adj_list[u] = []
        self.adj_list[u].append(v)

    # Helper function for DFS traversal
    def dfs(self, node, visited, rec_stack):
        # Mark the current node as visited and add to the recursion stack
        visited[node] = True
        rec_stack[node] = True

        # Recur for all the vertices adjacent to this node
        for neighbor in self.adj_list.get(node, []):
            # If the neighbor is not visited, recurse on it
            if not visited.get(neighbor, False) and self.dfs(neighbor, visited, rec_stack):
                return True
            # If the neighbor is in the recursion stack, a cycle is detected
            elif rec_stack.get(neighbor, False):
                return True

        # Remove the vertex from recursion stack before returning
        rec_stack[node] = False
        return False

    # Function to detect cycle in the graph
    def detect_cycle(self):
        visited = {}
        rec_stack = {}

        # Check for cycle in every vertex
        for node in self.adj_list:
            if not visited.get(node, False):
                if self.dfs(node, visited, rec_stack):
                    return True
        return False

# Example usage
g = Graph()

g.add_edge('A', 'B')
g.add_edge('B', 'C')
g.add_edge('C', 'A')  # This creates a cycle: A -> B -> C -> A
# Example for disconnected graphs
g.add_edge('D', 'E')
g.add_edge('E', 'F')  # No cycle here

if g.detect_cycle():
    print("Cycle detected!")
else:
    print("No cycle detected.")
