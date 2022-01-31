class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, int>hash;
        for(int &i: nums1)
        {
            hash[i] = 1;
        }
        for(int &i: nums2)
        {
            if(!hash[i]) hash[i] = 2; //1
            else if(hash[i] == 1) hash[i] = 3; //2
        }
        for(int &i: nums3)
        {
            if(hash[i] == 2 or hash[i] == 1) hash[i] = 3;
        }
        vector<int>res;
        for(auto &[k, v]:hash)
        {
            if(v == 3) res.push_back(k);
        }

        return res;
    }
};