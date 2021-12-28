class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestSum, currSum;
        bestSum = currSum = nums[0];
        
        for(int i = 1; i < nums.size(); i++)
        {
            currSum = max(currSum +  nums[i], nums[i]);
            bestSum = max(currSum, bestSum);
        }
        return bestSum;
    }
};