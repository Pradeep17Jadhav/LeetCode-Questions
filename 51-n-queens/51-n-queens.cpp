class Solution {
public:
    //Solution 1
    vector<vector<string>> solveNQueens(int n) {
        return Solution1(n);
    }
    
    vector<vector<string>> Solution1(int n) {
        vector<vector<string>> res;
        vector<string> board;
        string s(n, '.'); //string of n '.' chars
        for(int i = 0; i < n; i++) //fill board with strings of all dots
            board.push_back(s);
        
        solve(res, board, 0, n);
        return res;
    }
    
    
    void solve(vector<vector<string>> &res, vector<string> &board, int row, int n) {
        if(row == n) {
            res.push_back(board);
            return;
        }
        
        //for all columns in current row
        for(int col = 0; col < n; col++) {
            if(isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                solve(res, board, row+1, n);
                board[row][col] = '.'; //backtrack
            }
        }
    }
    
    bool isSafe(vector<string> &board, int row, int col, int n) {
        int currRow = row - 1;
        int currCol = col - 1;
        
        //check top-left direction
        while(currRow >= 0 && currCol >= 0) {
            if(board[currRow][currCol] == 'Q')
                return false;
            currRow--;
            currCol--;
        }
        
        //check top direction
        currRow = row - 1;
        while(currRow >= 0) {
            if(board[currRow][col] == 'Q')
                return false;
            currRow--;
        }
        
        //check top-right direction
        currRow = row - 1;
        currCol = col + 1;
        while(currRow >= 0 && currCol < n) {
            if(board[currRow][currCol] == 'Q')
                return false;
            currRow--;
            currCol++;
        }

        return true;
    }
};