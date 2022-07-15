class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++)  {
            for(int j = 0; j < m; j++) {
                if(grid[i][j]) 
                    ans = max(ans, traverse(grid, i, j, m, n));
            }
        }
        return ans;
    }
    int traverse(vector<vector<int>> &grid, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= n || j >= m || !grid[i][j])
            return 0;

        grid[i][j] = 0;
        return (
            1 + traverse(grid, i-1, j, m, n) + traverse(grid, i, j-1, m, n) + 
            traverse(grid, i+1, j, m, n) + traverse(grid, i, j+1, m, n)
        );
    }
};