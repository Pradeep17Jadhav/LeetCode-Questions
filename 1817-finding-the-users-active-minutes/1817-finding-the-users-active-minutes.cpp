class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> hash;
        for(auto &v: logs)
            hash[v[0]].insert(v[1]);
        
        vector<int> res(k);
        for(auto &x: hash)
            res[x.second.size() - 1]++;

        return res;
    }
};