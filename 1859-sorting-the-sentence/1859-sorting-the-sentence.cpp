class Solution {
public:
    string sortSentence(string s) {

        string res;
        int start = 0;
        map<int, string> hash;
        for(int i = 1; i < s.size(); i++)
        {
            if(isdigit(s[i]))
            {
                hash[s[i]] = s.substr(start, i - start);
                start = i + 2;
                i++;
            }
        }
        
        for(auto i:hash)
        {
                res += i.second + " ";
        }
       return res.substr(0, res.size() - 1);
    }
};