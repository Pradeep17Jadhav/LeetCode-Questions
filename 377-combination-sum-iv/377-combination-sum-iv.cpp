class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return memoization(nums, dp, target);
    }
    
    int memoization(vector<int> &nums, vector<int> &dp, int target) {
        if(target == 0)
            return 1;

        if(dp[target] != -1)
            return dp[target];

        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= target)
                count += memoization(nums, dp, target-nums[i]);
            
        }
        
        return dp[target] = count;
            
    }
};