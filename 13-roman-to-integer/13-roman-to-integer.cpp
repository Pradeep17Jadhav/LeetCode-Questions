class Solution {
public:
    int romanToInt(string s) {
        char last = 'Z';
        int res = 0;
        for(char &c : s) {
            if(c == 'M') {
                res += 1000;
                if(last == 'C')
                    res -= 200;
            }
            else if(c == 'D') {
                res += 500;
                if(last == 'C')
                    res -= 200;
            }
            else if(c == 'C') {
                res += 100;
                if(last == 'X')
                    res -= 20;
            }
            else if(c == 'L') {
                res += 50;
                if(last == 'X')
                    res -= 20;
            }
            else if(c == 'X') {
                res += 10;
                if(last == 'I')
                    res -= 2;
            }
            else if(c == 'V') {
                res += 5;
                if(last == 'I')
                    res -= 2;
            }
            else
                res += 1;

            cout << res << " ";
            last = c;
        }  
        
        return res;
    }
};