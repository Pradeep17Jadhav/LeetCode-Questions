class Solution {
public:
    string mostCommonWord(string s, vector<string>& banned) {
        unordered_map<string, int> mp;
        
        for(auto &c:s)
            c = isalpha(c) ? tolower(c) : ' ';

        istringstream iss(s);
        while(iss >> s)
        {
            mp[s]++;
        }
        
        for(string s:banned)
            mp[s] = 0;
        
        string ans;
        for(auto &[k, v]: mp)
        {
            if(v > mp[ans])
                ans = k;
        }
        
        return ans;
    }
};