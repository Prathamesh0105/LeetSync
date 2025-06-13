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
    int getHeight(TreeNode * root){
        if(root == nullptr)
            return 0;
        int left_height = getHeight(root->left);
        if(left_height==-1) 
            return -1;
        int right_height = getHeight(root->right);
        if(right_height == -1)
            return -1;
        if(abs(right_height - left_height)>1)
            return -1;
        return max(right_height,left_height)+1;
    }
    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }
};