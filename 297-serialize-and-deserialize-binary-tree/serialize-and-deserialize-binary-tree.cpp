/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:    
    TreeNode* solu(queue<string> & qu){
        string val=qu.front();
        qu.pop();
        if(val=="null"){
            return NULL;
        }
        TreeNode* Nroot=new TreeNode(stoi(val));
        Nroot->left=solu(qu);
        Nroot->right=solu(qu);
        return Nroot;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL){
            return "null";
        }
        string left=serialize(root->left);
        string right=serialize(root->right);
        return to_string(root->val)+","+left+","+right;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string token;
        queue<string> qu;
        while(getline(ss, token, ',')){
            qu.push(token);
        }
        return solu(qu);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));