class Solution {
public:
    string minRemoveToMakeValid(string s) {
        return withoutStack(s);
        // return usingStack(s);
    }

    //TC: O(N)
    //SC: O(1)
    string withoutStack(string &s)
    {
        string res = "";
        int count = 0;
        vector<int>stack;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
                count++;
            else if(s[i] == ')')
                count--;
            
            if(count >= 0)
                res.push_back(s[i]);
            else
                count++;
        }  
        s = res;
        res = "";
        count = 0;
        for(int i = s.size() - 1; i >= 0; i--)
        {
            if(s[i] == ')')
                count++;
            
            else if(s[i] == '(')
                count--;

            if(count >= 0)
                res.push_back(s[i]);
            else
                count++;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    //TC: O(N)
    //SC: O(N)
    string usingStack(string &s)
    {
        string res = "";
        vector<char>stack;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
                stack.push_back('(');
            
            if(s[i] == ')')
            {
                if(!stack.empty())
                    stack.pop_back();
                else
                    continue;
            }
            
            res.push_back(s[i]);
        }
        
        stack.clear();
        s = res;
        res = "";
        for(int i = s.size() - 1; i >= 0; i--)
        {
            if(s[i] == ')')
                stack.push_back(')');
            
            if(s[i] == '(')
            {
                if(!stack.empty())
                    stack.pop_back();
                else
                    continue;
            }
            
            res.push_back(s[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};