class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size()-1);
    }
    
    TreeNode* dfs(vector<int> &nums, int left, int right) {
        if(left > right)
            return NULL;
        int mid = (left+right)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = dfs(nums, left, mid-1);
        node->right = dfs(nums, mid+1, right);
        return node;
    }
};