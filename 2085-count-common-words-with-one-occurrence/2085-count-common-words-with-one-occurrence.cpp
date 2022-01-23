class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> mp;
        
        //increment all words in words1 array
        for(string &s:words1)
        {
            mp[s]++;
        }
        
        for(string &s:words2)
        {
            //decrement only the words which occur at the most 1 times.
            if(mp[s] < 2)
            {
                mp[s]--;   
            }
        }

        int res = 0;
        for(auto &m: mp)
        {
            if(m.second == 0)
                res++;                
        }
        return res;
    }
};