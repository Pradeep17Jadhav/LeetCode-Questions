class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int res = 1;
        int row = grid.size();
        int col = grid[0].size();
        if (row == 0 || col == 0) return -1;
        if (grid[0][0] != 0 | grid[row-1][col-1] != 0) return -1; //first and last cell should not be 1

        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        vector<vector<int>> directions = {{1, 1}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}};
        grid[0][0] = 1; //first cell of the path

        while(!q.empty())
        {
            pair curr = q.front();
            int x = curr.first;
            int y = curr.second;
            if(x == row-1 && y == col-1) 
                return grid[x][y]; //reached the final destination

            for(auto direction : directions)
            {
                //traverse the 8 directions
                int newX = x + direction[0];
                int newY = y + direction[1];
                
                //the index exists and value is still 0, i.e. unvisited cell    
                if(newX >= 0 && newX < row && newY >= 0 && newY < col && grid[newX][newY] == 0) 
                {
                    q.push(make_pair(newX, newY));
                    grid[newX][newY] = grid[x][y]+1; //mark as next step, so increase the count of the path
                }
            }
            q.pop();
        }
        return -1;
    }
};