class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>hash(26);
        for(auto &c:s)
            hash[c - 'a']++;
        for(int i = 0; i < s.size(); i++)
        {
            if(hash[s[i] - 'a'] == 1)
                return i;
        }
        
        // unordered_map<char,int> hash;
        // for(char i: s) hash[i]++; // save ocurrrences without sorting -- unordered 
        // for(int i=0;i<s.size();i++) 
        //     if (hash[s[i]]==1) return i;

        return -1; 
    }
};