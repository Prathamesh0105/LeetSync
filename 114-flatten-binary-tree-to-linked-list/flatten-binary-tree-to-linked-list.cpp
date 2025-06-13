/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* prev = nullptr;

public:
    void flatten(TreeNode* root) {
        if (!root) return;

        // Process right subtree first
        flatten(root->right);

        // Process left subtree
        flatten(root->left);

        // Set the current node's right to prev and left to null
        root->right = prev;
        root->left = nullptr;

        // Update prev to current node
        prev = root;
    }
};