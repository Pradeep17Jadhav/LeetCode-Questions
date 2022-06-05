class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board;
        string s(n, '.'); //string of n '.' chars
        for(int i = 0; i < n; i++) //fill board with strings of all dots
            board.push_back(s);
        
        vector<bool>topRow(n, false); //hash to check which column already has a queen
        vector<bool>topRightDiagonal((2*n)-1, false); //hash to check if top-right diagonal has queens
        vector<bool>topLeftDiagonal((2*n)-1, false); //hash to check if top-left diagonal has queens
        
        solve_Solution2(res, board, 0, n, topRow, topRightDiagonal, topLeftDiagonal);
        return res.size();
    }
    
    void solve_Solution2(vector<vector<string>> &res, vector<string> &board, int row, int n, vector<bool> &topRow, vector<bool> &topRightDiagonal, vector<bool> &topLeftDiagonal) {
        if(row == n) {
            res.push_back(board);
            return;
        }
        
        //for all columns in current row
        for(int col = 0; col < n; col++) {
            if(topRow[col] == false && //col should not contain queen
               topLeftDiagonal[row + col] == false && //topLeftDiagonal should not contain queen
               topRightDiagonal[(n-1) + col - row] == false)  //topRightDiagonal should not contain queen
            {
                    topRow[col] = true;
                    topLeftDiagonal[row + col] = true;
                    topRightDiagonal[(n-1) + col - row] = true;
                    
                    board[row][col] = 'Q';
                    solve_Solution2(res, board, row+1, n, topRow, topRightDiagonal, topLeftDiagonal);
                
                    //backtrack
                    board[row][col] = '.';
                    topRow[col] = false;
                    topLeftDiagonal[row + col] = false;
                    topRightDiagonal[(n-1) + col - row] = false;
            }
        }
    }
};