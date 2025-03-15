
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* prevNode = NULL;
//
bool isValidBST(TreeNode* root) {
    // Empty tree is always a valid BST
    if (!root) return true;
    // Recursively check the left subtree
    if (!isValidBST(root->left))
        return false;
    // if prevNode is NULL, trying to access prevNode->val would cause a segmentation fault (crash).
    if (prevNode && prevNode->val >= root->val)
        return false;
    // Update the previous node to the current node
    prevNode = root;
    // Recursively check the right subtree
    return isValidBST(root->right);
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    cout << (isValidBST(root) ? "Valid BST" : "Invalid BST") << endl;

    return 0;
}




