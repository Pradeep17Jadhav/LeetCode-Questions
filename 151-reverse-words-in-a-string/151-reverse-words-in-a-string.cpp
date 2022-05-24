class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        string word = "";
        
        //start iterating from begining and store characters in a string till space is found
        for(int i = 0; i <  s.size(); i++) {
            if(s[i] == ' ' && word != "") {
                if(res == "")
                    res = word;
                else
                    res = word + ' ' + res;
                word = "";
            }
            else if(s[i] != ' ') {
                word += s[i];
            }
        }
        
        //take care of last word
        if(word != "") {
            if(res == "") //handle case where no spaces are found as the given string has only one word
                res = word; 
            else
                res = word + ' ' + res;
        }
        
        return res;
    }
};