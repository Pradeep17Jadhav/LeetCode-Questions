class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        traverse(root, res);
        return res;
    }
    
    void traverse(TreeNode* root, vector<int> &res) {
        if(!root) return;
        traverse(root->left, res);
        traverse(root->right, res);
        res.push_back(root->val);
    }
};