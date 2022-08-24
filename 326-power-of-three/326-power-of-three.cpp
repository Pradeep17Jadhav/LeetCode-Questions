class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 1) return true;
        long long curr = 3;
        int power = 32;
        while(power-- && n >= curr) {
            if(curr == n)
                return true;
            curr *= 3;
        }
        return false;
    }
};