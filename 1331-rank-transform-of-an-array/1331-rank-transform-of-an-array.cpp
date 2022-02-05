class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int>st(arr.begin(), arr.end());
        unordered_map<int, int>mp;
        int rank = 1;
        for(auto &i: st)
        {
            mp[i] = rank++;
        }
        
        for(int &i: arr)
        {
            i = mp[i];
        }
        
        return arr;
    }
};