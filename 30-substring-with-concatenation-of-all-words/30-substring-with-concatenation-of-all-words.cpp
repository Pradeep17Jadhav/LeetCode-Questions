class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int wordCount = words.size();
        int wordLength = words[0].size();
        int charCount = wordLength * wordCount;
        
        if(s.size() < charCount) 
            return res;
        
        unordered_map<string, int> freq;
        for(string word:words)
            freq[word]++;
        
        for(int i = 0; i <= s.size()-charCount; i++)
        {
            int j;
            unordered_map<string, int> mp = freq;
            
            for(j = 0; j < s.size(); j++)
            {
                //create string of size m and starting index i+j*wordLength
                string temp = s.substr(i+j*wordLength, wordLength); 
                
                if(mp[temp]==0)
                    break;

                mp[temp]--;
            }
            //check whether all word in words are in the string or not 
            if(j == wordCount) 
                res.push_back(i);
        }
        return res;
        
    }
};