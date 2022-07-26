class Solution {
public:
    bool ancestor = false;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //if found either p or q, no need to check further as we found ancestor
        if (!root || root == p || root == q) 
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(!left) return right;
        if(!right) return left;
        return root;
    }
};