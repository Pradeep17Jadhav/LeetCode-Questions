class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        partition(s, 0, curr, res);
        return res;
    }
    
    void partition(string &s, int index, vector<string> &curr, vector<vector<string>> &res)
    {
        if(index == s.size())
        {
            res.push_back(curr);
            return;
        }
        
        for(int i = index; i < s.size(); i++)
        {
            if(isPalindrome(s, index, i))
            {
                curr.push_back(s.substr(index, i - index + 1));
                partition(s, i + 1, curr, res);
                curr.pop_back(); //backtrack
            }
        }
    }
    
    bool isPalindrome(string &s, int start, int end) {
        while(start <= end)
        {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};

//abaaba