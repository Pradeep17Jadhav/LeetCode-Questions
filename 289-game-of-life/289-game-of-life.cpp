class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> temp = board;
        
        for(int i = 0; i < m; i++) 
        {
            for(int j = 0; j < n; j++) 
            {
                int live = 0;
                if(i-1 >= 0) //if column above current column exists
                {
                    live += j-1 >= 0 ? temp[i-1][j-1] : 0; //if left column exists
                    live += temp[i-1][j];                  //current column
                    live += j+1 < n ? temp[i-1][j+1] : 0;  //if next column exists
                }
                
                //current column
                live += j-1 >= 0 ? temp[i][j-1] : 0;
                live += j+1 < n ? temp[i][j+1] : 0;
                
                if(i+1 < m) //if column below current column exists
                {
                    live += j-1 >= 0 ? temp[i+1][j-1] : 0;
                    live += temp[i+1][j];
                    live += j+1 < n ? temp[i+1][j+1] : 0;
                }

                if(temp[i][j]) // live
                    board[i][j] = (live < 2 || live > 3) ? 0 : 1;
                else if(live == 3)
                    board[i][j] = 1;
            }
        }
    }
};