class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return checkSymmetry(root->left, root->right);
    }
    
    bool checkSymmetry(TreeNode* left, TreeNode* right) {
        if(!left && !right) //if both ptrs not available, its still symmetric
            return true;
        
        //if either of pointer is null, or values are not equal, it is not symmetric
        if((left && !right) || (!left && right) || (left->val != right->val))
            return false;

        return checkSymmetry(left->left, right->right) && checkSymmetry(left->right, right->left);
    }
};