class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // return recursive(grid, grid.size()-1, grid[0].size()-1); //TLE
        
        // vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        // return memoization(grid, dp, grid.size()-1, grid[0].size()-1);
        
        return tabulation(grid);
    }
    
    int tabulation(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<int> dp(col+1, -1);
        dp[1] = 0;
        
        for(int i = 1; i <= row; i++) {
            for(int j = 1; j <= col; j++) {
                int curr;
                if(dp[j] == -1)
                    curr = dp[j-1];
                else if(dp[j-1] == -1)
                    curr = dp[j];
                else
                    curr = min(dp[j], dp[j-1]);
                
                dp[j] = curr + grid[i-1][j-1]; 
            }
        }
        return dp[col];
    }
    
    int memoization(vector<vector<int>>& grid, vector<vector<int>> &dp, int row, int col) {
        if(row < 0) return -1;
        if(col < 0) return -1;
        if(row == 0 && col == 0)
            return grid[0][0];
        
        if(dp[row][col] != -1)
            return dp[row][col];

        int above = memoization(grid, dp, row-1, col); //can return -1 for negative index
        int left = memoization(grid, dp, row, col-1); //can return -1 for negative index
        int curr = grid[row][col];
        
        if(above == -1)
            dp[row][col] = left + curr;
        else if(left == -1)
            dp[row][col] = above + curr;
        else 
            dp[row][col] = min(left, above) + curr;

        return dp[row][col];
    }
    
    //Might give TLE
    int recursive(vector<vector<int>>& grid, int row, int col) {
        if(row < 0) return 0;
        if(col < 0) return 0;
        if(row == 0 && col == 0)
            return grid[0][0];

        int above = recursive(grid, row-1, col); //can return 0 for negative index
        int left = recursive(grid, row, col-1);
        int curr = grid[row][col];
        return above == 0 ? left + curr : min(left, above) + curr;
    }
};