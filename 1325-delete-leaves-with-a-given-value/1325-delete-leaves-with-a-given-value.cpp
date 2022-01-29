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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root->left)
            root->left = removeLeafNodes(root->left, target);
        
        if(root->right)
            root->right = removeLeafNodes(root->right, target);
        
        return (root->left == root->right and root->val == target) ? NULL : root;
        // (root->left == root->right) is a shortcut to say if (r->left == nullptr && r->right == nullptr).
        // In other words, the only time when r->left == r->right is when both are null.
    }

};