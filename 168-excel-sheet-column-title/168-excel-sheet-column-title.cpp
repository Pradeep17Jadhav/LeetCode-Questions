class Solution {
public:
    //Similar to - https://leetcode.com/problems/excel-sheet-column-number
    string convertToTitle(int n) {
        //BD -> 2*26 + 4
        //BCA -> 2*26*26 + 3*26 + 1
        int curr;
        string res;
        while(n > 0)
        {
            n--; //as A stands for 1, not 0
            res.push_back(n % 26 + 'A'); //take remainder
            n /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};