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
    int maxSum = INT_MIN;

    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxSum;
    }

private:
    int helper(TreeNode* node) {
        if (!node) return 0;

        int leftMaxPath = max(helper(node->left), 0);
        int rightMaxPath = max(helper(node->right), 0);

        int maxIfNodeIsRoot = node->val + leftMaxPath + rightMaxPath;
        maxSum = max(maxSum, maxIfNodeIsRoot);

        return node->val + max(leftMaxPath, rightMaxPath);
    }
};