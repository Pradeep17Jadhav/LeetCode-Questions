class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, -1));
        return memoization(nums, dp, 0, -1);
        // return tabulation(nums);
    }

//     int tabulation(vector<int>& nums) {
//         vector<unordered_map<int, int>> dp(nums.size()+1, unordered_map<int, int>());

//     }
    
    int memoization(vector<int> &nums, vector<vector<int>> &dp, int index, int prevIndex) {
        if(index == nums.size())
            return 0;

        if(dp[index][prevIndex+1] != -1)
            return dp[index][prevIndex+1];

        int notTake = memoization(nums, dp, index+1, prevIndex);
        int take = 0;
        if(prevIndex == -1 || nums[index] > nums[prevIndex])
            take = 1 + memoization(nums, dp, index+1, index);

        return dp[index][prevIndex+1] = max(notTake, take);
    }
};