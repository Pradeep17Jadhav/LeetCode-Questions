class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char, int> hash;
        
        for(char &c : s) {
            hash[c]++;
            if(hash[c] == 2)
                return c;
        }
        return 'a';
    }
};