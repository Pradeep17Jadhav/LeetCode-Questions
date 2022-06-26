class Solution {
public:
    int rob(vector<int>& nums) {
        return rob_1(nums);
        // return rob_2(nums);
    }
    
    //TC: O(N)
    //SC: O(1)
    int rob_1(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int prev2 = nums[0];
        int prev = max(nums[0], nums[1]);
        int curr;
        
        for(int i = 2; i < nums.size(); i++) {
            curr = prev2 + nums[i];
            prev2 = prev;
            prev = max(curr, prev);
        }
        return prev;
    }
    
    //Dynamic Programming (Tabulation)
    //TC: O(N)
    //SC: O(N)
    int rob_2(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]); //to handles cases like [2,1,1,2]
        
        for(int i = 2; i < n; i++)
        {
            //since we need to skip adjecent houses, we can select either:
            //1 - current house + total robbed money at (current-2)th house
            //2 - skip current house and select total gains at (current - 1)th house 
            //We select maximum money robbed out of these two
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }
        
        return max(dp[n-1], dp[n-2]);
    }
};