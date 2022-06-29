class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //Memoization
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));
        return recursion(triangle, dp, 0, 0);
    }
    
    int recursion(vector<vector<int>> &triangle, vector<vector<int>> &dp, int row, int col) {
        if(row == triangle.size() - 1)
            return triangle[row][col];

        if(dp[row][col] != -1)
            return dp[row][col];

        int bottom = recursion(triangle, dp, row+1, col);
        int diagonal = recursion(triangle, dp, row+1, col+1);

        return dp[row][col] = min(bottom, diagonal) + triangle[row][col];
    }

};