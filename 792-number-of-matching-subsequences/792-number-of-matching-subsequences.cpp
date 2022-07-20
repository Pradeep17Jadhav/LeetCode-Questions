class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        // return using_hashmap(s, words);
        return using_binary_search(s, words);
    }
    
    int using_binary_search(string s, vector<string>& words) {
        int res = 0;
        //save each character of original string, and all the index at which char is present, in a vector
        unordered_map<char, vector<int>> mp;
        for(int i = 0; i < s.size(); i++) {
            mp[s[i]].push_back(i);
        }
        
        for(string word: words) {
            if(word.size() > s.size())
                continue;
            
            int lastPos = -1;
            bool bFound = true;
            
            //check all chars of each word, if they are present in S or not
            for(char c: word) {
                //Instead of interating over all chars of S, for each word,
                //we can directly jump on the next index of char, at which it is present
                //get iterator at the index in vector, for a number greater than lastPos
                //Example, if S="aaabaaa", word is ["aba"]
                //Hashmap will be ->
                // a = [0,1,2,4,5,6]
                // b = [3]
                //first, lastPos becomes 0 for 'a'
                //lastPos becomes 3 for 'b'
                //lastPos becomes 4 for 'a'
                //We can see that instead of traversing whole S string for 'a', 
                //we directly found index 4 of 'a', which is greater that lastPost 3
                auto it = upper_bound(mp[c].begin(), mp[c].end(), lastPos);
                if(it != mp[c].end())
                {
                    int indPosition = it - mp[c].begin(); //find index of the number in mp[char] vector, greater than lastPost
                    lastPos = mp[c][indPosition]; //find the number(index of new 'a') from the vector
                }
                else {
                    bFound = false;
                    break;
                }
            }
            if(bFound)
                res++;
        }
        return res;
        
    }
    
    //TC: O(unique words * s.size()) = O(words.size() * s.size())
    //SC: O(total words)
    int using_hashmap(string s, vector<string>& words) {
        int res = 0;
        
        //set all words in a map so that duplicates will be eliminated
        unordered_map<string, int> mp;
        for(string &word: words)
            mp[word]++;
            
        for(auto it: mp)
        {
            if(it.first.size() > s.size())
                continue;

            int si = 0;
            int wi = 0;
            while(si < s.size() && wi < it.first.size())
            {
                if(s[si] == it.first[wi])
                    wi++;
                si++;
                if(wi == it.first.size())
                    res += it.second;
            }
        }
        return res;
    }
};