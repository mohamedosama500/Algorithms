class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

prevNode = None

def isValidBST(root):
    global prevNode
    # Empty tree is always a valid BST
    if not root:
        return True
    # Recursively check the left subtree
    if not isValidBST(root.left):
        return False
    # Check if the previous node's value is greater than or equal to the current node's value
    if prevNode and prevNode.val >= root.val:
        return False
    # Update the previous node to the current node
    prevNode = root
    # Recursively check the right subtree
    return isValidBST(root.right)

if __name__ == "__main__":
    root = TreeNode(5)
    root.left = TreeNode(3)
    root.right = TreeNode(7)
    root.left.left = TreeNode(2)
    root.left.right = TreeNode(4)
    root.right.left = TreeNode(6)
    root.right.right = TreeNode(8)

    print("Valid BST" if isValidBST(root) else "Invalid BST")
