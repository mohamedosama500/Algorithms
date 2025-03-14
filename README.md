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



-> Algorithm to Find the In-Order Successor

	- If the node has a right subtree, the successor is the leftmost node in the right subtree.
	- If the node has no right subtree, the successor is the lowest ancestor for which the given node is in its left subtree.

	- Using In-Order Traversal in a Binary Search Tree (BST)
		Left Subtree → Root → Right Subtree
		This means:

			First, visit the left subtree.
			Then, visit the root node.
			Finally, visit the right subtree.