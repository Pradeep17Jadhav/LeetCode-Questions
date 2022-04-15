class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        
        vector<int> memo(n);
        memo[0] = nums[0];
        memo[1] = max(nums[0], nums[1]); //to handles cases like [2,1,1,2]
        
        for(int i = 2; i < n; i++)
        {
            //since we need to skip adjecent houses, we can select either:
            //1 - current house + total robbed money at (current-2)th house
            //2 - skip current house and select total gains at (current - 1)th house 
            //We select maximum money robbed out of these two
            memo[i] = max(memo[i-1], nums[i] + memo[i-2]);
        }
        
        return max(memo[n-1], memo[n-2]);
    }
};