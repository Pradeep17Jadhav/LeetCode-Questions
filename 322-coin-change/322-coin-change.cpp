class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        int res = memoization(coins, dp, n-1, amount);
        return res == 1e9 ? -1 : res;
        // return solution1(coins, amount);
    }
    
    int memoization(vector<int>& coins, vector<vector<int>> &dp, int index, int amount) {
        if(amount == 0)
            return 0;
        if(index == 0)
        {
            if(amount % coins[0] == 0)
                return amount / coins[0];
            return 1e9;
        }
        if(dp[index][amount] != -1)
            return dp[index][amount];
            
        int notTake = memoization(coins, dp, index-1, amount);
        int take = 1e9;
        if(coins[index] <= amount)
            take = memoization(coins, dp, index, amount-coins[index]) + 1;
        
        return dp[index][amount] = min(notTake, take);
    }

    int solution1(vector<int>& coins, int amount) {
        amount++; //extra block for 0th index as 0
        vector<int> dp(amount, INT_MAX);
        dp[0] = 0;
        sort(coins.begin(), coins.end());
        for(int i = 1; i < amount; i++) {
            // setting dp[0] base value to 1, 0 for all the rest
            for(int coinVal: coins) {
                if(i - coinVal < 0) 
                    break;

                // if it was a previously not reached cell, we do not add use it
                if(dp[i - coinVal] != INT_MAX) 
                    dp[i] = min(dp[i], 1 + dp[i - coinVal]);
            }
        }
        return dp[--amount] == INT_MAX ? -1 : dp[amount];
    }
};