class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>res(nums.size());
        int positive = 0;
        int negative = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            int cur = nums[i];
            if(cur < 0)
            {
                res[negative] = cur;
                negative += 2;
            }
            else if(cur > 0)
            {
                res[positive] = cur;
                positive += 2;
            }
        }
        return res;
    }
};