class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        vector<vector<string>> res;
        for(string &s: strs)
        {
            string temp = s;
            sort(temp.begin(), temp.end());
            hash[temp].push_back(s);
        }
        
        for(auto &kv: hash)
            res.push_back(kv.second);
        
        return res;
    }
};