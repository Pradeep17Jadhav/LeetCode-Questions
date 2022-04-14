class Solution {
public:
    int fib(int n) {
        return fib1(n); //avg ans
        // return fib2(n); //best ans
        // return fib3(n); //worst ans
    }

    
    //dynamic programming - memoisation
    //TC: O(N)
    //SC: O(N)
    int fib1(int n) {
        if(n <= 1) return n;
        vector<int> memo(n+1);
        memo[0] = 0;
        memo[1] = 1;
        
        for(int i = 2; i <= n; i++)
            memo[i] = memo[i-1] + memo[i-2];
        
        return memo[n];
    }

    //Bottom up approach
    //TC: O(N)
    //SC: O(1)
    int fib2(int n) {
        if(!n) return 0;
        int fa = 0;
        int fb = 1;
        int fc;
        n -= 1;
        
        while(n-- > 0)
        {
            fc = fa + fb;
            fa = fb;
            fb = fc;
        }
        return fb;
    }
    
    //Recursive
    //TC: O(2^N) - should be avoided at all costs
    //SC: O(N)
    int fib3(int n) {
        if(n == 0)  return 0;
        if(n == 1)  return 1;
        return fib(n-1) + fib(n-2);
    }
};