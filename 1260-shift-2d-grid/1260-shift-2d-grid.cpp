class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        int x, y, newX, newY;
        
        //treate the matrix as an array
        //iterate over alll elements for use size of any array inside grid matrix to find row and column
        for(int i = 0; i < m*n; i++) {
            y = i / n; //current y index for row
            x = i % n; //current x index for column
            
            newX = (x + k) % n; //new X (column)
            newY = (y + ((x + k) / n)) % m; //new Y (row)
            res[newY][newX] = grid[y][x]; // fill the new answer array
        }
        
        return res;
    }
};

//Explanations:
//to find new column::
//to find new X, we can add k in current x and take mod of the whole value to get new 0-indexed X 
//example, size of ith array n=5, x=2 and k=4
//so the newX = (2+4)%6 = 0 i.e. 0th index of new row. we do not care about row in this statement.
//--> newX = (x + k) % n;


//to find new row::
//new row = current row + number of rows we need to move down
//to find number of rows we need to move down, we can use (current column + k) / number of elements in each row i.e. -> (x + k) / n.
//we add this value to current row count so we get new row count = y + ((x + k) / n)
//now it may happen that we moved out of last row and there is no more rows to add. in this case we should start from begining of the matrix
//so we take remainder of new row by number of rows
//so newY = (new row count) % m;
//--> newY = (y + ((x + k) / n)) % m;