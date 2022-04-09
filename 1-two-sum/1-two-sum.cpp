class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> seen;
        int num, required;
        for(int i = 0; i < nums.size(); i++)
        {
            num = nums[i];
            required = target-num;
            if(seen.count(required))
                return {i, seen[required]};
            seen[num] = i;
        }
        return {};
    }
};
