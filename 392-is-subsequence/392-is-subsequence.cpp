class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0; //to traverse s
        int j = 0; //to traverse t

        for(; i < s.size(), j < t.size(); j++)
        {
            //if both chars are equal, both pointers will increment
            //otherwise only j will increment (consider this as deleting some chars)
            if(s[i] == t[j])
                i++;
        }
        
        //since i is incremented only on match, when both pointers are reached end,
        //i should be equal to size of s, which means all chars of s are matched
        return i == s.size();
    }
};