import sys

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def insert(root, val):
    """Inserts a value into the BST and returns the root node."""
    if not root:
        print(f"Inserting {val} as a new root node.")
        return TreeNode(val)
    
    if val < root.val:
        print(f"Inserting {val} to the left of {root.val}")
        root.left = insert(root.left, val)
    else:
        print(f"Inserting {val} to the right of {root.val}")
        root.right = insert(root.right, val)
    
    return root

def find_min(node):
    """Finds the leftmost node in a BST (i.e., node with the smallest value)."""
    print(f"Finding min value starting at node: {node.val}")
    while node.left:
        node = node.left
        print(f"Moving left to node with value: {node.val}")
    return node

def find_successor(root, node):
    """Finds the in-order successor of a given node in BST."""
    if node.right:
        print(f"Node {node.val} has a right subtree. Finding min in right subtree...")
        return find_min(node.right)  # Case 1: Successor is the minimum node in the right subtree
    
    successor = None
    current = root  # Start the search from the root
    
    while current:
        print(f"Checking node {current.val} for successor of {node.val}")
        if node.val < current.val:
            successor = current  # Possible successor, but keep searching in the left subtree
            print(f"Updated potential successor to {successor.val}")
            current = current.left
        elif node.val > current.val:
            current = current.right  # Look on the right side of the current node
        else:
            break  # Found the node, return successor
    if successor:
        print(f"Successor of {node.val} found: {successor.val}")
    else:
        print(f"No in-order successor found for {node.val}")
    return successor

def inorder_traversal(root):
    """Helper function to print inorder traversal of the tree."""
    if root:
        inorder_traversal(root.left)
        print(f"{root.val} ", end=" ")
        inorder_traversal(root.right)

# Construct BST and insert nodes
root = None
root = insert(root, 20) # Root node
root = insert(root, 10) # Left child of 20
root = insert(root, 30) # Right child of 20
root = insert(root, 5)  # Left child of 10
root = insert(root, 15) # Right child of 10
root = insert(root, 25) # Left child of 30
root = insert(root, 35) # Right child of 30

# Perform in-order traversal
print("Inorder Traversal of BST:")
inorder_traversal(root)
print()

# Find in-order successor of 15
target = root.left.right  # Node with value 15
print(f"Finding in-order successor of node with value: {target.val}")
successor = findSuccessor(root, target)

if successor:
    print(f"In-order Successor of {target.val} is {successor.val}")
else:
    print(f"{target.val} has no in-order successor")