class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // usingExtraSpace(board);
        inplace(board); //better space
    }

    //For this inplace solution, each cell has values either 0 or 1, but instead of using bool datatype we have int data type for cells.
    //We will take advantage of int. We will introduce two new values:: 2-newly dead, 3-newly alive
    //If a cell dies, we will assign value 2 (instead of 0) to it. Similarly if a cell becomes alive we will mark it 3 (instead of 1)
    
    //Divide the solution in three parts:
    //1 - Find the alives cells around current cell, for all cells
    //2 - Change the value of current cell accd to conditions given in problem statement.
    //3 - Change all the values to 0 or 1, once we iterate the whole matrix
    
    //PART 1:: To find sum of live cells, we by-default will count '1' value. 
    //But along with it, we will also count '2'; which is newly dead in result but it is still alive in the question matrix.
    //PART 2:: We will mark newly alive cells as 3 so it will not interfere with the alive neighbor counts for remaining cells.
    //We will also mark newly dead cells as 2, so that we can still consider them for counting alive neighbors
    //PART 3:: After traversing and updating all cells, we can simply convert all values back to 0s and 1s as a final answer.
    
    
    //TC: O(2N), one pass for editing the values inplace, one pass to change the values to 0/1
    //SC: O(1), no extra space used
    void inplace(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i < m; i++) 
        {
            for(int j = 0; j < n; j++) 
            {
                int live = 0;
                if(i-1 >= 0) //if column above current column exists
                {
                    if(j-1 >= 0 && (board[i-1][j-1] == 1 || board[i-1][j-1] == 2)) //if j-1 exists and curr cell is alive or newly dead
                        live++;
    
                    if(board[i-1][j] == 1 || board[i-1][j] == 2) //if curr cell is alive or newly dead
                        live++;
                    
                    if(j+1 < n && (board[i-1][j+1] == 1 || board[i-1][j+1] == 2)) //if j+1 exists and curr cell is alive or newly dead
                        live++;
                }
                
                if(j-1 >= 0 && (board[i][j-1] == 1 ||  board[i][j-1] == 2)) //if j-1 exists and curr cell is alive or newly dead
                    live++;
                if(j+1 < n && (board[i][j+1] == 1 ||  board[i][j+1] == 2)) //if j+1 exists and curr cell is alive or newly dead
                    live++;
                
                if(i+1 < m) 
                {
                    if(j-1 >= 0 && (board[i+1][j-1] == 1 ||  board[i+1][j-1] == 2)) //if j-1 exists and curr cell is alive or newly dead
                        live++;

                    if(board[i+1][j] == 1 || board[i+1][j] == 2) //if curr cell is alive or newly dead
                        live++;
                    
                    if(j+1 < n && (board[i+1][j+1] == 1 ||  board[i+1][j+1] == 2)) //if j+1 exists and curr cell is alive or newly dead
                        live++;
                }

                if(board[i][j] == 1) //currently alive
                {
                    if(live < 2 || live > 3)
                         board[i][j] = 2; //mark as newly dead
                }
                else if(live == 3) //currently dead and has 3 alive neighbors
                    board[i][j] = 3; //mark as newly alive
            }
        }
        
        //revert all 0,1,2,3 values to 1s and 2s       
        for(int i = 0; i < m; i++) 
        {
            for(int j = 0; j < n; j++) 
            {
                board[i][j] = board[i][j] % 2; //change 0,2 to 0 and 1,3 to 1
            }
        }
    }


    //TC: O(N), if we skip the time to copy the array
    //SC: O(N), linear extra space for temp matrix
    void usingExtraSpace(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> temp = board;
        
        for(int i = 0; i < m; i++) 
        {
            for(int j = 0; j < n; j++) 
            {
                int live = 0;
                if(i-1 >= 0) //if row above current row exists
                {
                    live += j-1 >= 0 ? temp[i-1][j-1] : 0; //if left column exists
                    live += temp[i-1][j];                  //current column
                    live += j+1 < n ? temp[i-1][j+1] : 0;  //if next column exists
                }
                
                //current row
                live += j-1 >= 0 ? temp[i][j-1] : 0;
                live += j+1 < n ? temp[i][j+1] : 0;
                
                if(i+1 < m) //if row below current row exists
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