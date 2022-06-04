class Solution {
public:
    //Solution 1 - (Check solution 2 for more optimization in interview)
    vector<vector<string>> solveNQueens(int n) {
        // return Solution1(n);
        return Solution2(n);
    }
    
    vector<vector<string>> Solution1(int n) {
        vector<vector<string>> res;
        vector<string> board;
        string s(n, '.'); //string of n '.' chars
        for(int i = 0; i < n; i++) //fill board with strings of all dots
            board.push_back(s);
        
        solve_Solution1(res, board, 0, n);
        return res;
    }
    
    //TC: O(N! * N)
    //SC: O(N^2)
    void solve_Solution1(vector<vector<string>> &res, vector<string> &board, int row, int n) {
        if(row == n) {
            res.push_back(board);
            return;
        }
        
        //for all columns in current row
        for(int col = 0; col < n; col++) {
            if(isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                solve_Solution1(res, board, row+1, n);
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
    
    
    //////////////////////////////////////
    
    //Instead of using isSafe having 3 for loops, to check that no two queens attack each other,
    //We can use 3 hash to check the attacks
    //This will increase SC by (2n-1) but decrease the nested TC
    //Check notes for explanation
    vector<vector<string>> Solution2(int n) {
        vector<vector<string>> res;
        vector<string> board;
        string s(n, '.'); //string of n '.' chars
        for(int i = 0; i < n; i++) //fill board with strings of all dots
            board.push_back(s);
        
        vector<bool>topRow(n, false); //hash to check which column already has a queen
        vector<bool>topRightDiagonal((2*n)-1, false); //hash to check if top-right diagonal has queens
        vector<bool>topLeftDiagonal((2*n)-1, false); //hash to check if top-left diagonal has queens
        
        solve_Solution2(res, board, 0, n, topRow, topRightDiagonal, topLeftDiagonal);
        return res;
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