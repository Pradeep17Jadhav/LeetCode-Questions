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
    TreeNode* prev; //pointer to traverse the answer as a linked list. it is the last value of answer tree
    TreeNode* increasingBST(TreeNode* root) {
        if(!root)
            return NULL;
        
        TreeNode * dummy = new TreeNode(0);
        prev = dummy; //let reference to new root unchanged
        inorder(root); //pass the original root
        return dummy->right;
    }

    //we traverse all the nodes inorder
    //we keep on changing the 'prev' pointer inorder and attaching the next pointer 
    void inorder(TreeNode* root) {
        if(!root)
            return;
        
        inorder(root->left); 
        root->left = NULL; //mark the left of original root as null as left subtree is already handled
        prev->right = root; //make the root node as right of the prev pointer
        prev = root; //update the prev pointer (which moves in-order)
        inorder(root->right);
    }
};