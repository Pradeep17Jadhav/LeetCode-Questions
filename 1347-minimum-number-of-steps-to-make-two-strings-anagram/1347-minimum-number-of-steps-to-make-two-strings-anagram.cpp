class Solution {
public:
    int minSteps(string s, string t) {
        // return minStepsMethod1(s, t);
        return minStepsMethod2(s, t);
    }
    
    int minStepsMethod2(string &s, string &t)
    {
        vector<int> hash(26);
        for(int i = 0; i < s.size(); i++)
        {
            hash[s[i] - 'a']++;
            hash[t[i] - 'a']--;
        }
            
        int res = 0;
        for(int &i: hash)
        {
            if(i > 0)
                res += i;
        }
        
        return res;
    }
    
    int minStepsMethod1(string &s, string &t) {
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