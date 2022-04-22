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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        
        stack<vector<TreeNode*>> st;
        st.push({root});

        vector<TreeNode*> currLevel;
        vector<TreeNode*> nextLevel;
        while(true) {
            nextLevel.clear();
            currLevel = st.top();

            for(auto &root: currLevel) {
                if(root->left) nextLevel.push_back(root->left);
                if(root->right) nextLevel.push_back(root->right);
            }
            if(nextLevel.size())
                st.push(nextLevel);
            else
                break;
        }
        
        while(st.size()) {
            vector<int> temp;
            currLevel = st.top();
            st.pop();
            
            for(auto &node: currLevel)
                temp.push_back(node->val);
            res.push_back(temp);            
        }
        return res;

    }
};