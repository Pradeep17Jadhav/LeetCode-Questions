class Solution {
public:
    int missingNumber(vector<int>& nums) {
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