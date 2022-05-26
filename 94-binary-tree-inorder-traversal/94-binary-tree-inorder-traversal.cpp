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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        
        // Solution 1 - Recursive
        // traverse_recursive(root, res); //uncomment to use
        
        // Solution 2 - Iterative using Stack
        stack<TreeNode*> st;
        while(root || !st.empty()) {
            
            //keep pushing all left nodes in the stack
            while(root) {
                st.push(root);
                root = root->left;
            }
            
            //add value if stack top in res and remove it from stack
            root = st.top();
            st.pop();
            res.push_back(root->val);

            //change root to right subtree root to traverse right subtree
            root = root->right;
            
        }
        return res;
    }
    
    //traversal function for solution 1
    void traverse_recursive(TreeNode* root, vector<int> &res) {
        if(!root)
            return;
        
        traverse_recursive(root->left, res);
        res.push_back(root->val);
        traverse_recursive(root->right, res);
    }
};