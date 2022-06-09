class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return checkSymmetry(root->left, root->right);
    }
    
    bool checkSymmetry(TreeNode* left, TreeNode* right) {
        if(!left && !right)
            return true;
        
        if((left && !right) || (!left && right) || (left->val != right->val))
            return false;

        return checkSymmetry(left->left, right->right) && checkSymmetry(left->right, right->left);
    }
};