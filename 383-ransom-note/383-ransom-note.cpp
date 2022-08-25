class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> hash;
        for(char &c: ransomNote) {
            hash[c]++;
            cout << c << " " << hash[c] << endl;
        }
        
        for(char &c: magazine) {
            if(hash.find(c) != hash.end() && hash[c])
                hash[c]--;
        }
        
        for(auto &[k, v] : hash)
            if(v != 0) return false;
        
        return true;
    }
};