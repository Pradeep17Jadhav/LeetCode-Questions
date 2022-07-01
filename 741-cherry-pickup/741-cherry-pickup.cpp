class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1))); //3D memoization vector
        int cherries = memoization(grid, dp, 0, 0, 0, 0); //start two pointers at (0,0) and (0,0)
        return cherries <= 0 ? 0 : cherries; //handle case of no cherries collected
    }
    
    int memoization(vector<vector<int>> &grid, vector<vector<vector<int>>> &dp, int row1, int row2, int col1, int col2) {
        int n = grid.size();
       
        //handle out of bound cases and thorn blocker
        if(row1 >= n || row2 >= n || col1 >= n || col2 >= n || grid[row1][col1] == -1 || grid[row2][col2] == -1)
            return -1e9; //return very small integer
        
        //base case (reached the destination)
        if(row1 == n-1 && col1 == n-1)
            return grid[row1][col1];

        //memoization
        if(dp[row1][col1][col2] != -1)
            return dp[row1][col1][col2];


        int currSum = 0;
        //Assume (row1, col1) as pointer1 and (row2, col2) as pointer2
        //If both pointers are at different cells at any point, we will take sum of both
        //If both pointers are at single cell, we consider it only once
        //In this case, when both rows are unequal, then both pointers are definately on diff cells.
        //When both rows are equal, it means columns are also equal. so both ptrs are at same cell
        if(row1 != row2)
            currSum = grid[row1][col1] + grid[row2][col2];
        else
            currSum = grid[row1][col1]; //take any - grid[row1][col1] or grid[row2][col2]
        
        int maxCherries = -1e9; //initialize with very small value. Not using INT_MIN to avoid int overflow
        
        //recursively call for combination of direction for both pointers together
        int downdown = memoization(grid, dp, row1+1, row2+1,col1, col2); //both move downwards
        int downright = memoization(grid, dp, row1+1, row2, col1, col2+1); //pointer1 move downwards, pointer2 move to right
        int rightdown = memoization(grid, dp, row1, row2+1, col1+1, col2); //pointer1 move to right, pointer2 move downwards
        int rightright = memoization(grid, dp, row1, row2, col1+1, col2+1); //both pointers move to right
        
        //take maximum of all paths
        maxCherries = max(downdown, max(downright, max(rightdown, rightright)));
        
        //save to DP and return max of all paths + value at current cell
        return dp[row1][col1][col2] = maxCherries + currSum;
    }
};