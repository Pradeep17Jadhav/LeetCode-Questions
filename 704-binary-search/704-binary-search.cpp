class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binary(nums, target, 0, nums.size()-1);
    }
    
    int binary(vector<int> nums, int target, int left, int right)
    {
        if(left > right) return -1;
        int mid = (right + left) / 2;
        if(nums[mid] == target) return mid;
        return  target < nums[mid]  ? binary(nums, target, left, mid-1) : binary(nums, target, mid+1, right);
    }
};