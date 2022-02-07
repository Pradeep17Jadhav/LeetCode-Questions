class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>hash1(26, INT_MAX);
        vector<int>hash2(26);
        for(auto &word: words)
        {
            for(auto &c: word)
                hash2[c - 'a']++;
            
            for(int i = 0; i < hash1.size(); i++)
            {
                hash1[i] = min(hash1[i], hash2[i]);
                hash2[i] = 0;
            }
        }
        
        vector<string> res;
        for(int i = 0; i < hash1.size(); i++)
            while(hash1[i]--) res.push_back(string(1, i + 'a'));

        return res;
    }
};