class Solution {
public:
    int mod = 1000000000 + 7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if(maxMove == 0) return 0;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        return memoization(dp, m, n, maxMove, startRow, startColumn);
    }

    int memoization(vector<vector<vector<int>>> &dp, int m, int n, int moves, int row, int col) {
        if(row < 0 || row >= m || col < 0 || col >= n)
            return 1;
        
        if(moves <= 0)
            return 0;
        
        if(dp[row][col][moves] != -1)
            return dp[row][col][moves];
        int paths = 0;
        paths = (paths + memoization(dp, m, n, moves-1, row, col-1)) % mod;
        paths = (paths + memoization(dp, m, n, moves-1, row-1, col)) % mod;
        paths = (paths + memoization(dp, m, n, moves-1, row, col+1)) % mod;
        paths = (paths + memoization(dp, m, n, moves-1, row+1, col)) % mod;

        dp[row][col][moves] = paths;
        return paths % mod;
    }
};