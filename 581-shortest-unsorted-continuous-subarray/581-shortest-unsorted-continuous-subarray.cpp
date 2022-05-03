class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = nums.size() - 1;
        int end = -1;
        int temp = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if(nums[i] < nums[i-1])
            {
                int j = i-1;
                while(j >= 0 && nums[j] > nums[i])
                    j--;
                start = min(start, j+1);
            }
        }

        for (int i = nums.size() - 1; i > 0; i--)
        {
            if(nums[i] < nums[i-1])
            {
                int j = i;
                while(j < nums.size() && nums[j] < nums[i-1])
                    j++;
                end = max(end, j-1);
                
            }
        }
        if(start == nums.size() - 1 && end == -1)
            return 0;
        return end - start + 1;
    }
};