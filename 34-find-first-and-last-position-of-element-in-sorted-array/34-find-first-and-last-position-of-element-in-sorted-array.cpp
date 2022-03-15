class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        
        while(start <= end)
        {
            mid = (start + end) / 2;
            if(nums[mid] == target)
            {
                start = end = mid;
                while(start >=0 && start < nums.size() && nums[start] == target)
                    start--;
                while(end >=0 && end < nums.size() && nums[end] == target)
                    end++;

                return {start+1, end-1};
            }
            else if(nums[mid] < target)
            {
                start = mid+1;
            }
            else if(nums[mid] > target)
            {
                end = mid-1;
            }
        }
        
        return {-1,-1};
    }
};