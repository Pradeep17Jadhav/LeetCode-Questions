class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int res = 0;
        unordered_map<string, int> mp;
        for(string &word: words)
            mp[word]++;
            
        for(auto it: mp)
        {
            if(it.first.size() > s.size())
                continue;

            int si = 0;
            int wi = 0;
            while(si < s.size() && wi < it.first.size())
            {
                if(s[si] == it.first[wi])
                    wi++;
                si++;
                if(wi == it.first.size())
                    res += it.second;
            }
        }
        return res;
    }
};