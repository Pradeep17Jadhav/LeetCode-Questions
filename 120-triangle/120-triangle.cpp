class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> currRow(n, 0);
        vector<int> nextRow(triangle[n-1]);
        for(int i = n-2; i >= 0; i--)
        {
            for(int j = 0; j < i + 1; j++) 
            {
                int lowerLeft = triangle[i][j] + nextRow[j];
                int lowerRight = triangle[i][j] + nextRow[j + 1];
                currRow[j] = min(lowerLeft, lowerRight);
            }
            swap(currRow, nextRow);
        }
        return nextRow[0];  //as we swapped at last iteration
    }
};