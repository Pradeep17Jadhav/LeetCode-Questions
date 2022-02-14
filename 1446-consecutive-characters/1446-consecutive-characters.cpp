class Solution {
public:
    int maxPower(string s) {
        int maxx = 0;
        int i = 0;
        int j = 0;
        
        while(j < s.size())
        {
            if(s[i] == s[j])
                j++;
            else
                maxx = max(maxx, j - i++);
        }
        return max(maxx, j - i); //to handle case of only 1 char in string as while loop is not executed.
    }
};