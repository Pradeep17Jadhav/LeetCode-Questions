class Solution {
public:
    //not sure why this question has medium difficulty. It should be easy.
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxx = 0;
        unsigned int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            maxx = max(maxx, nums[i] + nums[n - i - 1]);
        }
        return maxx;
    }
};