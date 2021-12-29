class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int minDiff, maxDiff;
        int n = nums.size();
        int res = nums[n - 1] - nums[0];
        
        for(int i = 0; i < n - 1; i++)
        {
            maxDiff = max(nums[n - 1] - k, nums[i] + k);
            minDiff = min(nums[0] + k, nums[i + 1] - k);
            res = min(res, maxDiff - minDiff);
        }
        return res;
    }
};