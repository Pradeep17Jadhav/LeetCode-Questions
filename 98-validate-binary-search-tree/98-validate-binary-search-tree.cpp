class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTSubtree(root, NULL, NULL);
    }
    
    bool isValidBSTSubtree(TreeNode* root, TreeNode* min, TreeNode* max) {
        if(!root) //null subtree is valid for leaf nodes
            return true;
        
        //if min node is present, the value of all the subtree nodes shoud be greater than the value of min node
        //if max node is present, the value of all the subtree nodes shoud be less than the value of max node
        //if not, the subtree is invalid so returen false
        if((min && root->val <= min->val) || (max && root->val >= max->val))
            return false;
        
        //both the left and rightsubtree should also be valid
        return isValidBSTSubtree(root->left, min, root) && isValidBSTSubtree(root->right, root, max);
    }
};