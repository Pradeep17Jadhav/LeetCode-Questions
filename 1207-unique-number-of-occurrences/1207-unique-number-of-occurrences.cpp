class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int>hash;
        unordered_map<int, int>hashCount;
        for(int &i: arr)
            hash[i]++;
        
        for(auto &[k, v]: hash)
        {
            if(++hashCount[v] > 1)
                return false;
        }
        return true;
    }
};