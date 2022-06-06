class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        // Solution 1 - Recursive
        // traverse_recursive(root, res); //uncomment to use
        
        // Solution 2 - Iterative using Stack
        stack<TreeNode*> st;
        while(!st.empty() || root) {
            while(root) {
                res.push_back(root->val);
                st.push(root);
                root = root->left;
            }
            
            root = st.top();
            st.pop();
            root = root->right;
        }
        return res;
    }
    
    // Traversal function for Solution 1 (Recursive)
    void traverse_recursive(TreeNode* root, vector<int> &res) {
        if(!root)
            return;
        
        res.push_back(root->val);
        traverse_recursive(root->left, res);
        traverse_recursive(root->right, res);
    }
};