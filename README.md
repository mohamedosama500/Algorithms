# Algorithms

-> Breadth first search:

	- BFS uses a queue to explore nodes level by level. It processes each node, then enqueues all its neighbors,
		ensuring that nodes at the same level are visited before moving to the next level.
		
		
-> Depth first search:


	- DFS uses recursion to explore as deep as possible first. The function keeps calling itself for unvisited neighbors.


-> Cycles in a Graph [DFS with Recursion Stack]:


	- Keep track of visited vertices.
	- Keep a stack of vertices that are currently in the recursion.
	- If you encounter a vertex that is already in the recursion stack, a cycle is detected.


-> Binary tree diameter:


	- The diameter of a binary tree is the longest path between any two nodes in the tree. It is measured in terms of the number of edges along the path.
