class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return depth(root) != -1;
    }
    //Note - top down approach can cost O(nlogn) complexity as we will have to check 
    //depth of all elements from top to bottom
    
    
    //bottom up approach - O(N)
    //use -1 as false. if -1 is returned no need to check further, just keep returning -1
    int depth(TreeNode* node)
    {
        if(!node) 
            return 0; //use 0 to add
        
        int left = depth(node->left);
        if(left == -1) 
            return -1;
        
        int right = depth(node->right);
        if(right == -1) 
            return -1;
        
        if(abs(left - right) > 1)
            return -1;

        return max(left, right) + 1;
    }
};