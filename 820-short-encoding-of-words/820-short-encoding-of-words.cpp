class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> s1(words.begin(), words.end());
        set<string> s2(words.begin(), words.end());
        
        for(auto &s: s1)
        {
            for(int i = 1; i < s.length(); i++)
            {
                s2.erase(s.substr(i));
            }
        }
        
        int sum = 0;
        for(auto &s : s2)
        {
            sum = sum + s.length() + 1;
        }
        
        return sum;
    }
};