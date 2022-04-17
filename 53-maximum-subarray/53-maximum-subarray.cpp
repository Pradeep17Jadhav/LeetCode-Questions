class Solution {
public:
    //Kadane's algo
    int maxSubArray(vector<int>& nums) {
        int currSum = nums[0], bestSum = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            currSum = max(currSum + nums[i], nums[i]);
            bestSum = max(currSum, bestSum);
        }
        
        return bestSum;
    }
};