class Solution {
public:
    string sortString(string s) {
        vector<int> hash(26);
        string res = "";
        for(auto &c: s)
            hash[c - 'a']++;
        
        while(res.size() != s.size())
        {
            for(int i = 0; i < hash.size(); i++)
            {
                if(hash[i])
                {
                    res += i + 'a';
                    hash[i]--;
                }
            }
            for(int i = hash.size() - 1; i >= 0; i--)
            {
                if(hash[i])
                {
                    res += i + 'a';
                    hash[i]--;
                }
            }
        }
        return res;
    }
};