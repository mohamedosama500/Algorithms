#include <iostream>
#include <algorithm>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to calculate the height of the tree
int height(TreeNode* root, int& diameter) {
    if (root == NULL)
        return 0;

    // Recursive calls to calculate the height of left and right subtrees
    int leftHeight = height(root->left, diameter);
    int rightHeight = height(root->right, diameter);

    // Update the diameter if the path through the root is larger
    diameter = max(diameter, leftHeight + rightHeight);

    // Return the height of the tree rooted at the current node
    return max(leftHeight, rightHeight) + 1;
}

// Function to calculate the diameter of the binary tree
int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

int main() {
    // Create the binary tree: 
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Diameter of the binary tree: " << diameterOfBinaryTree(root) << endl;

    return 0;
}
