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
    int res = -1;
    int count = 0;
    int kthSmallest(TreeNode* root, int k) {
        count = k;
        traverse(root, k);
        return res;
    }
    void traverse(TreeNode* root, int k)
    {
        if(root->left)
            traverse(root->left, k);

        count--;
        if(!count)
        {
            res = root->val;
            return;
        }
        
        if(root->right)
            traverse(root->right, k);
    }
};