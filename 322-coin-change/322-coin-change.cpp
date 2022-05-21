class Solution {
public:
    int coinChange(vector<int>& coins, int amout) {
        amout++; //extra block for 0th index as 0
        vector<int> dp(amout, INT_MAX);
        dp[0] = 0;
        sort(coins.begin(), coins.end());
        for(int i = 1; i < amout; i++) {
            // setting dp[0] base value to 1, 0 for all the rest
            for(int coinVal: coins) {
                if(i - coinVal < 0) 
                    break;

                // if it was a previously not reached cell, we do not add use it
                if(dp[i - coinVal] != INT_MAX) 
                    dp[i] = min(dp[i], 1 + dp[i - coinVal]);
            }
        }
        return dp[--amout] == INT_MAX ? -1 : dp[amout];
    }
};