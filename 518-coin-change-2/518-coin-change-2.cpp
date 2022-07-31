class Solution {
public:
    int change(int amount, vector<int>& coins) {
//         vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
//         return memoization(coins, dp, coins.size()-1, amount);
    
//         return tabulation(amount, coins);

        return tabulation_space_optimized(amount, coins);
    }
    
    int tabulation_space_optimized(int amount, vector<int>& coins) {
        vector<int> prev(amount+1, 0), curr(amount+1, 0);
        
        for(int j = 0; j <= amount; j++)
            prev[j] = j % coins[0] == 0;
        
        for(int ind = 1; ind < coins.size(); ind++) {
            for(int target = 0; target <= amount; target++) {
                int notTake = prev[target];
                int take = 0;
                if(coins[ind] <= target)
                    take = curr[target-coins[ind]];
                
                curr[target] = take + notTake;
            }
            prev = curr;
        }
        
        return prev[amount];
    }
    
    
    int tabulation(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, 0));
        
        for(int j = 0; j <= amount; j++)
            dp[0][j] = j % coins[0] == 0;
        
        for(int ind = 1; ind < coins.size(); ind++) {
            for(int target = 0; target <= amount; target++) {
                int notTake = dp[ind-1][target];
                int take = 0;
                if(coins[ind] <= target)
                    take = dp[ind][target-coins[ind]];
                
                dp[ind][target] = take + notTake;
            }
        }
        
        return dp[coins.size()-1][amount];
    }
    
    int memoization(vector<int> &coins, vector<vector<int>> &dp, int index, int amount) {
        if(index == 0)
           return amount % coins[0] == 0;
        if(dp[index][amount] != -1)
            return dp[index][amount];
    
        int notTake = memoization(coins, dp, index-1, amount);
        int take = 0;
        if(coins[index] <= amount)
            take = memoization(coins, dp, index, amount-coins[index]);
        
        return dp[index][amount] = take + notTake;
        
    }
};