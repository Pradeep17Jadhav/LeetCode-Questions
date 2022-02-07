class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int>hash(26);

        for(char &c: s)
            hash[c - 'a']++;
        
        for(char &c: t)
            hash[c - 'a']--;
        
        for(int i = 0; i < 26; i++)
            if(hash[i]) return i + 'a';
            
        return 'a';
    }
};