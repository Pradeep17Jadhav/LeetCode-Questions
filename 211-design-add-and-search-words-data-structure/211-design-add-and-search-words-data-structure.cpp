class WordDictionary {
public:
    unordered_map<int, vector<string>> hash;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        hash[word.size()].push_back(word);
    }
    
    bool search(string word) {
        for(auto &s: hash[word.size()])
        {
            bool bFound = true;
            for(int i = 0; i < word.size(); i++)
            {
                if(word[i] != '.' and word[i] != s[i])
                {
                    bFound = false;
                    break;
                }
            }
            if(bFound)
                return true;
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */