class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> hash;
        
        for(int i = 0; i < groupSizes.size(); i++)
            hash[groupSizes[i]].push_back(i);
        
        vector<vector<int>>res;
        for(auto group: hash)
        {
            int groupCount = group.first;
            vector<int> temp;
            int i = 0;
            while(i < group.second.size())
            {
                temp.assign(group.second.begin() + i, group.second.begin()+i+groupCount); //copy vector
                res.push_back(temp);
                i += groupCount;
            }
        }
        
        return res;
    }
};