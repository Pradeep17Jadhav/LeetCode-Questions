class Solution {
public:
    int titleToNumber(string t) {        
        //Let string is BD
        //Ans will be 1*26 + 4
        
        //Similarly for
        //BCA -> 2*26*26 + 3*26 + 1

        int res = 0;
        for(int i: t)
        {
            //starting from left to right
            //so for each character at left, 26 will be multiplied each time
            //except first time (as res will be 0)
            res = res * 26 + (i - 'A' + 1);
        }
        return res;
    }
};