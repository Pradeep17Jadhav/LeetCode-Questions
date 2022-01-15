class Solution {
public:
    string reversePrefix(string word, char ch) {
        for(int i = 0; i < word.size(); i++)
        {
            if(word[i] == ch)
            {
                reverse(word.begin(), word.begin() + i + 1); //in reverse(), the "last" argument index is excluded
                break;
            }
        }
        return word;
    }
};