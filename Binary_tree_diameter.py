class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# Function to calculate the height of the tree
def height(root, diameter):
    if root is None:
        return 0
    
    # Recursive calls to calculate the height of left and right subtrees
    left_height = height(root.left, diameter)
    right_height = height(root.right, diameter)
    
    # Update the diameter if the path through the root is larger
    diameter[0] = max(diameter[0], left_height + right_height)
    
    # Return the height of the tree rooted at the current node
    return max(left_height, right_height) + 1

# Function to calculate the diameter of the binary tree
def diameter_of_binary_tree(root):
    diameter = [0]
    height(root, diameter)
    return diameter[0]

# Example usage:
# Create the binary tree:
#       1
#      / \
#     2   3
#    / \
#   4   5
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)

print("Diameter of the binary tree:", diameter_of_binary_tree(root))
