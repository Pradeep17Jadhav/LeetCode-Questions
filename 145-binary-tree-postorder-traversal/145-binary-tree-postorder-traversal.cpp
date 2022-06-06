class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        // traverse(root, res); //uncomment to use
        
        vector<TreeNode*> st;
        TreeNode* last = NULL;
        while(root || !st.empty()) {
            if(root) {
                st.push_back(root);
                root = root->left;
            }
            else {
                TreeNode* node = st.back();
                if (node->right && last != node->right) {
                    root = node->right;
                } else {
                    res.push_back(node->val);
                    last = node;
                    st.pop_back();
                }
            }
            
        }
        return res;
    }
    
    void traverse(TreeNode* root, vector<int> &res) {
        if(!root) return;
        traverse(root->left, res);
        traverse(root->right, res);
        res.push_back(root->val);
    }
};