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
    int pre = 0;
    TreeNode* bstToGst(TreeNode* root) {
        // Soltion 1
        // findSum(root, 0);
        // return root;
    
        
        //Solution 2
        if(root->right)
            bstToGst(root->right);
        
        pre = pre + root->val;
        root->val = pre;
        
        if(root->left)
            bstToGst(root->left);
        
        return root;
    }
    
    int findSum(TreeNode* root, int rightSum)
    {
        //if leaf node, add prev sum in value of node and return
        if(!root->left && !root->right)
        {
            root->val += rightSum;
            return root->val;
        }

        if(root->right) //if right node exists, curr val should be (sum of vals of nodes on right + curr value)
            root->val += findSum(root->right, rightSum); 
        else //if right node doesnt exist, curr val should be prev sum + curr value
            root->val += rightSum;

        if(root->left) // left subtree has nodes with value greater than value of parent node
            return findSum(root->left, root->val);
        else //if there is node left subtree, the current node has value greater than parent node
            return root->val;
    }
};