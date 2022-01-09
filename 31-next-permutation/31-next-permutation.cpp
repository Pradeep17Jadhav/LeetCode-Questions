class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int breakdown = -1;
        for(int i = nums.size() - 1; i > 0; i--)
        {
            if(nums[i - 1] < nums[i])
            {
                breakdown = i - 1;
                break;
            }
        }
        if(breakdown == -1)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            for(int i = nums.size() - 1; i >= 0; i--)
            {
                if(nums[i] > nums[breakdown])
                {
                    swap(nums[i], nums[breakdown]);
                    reverse(nums.begin() + breakdown + 1, nums.end());
                    break;
                }
            }
        }
    }
};