class Solution {
public:
    string chars = "aeiou";
    int res = 0;
    int countVowelStrings(int n) {
        char temp = '#';
        find(n, temp);
        return res;
    }
    
    void find(int n, char &temp) {
        if(!n) {
            res++;
            return;
        }
        
        for(char &c: chars) {
            if(temp > c)
                continue;
            temp = c;
            find(n-1, temp);
            temp = '#';
        }
    }
};