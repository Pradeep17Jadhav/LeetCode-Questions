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
    int num;
    bool isUnivalTree(TreeNode* root) {
        num = root->val; //accd to constraints root should have at least one node with values 0-99;
        // return traverse(root);
        return traverseConcise(root);
    }
    //both solutions are same, but first is concise
    
    bool traverseConcise(TreeNode* &root) {
        if(!root) return true;
        return root->val == num && traverseConcise(root->left) && traverseConcise(root->right);
    }

    bool traverse(TreeNode* &root) {
        if(root->val != num)
            return false;
        
        if(root->left)
            if(!traverse(root->left)) return false;
    
        if(root->right)
            if(!traverse(root->right)) return false;
        
        return true;
    }
};