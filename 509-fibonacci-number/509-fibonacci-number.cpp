class Solution {
public:
    int fib(int n) {
        return fib1(n);
    }

    
    //Bottom up approach
    //TC: O(N)
    //SC: O(1)
    int fib1(int n) {
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
    //TC: O(2^N)
    //SC: O(N)
    int fib2(int n) {
        if(n == 0)  return 0;
        if(n == 1)  return 1;
        return fib(n-1) + fib(n-2);
    }
};