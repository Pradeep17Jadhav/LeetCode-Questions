class Solution {
public:
    int uniquePaths(int m, int n) {
        // return recursive(m-1, n-1); //TLE
        
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return memoization(dp, m-1, n-1);
        
        // return tabulation(m, n);
        return tabulation_optimized(m, n);
    }

    int tabulation_optimized(int row, int col) {  
        vector<int> dp(col, 1);
        
        //0th row and 0th col will always be 1 value
        for(int i = 1; i < row; i++) {
            for(int j = 1; j < col; j++) {
                dp[j] += dp[j-1];
            }
        }
        return dp[col-1];
    }
    
    
    int tabulation(int row, int col) {  
        vector<vector<int>> dp(row, vector<int>(col, 1));
        
        for(int i = 1; i < row; i++) {
            for(int j = 1; j < col; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[row-1][col-1];
    }
    
    //TC: O(N)
    //SC: auxilary + dp array = O(2*N) = O(N)
    int memoization(vector<vector<int>> &dp, int row, int col) {
        if(row < 0) return 0;
        if(col < 0) return 0;
        if(row == 0 && col == 0)
            return 1;
        if(dp[row][col] != -1)
            return dp[row][col];

        return dp[row][col] = memoization(dp, row-1, col) + memoization(dp, row, col-1);
    }
    
    //TC: O(N^2)
    int recursive(int row, int col) {
        if(row < 0) return 0;
        if(col < 0) return 0;
        if(row == 0 && col == 0)
            return 1;

        return recursive(row-1, col) + recursive(row, col-1);
    }
    
};