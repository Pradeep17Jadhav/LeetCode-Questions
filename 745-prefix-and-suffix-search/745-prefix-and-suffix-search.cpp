class WordFilter {
public:
    unordered_map<string, int> mp;
    WordFilter(vector<string>& words) {
        int n = words.size();
        int wordsize;
        string pre;

        for(int i = 0; i < n; i++) //cover each word in words
        {
            string word = words[i]; 
            wordsize = word.size();
            
            //storing all possible sequence of prefix and suffix of a word in the hashmap
            for(int j = 1; j <= wordsize; j++) //for preffix 
            {
                pre = word.substr(0, j);
                
                for(int k = 0; k < wordsize; k++) //for suffix
                {
                    string suff = word.substr(k, wordsize);
                    mp[pre + "|" + suff] = i + 1; //set index i+1 for all possible sequence of a word
                    //we set i+1 to handle i=0 because by-default map initialized with 0 
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string s = prefix + "|" + suffix;
        return mp[s] - 1; 
    }
};
