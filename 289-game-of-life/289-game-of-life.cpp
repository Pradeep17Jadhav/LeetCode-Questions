class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++) 
        {
            for(int j = 0; j < n; j++) 
            {
                int live = 0;
                if(i-1 >= 0) 
                {
                    if(j-1 >= 0)
                        live += board[i-1][j-1];
                    
                    live += board[i-1][j];
                    
                    if(j+1 < n)
                        live += board[i-1][j+1];
                }
                
                if(j-1 >= 0)
                    live += board[i][j-1];
                if(j+1 < n)
                    live += board[i][j+1];
                
                if(i+1 < m) 
                {
                    if(j-1 >= 0)
                        live += board[i+1][j-1];
                    
                    live += board[i+1][j];
                    
                    if(j+1 < n)
                        live += board[i+1][j+1];
                }

                if(board[i][j]) // live
                {
                    res[i][j] = (live < 2 || live > 3) ? 0 : 1;
                }
                else if(live == 3)
                    res[i][j] = 1;
            }
        }
        board = res;
    }
};