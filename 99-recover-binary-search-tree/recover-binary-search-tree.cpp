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
public:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void recoverTree(TreeNode* root) {
        inorderTraversal(root);
        swap(first->val, second->val);
    }

    void inorderTraversal(TreeNode* root) {
        if (!root) return;
        
        inorderTraversal(root->left);

        if (prev && root->val < prev->val) {
            if (!first) first = prev;
            second = root;
        }
        prev = root;

        inorderTraversal(root->right);
    }
};