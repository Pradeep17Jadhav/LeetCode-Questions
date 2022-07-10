class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // return minCostClimbingStairs_1(cost);
        // return minCostClimbingStairs_2(cost);
        
        vector<int>dp(cost.size()+1, -1);
        return memoization(cost, dp, cost.size());
    }
    
    int memoization(vector<int>cost, vector<int>&dp, int index) {
        if(index < 0)
            return 1e9;
        if(index == 0 || index == 1)
            return cost[index];
        if(dp[index] != -1)
            return dp[index];

        int oneStep = memoization(cost, dp, index-1);
        int twoSteps = memoization(cost, dp, index-2);
        int currCost = index == cost.size() ? 0 : cost[index];
        return dp[index] = (min(oneStep, twoSteps) + currCost);
    }
    
    //DP
    //TC: O(N)
    //SC: O(N)
    int minCostClimbingStairs_1(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n);
        memo[0] = cost[0];
        memo[1] = cost[1];

        for(int i = 2; i < n; i++)
            memo[i] = cost[i] + min(memo[i-1], memo[i-2]);

        return min(memo[n-1], memo[n-2]);
    }

    //TC: O(N)
    //SC: O(1)
    int minCostClimbingStairs_2(vector<int>& cost) {
        int a = cost[0];
        int b = cost[1];
        int c;
        int n = cost.size();
        
        for(int i = 2; i < n; i++) {
            c = cost[i] + min(a, b);
            a = b;
            b = c;
        }
        
        return min(a, b);
    }
};