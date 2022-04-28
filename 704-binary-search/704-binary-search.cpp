class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binary(nums, target);
        // return binary_recursive(nums, target, 0, nums.size()-1);
    }
    
    // TC: O(logn)
    // SC: O(1)
    int binary(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left <= right) 
        {
            int mid = (right + left) / 2;
            if(nums[mid] == target) return mid;
            if(target < nums[mid])
                right = mid-1;
            else
                left = mid+1;
        }
        return -1;

    }
    
    // TC: O(logn)
    // SC: O(N) for recursion
    int binary_recursive(vector<int> nums, int target, int left, int right)
    {
        if(left > right) return -1;
        int mid = (right + left) / 2;
        if(nums[mid] == target) return mid;
        return  target < nums[mid]  ? binary_recursive(nums, target, left, mid-1) : binary_recursive(nums, target, mid+1, right);
    }
};