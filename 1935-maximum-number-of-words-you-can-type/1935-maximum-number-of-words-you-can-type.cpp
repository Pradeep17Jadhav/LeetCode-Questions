class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool>hash(26);
        for(char &c: brokenLetters)
            hash[c-'a'] = true;

        istringstream iss(text);
        bool canType;
        int res = 0;
        while(iss >> text)
        {
            canType = true;
            for(char &c: text)
            {
                if(hash[c-'a'])
                {
                    canType = false;
                    break;
                }
            }
            res += canType ? 1 : 0;
        }
        return res;
    }
};