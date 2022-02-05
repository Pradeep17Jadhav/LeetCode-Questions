class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        // return solution1(nums, target);
        return solution2(nums, target);

    }
    
    //time complexity: O(N)
    vector<int> solution2(vector<int>& nums, int target) {
        int less = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            count += nums[i] == target;
            less += nums[i] < target;
        }
        vector<int>res;
        while(count--)
        {
            res.push_back(less++);
        }
        return res;
    }
    
    //time complexity: O(nlogn) as sort is used
    vector<int> solution1(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        
        for(int i = 0; i< nums.size(); i++)
        {
            if(nums[i] == target)
                res.push_back(i);
            if(nums[i] > target)
                break;
        }
        return res;
    }
};