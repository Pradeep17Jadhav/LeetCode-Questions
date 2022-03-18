class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26, -1);
        for (int i = 0; i < s.length(); i++)
            lastIndex[s[i] - 'a'] = i; //track the lastIndex of the character's presence

        vector<bool> seen(26, false); //keep track of seen numbers
        stack<char> st;
        
        for (int i = 0; i < s.size(); i++)
        {
            int current = s[i] - 'a';
            if (seen[current]) 
                continue; // if already seen, continue to next, as we need to pick one char only
    
            while(st.size() > 0 && st.top() > s[i] && i < lastIndex[st.top() - 'a'])
            {
                seen[st.top() - 'a'] = false; //pop out & mark unseen
                st.pop();
            }

            st.push(s[i]); //add into the stack
            seen[current] = true; // mark as seen
        }
        
        string res = "";
        while (st.size() > 0)
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};