class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> list;
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(auto word: words)
        {
            string str = "";
            for(auto letter: word)
            {
                str += morse[int(letter) - 97];
            }
            list.insert(str);
        }
        return list.size();
    }
};