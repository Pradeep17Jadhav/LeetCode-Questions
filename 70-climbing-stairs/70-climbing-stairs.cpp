class Solution {
public:
    int climbStairs(int n) {
        return climbStairs_1(n);
        // return climbStairs_2(n);
    }
    
    //DP
    //TC: O(N)
    //SC: O(N)
    int climbStairs_1(int n) {
        vector<int> memo(n+1);
        memo[0] = 1; //ways to climb 0th stair
        memo[1] = 2; //ways to climb 1st stair
        for(int i = 2; i < n; i++)
            memo[i] = memo[i-1] + memo[i-2]; //ways to climb ith stair = ways to climb (i-1)th stair + ways to climb (i-2)th stair
        
        return memo[n-1];
    }
        
    //TC: O(N)
    //SC: O(1)
    int climbStairs_2(int n) {
        int a = 1, b = 1, c;
        
        while (--n) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};