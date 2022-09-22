class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        int left, right;
        left = right = 0;
        for(int i = 0; i < s.size(); i++) {
            char curr = s[i];
            
            if(curr == ' ') {
                right--;
                while(left <= right) {
                    res += s[right--];
                }
                res += ' ';
                left = right = i+1;
            }
            else {
                right++;
            }
        }
        
        right--;
        while(left <= right) {
            res += s[right--];
        }
        return res;
    }
};