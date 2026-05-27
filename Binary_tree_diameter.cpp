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


/*
Function to calculate the height of the tree.
The recursion goes all the way down to the leaf nodes.
Their children are NULL, so they return a height of 0 for this childern.
The & means diameter is passed by reference. Any changes made to it inside the recursive calls
Are saved globally across the entire tree exploration.
*/
int height(TreeNode* root, int& diameter) {
    if (root == NULL)
        return 0;

    /* Recursive calls to calculate the height of the left and right subtrees.
       Traverses down to the leaf nodes, then bubbles back up to the parent nodes 
       as the recursive calls resolve.
       1. Root starts ───> Paused at leftHeight
       2.   Left Child ───> Paused at leftHeight
       3.     Leaf Node ───> Paused at leftHeight
       4.       NULL reached! Returns 0.
    */
    int leftHeight = height(root->left, diameter);
    int rightHeight = height(root->right, diameter);

    // Update the diameter if the path through the root is larger
    diameter = max(diameter, leftHeight + rightHeight);

    // Return the height of the tree rooted at the current node
    // Once the leaf node finishes its last line (e.g. return max(0,0) + 1), it dies
    // and returns 1 to its parent.
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
