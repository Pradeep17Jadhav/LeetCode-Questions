class Solution {
public:
    int missingNumber(vector<int>& nums) {
        return method1(nums);
        // return method2(nums);
    }
    
    //since a^b^b = a,
    //we can use xor to find missing number
    int method1(vector<int>& nums)
    {
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