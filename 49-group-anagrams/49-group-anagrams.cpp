class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        vector<vector<string>> res;
        
        //store each string in a hash using sorted string as a key
        for(string &s: strs)
        {
            string temp = s;
            sortString(temp);
            hash[temp].push_back(s);
        }
        
        for(auto &kv: hash)
            res.push_back(kv.second);
        
        return res;
    }
    
    //Instead of using song() of STL, we can implement our own sort for this question
    //TC: O(N) 
    //SC: O(26) = O(1)
    void sortString(string &s)
    {
        vector<int> hash(26);
        int ptr = 0;
        for(char &c: s)
            hash[c - 'a']++;
        
        for(int i = 0; i < 26; i++)
        {
            if(hash[i])
            {
                s[ptr++] = i + 'a';
                hash[i--]--;
            }
        }
    }
};