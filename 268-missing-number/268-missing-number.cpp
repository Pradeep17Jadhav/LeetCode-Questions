class Solution {
public:
    int missingNumber(vector<int>& nums) {
        return method1(nums);
        // return method2(nums);
    }
    
    // since a^b^b = a,
    // we can use xor to find missing number
    // property - a^a^b^b^c^c = (a^a)^(b^b)^(c^c) = 0^0^0 = 0
    // example -
    // nums = [0,1,3]
    // indices =[0,1,2,3]
    // So, we do (0^1^3) ^ (0^1^2^3) = (0^0)^(1^1)^(2)^(3^3) = 0^0^2^0 = 2
    int method1(vector<int>& nums)
    {
        //start with nums.size() because if nums=[0,1,3], in for loop we will only have [0,1,2] indices out of [0,1,2,3]
        //to compensate the missing last index (which is always nums.size()), we start the res with nums.size()
        int res = nums.size(); 
        for(int i = 0; i < nums.size(); i++)
        {
            res = res ^ i ^ nums[i];
        }
        return res;
    }

    int method2(vector<int>& nums) {
        int indexSum = 0;
        int valueSum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            indexSum += i + 1;
            valueSum += nums[i];
        }

        return indexSum - valueSum;
    }
};