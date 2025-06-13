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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        deque<int> preorderQueue(preorder.begin(), preorder.end());
        return build(preorderQueue, inorder);        
    }

private:
    TreeNode* build(deque<int>& preorder, vector<int>& inorder) {
        if (!inorder.empty()) {
            int val = preorder.front();
            preorder.pop_front();
            auto it = find(inorder.begin(), inorder.end(), val);
            int idx = it - inorder.begin();

            TreeNode* root = new TreeNode(val);
            vector<int> leftInorder(inorder.begin(), inorder.begin() + idx);
            vector<int> rightInorder(inorder.begin() + idx + 1, inorder.end());

            root->left = build(preorder, leftInorder);
            root->right = build(preorder, rightInorder);

            return root;
        }

        return nullptr;
    }    
};