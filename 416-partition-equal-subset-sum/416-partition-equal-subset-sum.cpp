class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for(int &i: nums) total += i; //count total sum of all elements
        if(total % 2 || n == 1) return false; //odd nums cannot be divided in two integer halves
        
        //if any subsequence have sum of half of the total, then remaining subsequence must have the remaining half of total 
        int target = total / 2;
        
        //Memoization
        // vector<vector<int>> dp(n, vector<int>(target+1, -1));
        // return memoization(nums, dp, target, n-1);
        
        //Tabulation
        return tabulation(nums, target);
    }
    
    bool memoization(vector<int> &arr, vector<vector<int>> &dp, int target, int index) {
        if(target == 0) return true;
        if(index == 0) return target == arr[index];
        if(dp[index][target] != -1) return dp[index][target];

        int notTake = memoization(arr, dp, target, index-1);
        if(notTake) return true;

        int take = false;
        if(arr[index] <= target)
            take = memoization(arr, dp, target-arr[index], index-1);

        return dp[index][target] = take;
    }

    bool tabulation(vector<int> &arr, int k) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(k+1, false));
        if(arr[0] <= k) dp[0][arr[0]] = true;
        for(int i = 0; i < arr.size(); i++)
            dp[i][0] = true;

        for(int index = 1; index < arr.size(); index++) {
            for(int target = 1; target <= k; target++) {
                int notTake = dp[index-1][target];

                int take = false;
                if(arr[index] <= target)
                    take = dp[index-1][target - arr[index]];

                dp[index][target] = notTake | take;
            }
        }

        return dp[n-1][k];
    }
};