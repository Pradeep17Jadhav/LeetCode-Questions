class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int>hash;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
        {
            if(!hash.insert(nums[i]).second)
                res.push_back(nums[i]);
        }
        return res;
    }
};