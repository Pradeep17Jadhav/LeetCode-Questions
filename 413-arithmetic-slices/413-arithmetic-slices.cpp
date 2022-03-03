class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int res = 0;
        int i = 1; // start left from index 0
        int j = 2; // start right from index 0
        while(j < nums.size())
        {
            if(nums[i] - nums[i - 1] != nums[j] - nums[j - 1])
                i = j;
            res += j - i;
            
            j++;
        }
        return res;
    }
};

//[0,1,2,3,4,6,7,8,9]
