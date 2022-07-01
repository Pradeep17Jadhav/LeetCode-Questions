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
        
        //base case
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
        int downdown = memoization(grid, dp, row1+1, row2+1,col1, col2); //both move down
        int downright = memoization(grid, dp, row1+1, row2, col1, col2+1); //pointer1 move down, pointer2 move right
        int rightdown = memoization(grid, dp, row1, row2+1, col1+1, col2); //pointer1 move right, pointer2 move down
        int rightright = memoization(grid, dp, row1, row2, col1+1, col2+1); //both pointers move right
        
        //take maximum of all paths
        maxCherries = max(downdown, max(downright, max(rightdown, rightright)));
        
        //return max of all paths + value at current cell
        return dp[row1][col1][col2] = maxCherries + currSum;
    }
    
    //same solution, just without passing row2 and calculating it
    int memoization_old(vector<vector<int>> &grid, vector<vector<vector<int>>> &dp, int row1, int col1, int col2) {
        int n = grid.size();
        
        //find row2 by checking how many cells the first pointer (row1, col1) has moved from (0, 0)
        //Let (row1, col1) = (3,1), (row2, col2) = (x,2), then ->
        //it must have moved 3 rows from 0th row
        //it must have moved 1 col from 0th col
        //So total 3 moves. let ptr1Moves = 4
        
        //At the same time, pointer 2 should also move by 4 moves.
        //If it is currently at (x, col2), then -> (x + col2) should be equal to ptr1Moves
        //So x+col2=4... x+2=4... x=4-2.. x=2
        //This means (row1 + col1) == (row2 + col2)
        //row2 = (row1 + col1) - col2
        int row2 = row1 + col1 - col2;
        
        if(row1 >= n || row2 >= n || col1 >= n || col2 >= n || 
           grid[row1][col1] == -1 || grid[row2][col2] == -1)
            return -1e9;
        
        //base case
        if(row1 == n-1 && col1 == n-1)
            return grid[row1][col1];

        //memoization
        if(dp[row1][col1][col2] != -1)
            return dp[row1][col1][col2];


        int currSum = 0;
        //If both pointers are not at single cell at any point, we will take sum of both
        //If both pointers are at single cell, we consider it only once
        //In this case, when both rows are unequal, then both pointers are definately on diff cells.
        //When both rows are equal, it means columns are also equal. so both ptrs are at same cell
        if(row1 != row2)
            currSum = grid[row1][col1] + grid[row2][col2];
        else
            currSum = grid[row1][col1]; //take any row1-col1 or row2-col2
        
        int maxCherries = -1e9;
        int downdown = memoization_old(grid, dp, row1+1, col1, col2);
        int downright = memoization_old(grid, dp, row1+1, col1, col2+1);
        int rightdown = memoization_old(grid, dp, row1, col1+1, col2); //increasing right will automatically take care of increasing row
        int rightright = memoization_old(grid, dp, row1, col1+1, col2+1);
        maxCherries = max(downdown, max(downright, max(rightdown, rightright)));
        return dp[row1][col1][col2] = maxCherries + currSum;
    }
};