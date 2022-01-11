class Solution {
public:
    bool validPalindrome(string s) {
        // return validPalindromeSimple(s);
        return isPalindromeRecursive(s, 0, s.size() - 1, 0, 1);
    }
    
    bool isPalindromeRecursive(string &s, int front, int back, int deleteCount, int deleteAllowedCount)
    {
        if(deleteCount > deleteAllowedCount)
            return false;

        while(front < back)
        {
            if(s[front] == s[back])
            {
                front++;
                back--;
            }
            else
            {
                return (isPalindromeRecursive(s, front + 1, back, deleteCount + 1, deleteAllowedCount) or 
                        isPalindromeRecursive(s, front, back - 1, deleteCount + 1, deleteAllowedCount));
            }
        }
        return true;
    }
    
    //Simple approach without recursion
    //cannot be generalised for K number delete allowed
    bool validPalindromeSimple(string &s)
    {
        int n = s.size();
        int front1 = 0;
        int back1 = s.size() - 1;

        while(front1 < back1)
        {
            if(s[front1] != s[back1])
            {
                int front2 = front1 + 1;
                int back2 = back1 - 1;
                
                while(front1 < back2 and s[front1] == s[back2])
                {
                    front1++;
                    back2--;
                }
                
                while(front2 < back1 and s[front2] == s[back1])
                {
                    front2++;
                    back1--;
                }
                
                return front1 >= back2 or front2 >= back1;
            }
            else
            {
                front1++;
                back1--;
            }
            
        }
        return true;
    }
};