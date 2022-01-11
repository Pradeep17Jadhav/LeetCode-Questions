class Solution {
public:
    bool validPalindrome(string s) {
        int bonus = 1;
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