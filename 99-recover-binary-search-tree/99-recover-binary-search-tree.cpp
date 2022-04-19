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
    TreeNode* prev = NULL;
    TreeNode* first; //store first violation
    TreeNode* mid; //store node next to the first violation (in ascd order)
    TreeNode* last; //store last violation
    int bDone = false;
    

    //Reference to this solution - https://www.youtube.com/watch?v=ZWGW7FminDM
    
    //TC: O(N)
    //SC: O(1) if recursion stack is not considered.
    //IMP - Implement Morris Traversal for O(1) space complexity
    void recoverTree(TreeNode* root) {
        first = mid = last = NULL;

        inorder(root); 
        if(!bDone) //if both violations are not found, the values to be swapped are adjucent values (first and mid)
            swap(first->val, mid->val);
    }
    
    //Traverse the tree inorder so that all the elements should be in ascending order
    //But as two nodes are swapped, there will be some nodes where the value is less than the value of previous node
    //Here the previous node should not be greater than the current node. So we mark it (prev node) as first violation
    //There can be a case where we dont find second violation. For this case the swap nodes are adjacent.
    //So we store the current node as mid node. Then continue traverse and if we dont find second violation then we just swap first and mid.
    //If we find 2nd violation, immediately swap roots value with first violation node
    void inorder(TreeNode* root) {
        if(!root)
            return;
            
        inorder(root->left);
        
        if(prev && root->val < prev->val)
        {
            if(!first) {
                first = prev;
                mid = root;
            }
            else {
                swap(first->val, root->val);
                bDone = true; //mark that swapping is already done when both violations are found
                return;
            }
        }
        
        prev = root;
        inorder(root->right);
    }
};