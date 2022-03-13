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
    long min = LONG_MAX;
    long secMin = LONG_MAX;
    int findSecondMinimumValue(TreeNode* root) {
        traverse(root);
        return secMin == LONG_MAX ? -1 : secMin;
    }
    
    void traverse(TreeNode* root)
    {
        if(root->right)
            traverse(root->right);
        
        if(root->left)
            traverse(root->left);
        
        if(root->val < min)
        {
            secMin = min;
            min = root->val;
        }
        else if(root->val > min && root->val < secMin)
            secMin = root->val;
    }
};