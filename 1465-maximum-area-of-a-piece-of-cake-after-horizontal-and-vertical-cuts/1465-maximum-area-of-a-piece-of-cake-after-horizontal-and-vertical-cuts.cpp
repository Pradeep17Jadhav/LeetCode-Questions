class Solution {
public:
    int maxArea(int h, int w, vector<int>& H, vector<int>& V) {
        return long(getMaxGap(H, h)) * getMaxGap(V, w) % 1000000007;
    }
    int getMaxGap(vector<int>& nums, int maxSize) {
        sort(nums.begin(), nums.end());
        
        // handling the case of first and last piece of cake
        int maxGap = max(nums[0], maxSize - nums.back()); 
        
        for(int i = 1; i < nums.size(); i++) 
            maxGap = max(maxGap, nums[i] - nums[i-1]);

        return maxGap;
    }
};