class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int i = 0;
        int j = 0;
        int n = s.size();
        int maxx = 0;
        
        while(i < n and j < n)
        {
            //if char is not in the set, it is not repeated.
            //so insert it in the set and update max
            if(st.find(s[j]) == st.end())
            {
                st.insert(s[j++]);
                maxx = max(maxx, j - i);
            }
            //if char is in set, it is repeated.
            //remove it from set and increament i pointer.
            else
            {
                st.erase(s[i]);
                i++;
            }
        }
        return maxx;
    }
};