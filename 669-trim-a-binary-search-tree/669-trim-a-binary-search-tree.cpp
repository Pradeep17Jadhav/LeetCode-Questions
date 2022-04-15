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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) return NULL;

        //do not consider the subtrees which are out of the required range (all elements will be smaller)
        //if curr root val is less than low of the range, then its left subtree is not required. 
        //but it may happen that right subtree has elements which are in the given range. 
        //Similarly if curr root val is greater than high of the range, then its right subtree is not reqired (all elements will be greater).
        //Again, left subtree may contain elements which lies within the required range. 
        //Since current node is out of range, we will just return the whole child subtree, skipping the current node.
        if(root->val > high)
            return trimBST(root->left, low, high);
        if(root->val < low)
            return trimBST(root->right, low, high);
        
        
        //if the current node is within the range, we will just update all the child subtrees.
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        
        return root;
    }
};