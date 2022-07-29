class Solution {
public:
     vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<int> temp;
        vector<int> match = find_Pattern(pattern,  temp); // pattern to be matched
        
        int n = words.size();
        vector<string> res;
        
        //match pattern with all strings
        for(int i = 0; i < n; i++)
        {
            vector<int> pattern_word = find_Pattern(words[i], match);
            
			// if matched add words[i] to answer vector
            if(pattern_word.size())
                res.push_back(words[i]);
        }
        
        return res;
    }
    
    vector<int> find_Pattern(string pattern, vector<int> &match)
    {
        vector<int> v;
        if(pattern.empty())
            return v;

        unordered_map<char,int> mp;
        int ind = 0;
        int n = pattern.size();
        for(int i = 0; i < n; i++)
        {
			// if character not present in map, insert the char with an index,
			// increment index because for next unique character the index should be differnt.
           if(mp.find(pattern[i]) == mp.end())
               mp[pattern[i]] = ind++;

            if(match.size() && match[i] != mp[pattern[i]])
                return {};

            v.push_back(mp[pattern[i]]);
        }
		// return numeric pattern
        return v;
    }
};