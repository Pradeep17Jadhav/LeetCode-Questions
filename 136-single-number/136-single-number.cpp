class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return method1(nums);
        // return method2(nums);
    }
        
    //TC: O(n) using XOR
    int method1(vector<int>& nums)
    {
        int res = 0;
        for(int &i: nums)
            res ^= i; //xor will cancel out the same numbers
        return res;
    }

    //TC: O(nlogn)
    int method2(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i+=2)
        {
            if(nums[i] != nums[i + 1])
                return nums[i];
        }
        return nums[nums.size() - 1];
    }
};