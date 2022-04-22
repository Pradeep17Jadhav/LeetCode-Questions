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
        
        stack<vector<TreeNode*>> st; //store vector of treenodes at each level in a stack
        st.push({root}); //store first level

        vector<TreeNode*> currLevel;
        vector<TreeNode*> nextLevel;
        while(true) {
            nextLevel.clear();
            currLevel = st.top(); //use top vector from stack

            //add childs of all nodes at the current level in the vector
            for(auto &node: currLevel) {
                if(node->left) nextLevel.push_back(node->left);
                if(node->right) nextLevel.push_back(node->right);
            }
            
            //if there are nodes in the next level, push the array to the stack, else break as we have reached last level
            if(nextLevel.size())
                st.push(nextLevel);
            else
                break;
        }
        
        //pop each level from stack, add their node values to the vector and append all such vectors to result vector
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