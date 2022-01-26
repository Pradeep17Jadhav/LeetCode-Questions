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
    bool isBalanced(TreeNode* root) {
        return depth(root) != -1;
    }
    //Note - top down approach can cost O(nlogn) complexity as we will have to check 
    //depth of all elements from top to bottom
    
    
    //bottom up approach - O(N)
    int depth(TreeNode* node)
    {
        if(!node) return 0;
        int left = depth(node->left);
        if(left == -1) return -1;
        int right = depth(node->right);
        if(right == -1) return -1;
        
        if(abs(left - right) > 1)
            return -1;
        return max(left, right) + 1;
    }
};