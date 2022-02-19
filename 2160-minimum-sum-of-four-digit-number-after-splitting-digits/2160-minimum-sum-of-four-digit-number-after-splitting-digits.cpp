class Solution {
public:
    int minimumSum(int num) {
        //combination of 3+1 or 1+3 chars will always be greater than 2+2 chars
        //so we will just use 2+2
        string n = to_string(num);
        sort(n.begin(), n.end());
        
        //for sorted numbers a,b,c,d; the smallest sum will be ac + bd
        return (n[0]-'0' + n[1]-'0') *10 + n[2]-'0' + n[3]-'0';
    }
};