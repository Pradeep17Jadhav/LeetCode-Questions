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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
    
    TreeNode* build(vector<int>&nums, int start, int end){
        if(start > end)
            return NULL;
        int maxIndex = start;
        for(int i = start + 1; i <= end; i++)
        {
            if(nums[i] > nums[maxIndex])
            {
                maxIndex = i;
            }
        }
        TreeNode* head = new TreeNode(nums[maxIndex]);
        head->left = build(nums, start, maxIndex - 1);
        head->right = build(nums, maxIndex + 1, end);
        return head;
    }
};