class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int negatives = 0;
        bool isLeftGreater = false;
        bool isRightLesser = false;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] - nums[i-1] < 0) {
                if(++negatives > 1)
                    return false;
                
                if(i >= 2)
                    isLeftGreater = nums[i-2] > nums[i];
                if(i+1 < nums.size())
                    isRightLesser = nums[i+1] < nums[i-1];
            }
        }
        
        return !isLeftGreater || !isRightLesser;
    }
};