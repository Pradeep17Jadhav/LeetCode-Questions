class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int i = 0, j = nums.size() - 1, res = 0, total;
        sort(nums.begin(), nums.end());
        while(i < j)
        {
            total = nums[i] + nums[j];
            if(total == k)
            {
                res++;
                i++;
                j--;
            }
            else if(total < k)
                i++;
            else
                j--;
        }
        return res;
    }
};