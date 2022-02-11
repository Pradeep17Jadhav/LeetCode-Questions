class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
            return false;

        vector<int>hash1(26); //for s1
        vector<int>hash2(26); //for s2
        
        //two pointers for sliding window
        int i = 0;
        int j = 0;

        //fill window for s1 string and start window of same size for s2
        while(j < s1.size())
        {
            hash1[s1[j] - 'a']++;
            hash2[s2[j] - 'a']++;
            j++;
        }

        while(j <= s2.size()) //traverse all letters
        {
            //if current window is anagram of s1, return true
            if(hash1 == hash2) 
                return true;

            if(j != s2.size()) //since j is next index of the window
                hash2[s2[j] - 'a']++; //add next char of window in hash

            hash2[s2[i] - 'a']--; //remove first char of window from hash
            
            //move the window
            i++;
            j++;
        }
        return false;  
    }
};