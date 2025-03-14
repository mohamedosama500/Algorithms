#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    // Constructor to initialize the node with given value
    TreeNode(int x) {
        val = x;
        left = right = NULL; // Initialize left and right children as NULL
    }
};

// Function to insert a new node in the Binary Search Tree (BST)
TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) {
        // If the tree is empty, create a new node and return it as root
        return new TreeNode(val);
    }
    
    if (val < root->val) {
        // If the value is smaller than the current node's value,
        // recursively insert it into the left subtree,When the left child is NULL, we create a new node and return it, assigning it to root->left.
        root->left = insert(root->left, val);
    }
    else if (val > root->val) {
        // If the value is greater than the current node's value,
        // recursively insert it into the right subtree, When root->right is NULL, we create a new node and assign it to root->right.
        root->right = insert(root->right, val);
    }
    return root; // Return the (potentially updated) root node
}

// Function to find the leftmost node (smallest node) in a subtree
TreeNode* findMin(TreeNode* node) {
    while (node->left != NULL) {
        // Keep moving left until the leftmost node is found
        node = node->left;
    }
    return node; // Return the leftmost node (smallest value in the subtree)
}

// Function to find the in-order successor of a given node in BST
TreeNode* findSuccessor(TreeNode* root, TreeNode* node) {
    // Case 1: If the node has a right subtree, the successor is the leftmost node in that subtree
    if (node->right != NULL) {
        return findMin(node->right); // Find and return the minimum node in the right subtree
    }

    // Case 2: If the node has no right subtree, find the nearest ancestor
    // where the node is in the left subtree of that ancestor
    TreeNode* successor = NULL; // Initialize successor as NULL
    TreeNode* current = root;   // Start the search from the root

    while (current != NULL) {
        if (node->val < current->val) {
            // If the target node's value is smaller than the current node's value,
            // then the current node is a possible successor
            successor = current;
            current = current->left; // Move left to check for a closer successor
        }
        else if (node->val > current->val) {
            // If the target node's value is greater than the current node's value,
            // move right to continue searching
            current = current->right;
        }
        else {
            // Found the target node, exit the loop
            break;
        }
    }
    return successor; // Return the found successor (or NULL if no successor exists)
}

// Main function to test the in-order successor function
int main() {
    TreeNode* root = NULL;
    
    // Constructing the BST by inserting nodes
    root = insert(root, 20); // Root node
    root = insert(root, 10); // Left child of 20
    root = insert(root, 30); // Right child of 20
    root = insert(root, 5);  // Left child of 10
    root = insert(root, 15); // Right child of 10
    root = insert(root, 25); // Left child of 30
    root = insert(root, 35); // Right child of 30

    // Select the target node whose successor we want to find
    TreeNode* target = root->left->right; // target = node with value 15, Node 15 for example, you can change it to start from anynode like [ TreeNode* target = root->left]
    
    // Find the in-order successor of the target node
    TreeNode* successor = findSuccessor(root, target);

    // Print the result
    if (successor != NULL)
        std::cout << "In-order Successor of " << target->val << " is " << successor->val << std::endl;
    else
        std::cout << "No successor found" << std::endl;
    
    return 0; // Exit the program
}


    