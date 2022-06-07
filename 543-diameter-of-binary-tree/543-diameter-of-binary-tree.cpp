class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        findPath(root, res);
        return res - 1;
    }
    
    int findPath(TreeNode* root, int &res) {
        if(!root)
            return 0;
        
        int maxLeft = findPath(root->left, res);
        int maxRight = findPath(root->right, res);
        int currMax = max(maxLeft, maxRight) + 1;
        res = max(res, maxLeft + maxRight + 1);
        
        return currMax;
    }
};