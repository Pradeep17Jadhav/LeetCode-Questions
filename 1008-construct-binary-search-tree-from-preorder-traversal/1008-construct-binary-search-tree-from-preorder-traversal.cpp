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
    int i = 0;
    TreeNode* bstFromPreorder(vector<int>& preorder, int max = INT_MAX) {
        //max is the maximum value till which a tree node can have value
        if(i == preorder.size() || preorder[i] > max)
            return NULL;
        TreeNode* root = new TreeNode(preorder[i++]); //give current value to a node
        root->left = bstFromPreorder(preorder, root->val); //use current value as max for left subtree
        root->right = bstFromPreorder(preorder, max); //use current max as max for right subtree
        return root;
    }
};