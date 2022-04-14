class Solution {
public:
    int tribonacci(int n) {
        return tribonacci_1(n);
        // return tribonacci_2(n);
    }
    
    //TC: O(N)
    //SC: O(1)
    int tribonacci_1(int n) {
        if(n == 0 || n == 1)
            return n;
        if(n == 2)
            return 1;
        
        int a = 0;
        int b = 1;
        int c = 1;
        int d;
        
        for(int i = 3; i <= n; i++) {
            d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        return d;
    }
    
    //Dynamic programming - memoisation
    //TC: O(N)
    //SC: O(N)
    int tribonacci_2(int n) {
        if(n == 0 || n == 1)
            return n;
        if(n == 2)
            return 1;

        vector<int> memo(n+1);
        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 1;
        
        for(int i = 3; i <= n; i++)
            memo[i] = memo[i-1] + memo[i-2] + memo[i-3];
        
        return memo[n];
    }
};