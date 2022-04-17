class Solution {
public:
    //Advance question of 53. Maximum Subarray
    //Case 1 - Kadane's algorithm can be directly used of answer subarray is in middle of the 'nums' array
    //Case 2 - The maximum subarray can be part of tail of the array + start of the array
    //To handle case 2, we find the minimum subarray, total sum of the whole array
    //So the answer will be - total sum - sum of minimum subarray
    //Return the maximum of both the cases

    int maxSubarraySumCircular(vector<int>& nums) {
        int currMin, currMax, minSum, maxSum;
        currMin = currMax = 0;
        minSum = maxSum = nums[0]; //cannot initialize with zero as the 0th index can be negative, so maxSum will become 0 in the loop
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            currMax = max(currMax + nums[i], nums[i]);
            maxSum = max(currMax, maxSum);
            
            currMin = min(currMin + nums[i], nums[i]);
            minSum = min(currMin, minSum);
            
            sum += nums[i];
        }
            
        //Corner case - all the numbers are negative
        //here the maxSum will always be the single element having maximum value
        //the 'sum - minSum' will always be 0, which is incorrect answer, so here we return the maxSum
        return maxSum > 0 ? max(maxSum, sum - minSum) : maxSum;
    }
};