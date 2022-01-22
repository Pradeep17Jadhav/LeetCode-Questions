class Solution {
public:
    int minAddToMakeValid(string s) {
        return usingStack(s);
        // return usingInt(s);
    }

    int usingInt(string &s)
    {
        int open = 0;
        int close = 0;
        for(char i:s)
        {
            if(i == '(')
                open++;
            else if(!open)
                close++;
            else
                open--;
        }
        return open + close;
    }
    
    int usingStack(string &s)
    {
        stack<char> st;
        int diff = 0;
        for(char i:s)
        {
            if(i == '(')
                st.push(i);
            else if(st.empty())
                diff++;
            else
                st.pop();
        }
        return diff + st.size();
    }
};