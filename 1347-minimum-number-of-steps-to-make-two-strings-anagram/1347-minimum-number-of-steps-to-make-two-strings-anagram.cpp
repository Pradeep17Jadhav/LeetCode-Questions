class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> hash(26);
        for(char &c: s)
            hash[c - 'a']++;
        
        int res = 0;
        for(char &c: t)
        {
            if(hash[c - 'a'])
                hash[c - 'a']--;
            else
                res++;
        }
        
        return res;
    }
};