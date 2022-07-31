class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        return memoization(coins, dp, coins.size()-1, amount);
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