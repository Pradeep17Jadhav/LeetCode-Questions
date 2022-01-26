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
    int sum = 0;
    int sumEvenGrandparent(TreeNode* root) {
        find(root, 0, 0);
        return sum;
    }
    
    void find(TreeNode* root, int gp, int p)
    {
        if(!root) return;
        
        if(gp and !(gp % 2))
            sum += root->val;
        
        find(root->left, p, root->val);
        find(root->right, p, root->val);
    }
};