class Solution {
public:
    //Sliding window using 2 pointers
    int maximumUniqueSubarray(vector<int>& nums) {
        int currScore, maxScore, left, right;
        left = right = currScore = maxScore = 0;
        unordered_map<int, int> hash;
        
        while(right < nums.size()) {
            while(hash.find(nums[right]) != hash.end() && hash[nums[right]] >= left && left <= right) {
                currScore -= nums[left];
                left++;
            }

            hash[nums[right]] = right;
            currScore += nums[right];
            
            maxScore = max(maxScore, currScore);
            right++;
        }
        return maxScore;
    }
};