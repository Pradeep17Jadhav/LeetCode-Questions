class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //Memoization
        // vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));
        // return memoization(triangle, dp, 0, 0);
        
        //Tabulation
        return tabulation(triangle);
    }
        
    int tabulation(vector<vector<int>> &triangle) {
        vector<int> dp(triangle.size()+1);
        
        for(int i = triangle.size()-1; i >= 0; i--) {
            for(int j = 0; j < triangle[i].size(); j++) {
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }
        return dp[0];
    }

    int memoization(vector<vector<int>> &triangle, vector<vector<int>> &dp, int row, int col) {
        if(row == triangle.size() - 1)
            return triangle[row][col];

        if(dp[row][col] != -1)
            return dp[row][col];

        int bottom = memoization(triangle, dp, row+1, col);
        int diagonal = memoization(triangle, dp, row+1, col+1);

        return dp[row][col] = min(bottom, diagonal) + triangle[row][col];
    }

};