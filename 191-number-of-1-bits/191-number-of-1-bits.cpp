class Solution {
public:
    int hammingWeight(uint32_t n) {
        // return hammingWeight_1(n);
        return hammingWeight_2(n);
    }
    
    //if we do [n & (n - 1)] we will be reducing one bit from the number
    //e.g. 9 & 8 = 8 i.e.1001 & 1000 = 1000,
    //e.g. 6 & 5 = 4 i.e. 110 & 101 = 100.
    //Full example - 
    //input - 00000000000000000000000000101011 (43)
    // - 101011 && 101010 = 101010 (42)
    // - 101010 && 101001 = 101000 (40)
    // - 101000 && 100111 = 100000 (32)
    // - 100000 && 011111 = 000000 (0)
    int hammingWeight_2(uint32_t n) {
        int res = 0;
        while(n > 0) {
            cout << n << endl;
            n = n & (n-1);
            res++;
        }

        return res;
    }
    
    //bruteforce
    int hammingWeight_1(uint32_t n) {
        int res = 0;
        while(n > 0) {
            res += n%2; // if(n%2==1) res++
            n /= 2;
        }

        return res;
    }
};