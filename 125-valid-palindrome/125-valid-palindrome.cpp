class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(auto i:s)
        {
            if(isalnum(i))
            {
                if(isupper(i))
                    str += i + 32;
                else
                    str += i;
            }
                
        }
        
        int n = str.size();
        for(int i = 0; i < n / 2; i++)
        {
            if(str[i] != str[n - i - 1])
                return false;
        }
        return true;
    }
};