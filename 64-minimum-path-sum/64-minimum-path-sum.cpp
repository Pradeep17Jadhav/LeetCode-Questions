class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // return recursive(grid, grid.size()-1, grid[0].size()-1);
        
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return memoization(grid, dp, grid.size()-1, grid[0].size()-1);
    }
    
    int memoization(vector<vector<int>>& grid, vector<vector<int>> &dp, int row, int col) {
        if(row < 0) return -1;
        if(col < 0) return -1;
        if(row == 0 && col == 0)
            return grid[0][0];
        
        if(dp[row][col] != -1)
            return dp[row][col];

        int above = memoization(grid, dp, row-1, col); //can return 0 for negative index
        int left = memoization(grid, dp, row, col-1); //can return 0 for negative index
        int curr = grid[row][col];
        
        if(above == -1)
            dp[row][col] = left + curr;
        else if(left == -1)
            dp[row][col] = above + curr;
        else 
            dp[row][col] = min(left, above) + curr;

        return dp[row][col];
    }
    
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