class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> seen; //to store indices of seen numbers
        int num, required;
        for(int i = 0; i < nums.size(); i++)
        {
            required = target - nums[i]; //the number required to make 2sum==target
            if(seen.find(required) != seen.end()) //if target is already seen, return its index and index of curr number
                return {i, seen[required]};
            seen[nums[i]] = i; //store index of current number as seen element
        }
        return {};
    }
};
