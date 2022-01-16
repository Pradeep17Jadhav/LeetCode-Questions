class Solution {
public:
    int countValidWords(string s) {
        istringstream ss(s);
        string curr;
        int res = 0;
        
        while (ss >> curr) 
            if(isValid(curr)) res++;
        
        return res;
    }
               
    bool isValid(string s)
    {
        int hyphenCount = 0;
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            //ignore alphabets
            if(isalpha(s[i])) 
                continue;
            
            //digits not allowed
            else if(isdigit(s[i])) 
                return false;
            
            else if(s[i] == '-')
            {
                //update count of hyphens
                hyphenCount++;
                
                //not valid if more than 1 hyphen, hyphen at start/end, not surrounded by alphabets
                if(hyphenCount > 1 or i == 0 or i == n-1 or !isalpha(s[i-1]) or !isalpha(s[i+1]))
                    return false;
                
            }
            //all punctuations should be last character
            else if(i != n-1)
                return false;
        }
        return true;
    }
};