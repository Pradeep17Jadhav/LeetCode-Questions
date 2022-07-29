class Solution {
public:
     vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
		// store numeric patten of Pattern string in v
        vector<int> v = find_Pattern(pattern);
        
        int n = words.size();
        vector<string> ans;
        
		// iterating and comparing pattern of each word with v(numeric pattern of Pattern)
        for(int i = 0; i < n; ++i)
        {
            vector<int> pattern_word = find_Pattern(words[i]);
            
			// if matched add words[i] to answer vector
            if(v == pattern_word)
                ans.push_back(words[i]);
        }
        
        return ans;
    }
    
    vector<int> find_Pattern(string pattern)
    {
        vector<int> v;
        if(pattern.empty())
            return v;

        int ind = 0;
		
        unordered_map<char,int> mp;
        int n = pattern.size();
        for(int i = 0; i < n; i++)
        {
			// if character not present in map, insert the char with an index,
			// increment index because for next unique character the index should be differnt.
           if(mp.find(pattern[i]) == mp.end())
               mp[pattern[i]] = ind++;

            v.push_back(mp[pattern[i]]);
        }
		// return numeric pattern
        return v;
    }
};