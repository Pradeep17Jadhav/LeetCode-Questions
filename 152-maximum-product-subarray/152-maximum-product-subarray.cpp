class Solution {
public:
    
    //This problem can easily be solved using Kadane's algorithm if constrain is "0 <= nums[i] <= 10"
    //But in this problem there can be multiple negative numbers so we cannot use Kadane's algo directly
    //Reason - Example - [-2,-3,-9]
    //Here, multiplication of -2 and -3 is positive (6) and greater than 2nd index so kadane's algo will give 6 as ans
    //But, (-3 * -9) = 27, which is greater than 6.
    //So we can conclude that, even if prod of two nums is less than current number, it can become huge if multiplied with another -ve no.
    
    //To handle negative nos, we will maintain a minimum product of two nos as 'currMin'.
    //Each time while checking for currMax, we will use maximum value betn (currNum, currNum * currMin, currNum * currMax)
    
    int maxProduct(vector<int>& nums) {
        int currMax, currMin, newMax, res, currNum;
        currMax = currMin = newMax = res = nums[0];
        
        for(int i = 1; i < nums.size(); i++)
        {
            currNum = nums[i];
            newMax = max(currNum, max(currNum * currMax, currNum * currMin));
            currMin = min(currNum, min(currNum * currMax, currNum * currMin));
            currMax = newMax;
            res = max(currMax, res);
        }
                
        return res;
    }
};
