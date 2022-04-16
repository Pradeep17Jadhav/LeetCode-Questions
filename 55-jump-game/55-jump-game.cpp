class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size());
        int maxIndex = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            dp[i] = i + nums[i];
            
            if(maxIndex < i) 
                return false;
            maxIndex = max(maxIndex, dp[i]);
        }
        return true;
    }
};