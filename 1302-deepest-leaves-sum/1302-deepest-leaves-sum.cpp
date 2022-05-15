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
    int maxDepth = 0;
    int deepestLeavesSum(TreeNode* root) {
        findSum(root, 1);
        return sum;
    }

    void findSum(TreeNode* node, int currDepth)
    {
        if(!node)
            return;
        
        if(currDepth > maxDepth)
        {
            maxDepth = currDepth;
            sum = 0;
        }

        if(currDepth == maxDepth)
            sum += node->val;

        findSum(node->left, currDepth + 1);
        findSum(node->right, currDepth + 1);
    }
};