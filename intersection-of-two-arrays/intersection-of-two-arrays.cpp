class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> s(nums1.begin(), nums1.end());
        
        for(int i:nums2)
        {
            if(s.count(i))
            {
                res.push_back(i);
                s.erase(i);
            }
        }
        return res;
    }
};