class NumMatrix {
public:
    vector<vector<int>> mat;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        mat = matrix; 
        
        //find prefix sum of all the columns in each row
        for(int i = 0; i < m; i++) {
            for(int j = 1; j < n; j++) {
                mat[i][j] = mat[i][j] + mat[i][j-1];
            }
        }
        
        //find prefix sum of all the rows in each column
        for(int i = 1; i < m; i++) {
            for(int j = 0; j < n; j++) { 
                mat[i][j] = mat[i][j] + mat[i-1][j];
            }
        }
    }
    int sumRegion(int r1, int c1, int r2, int c2) {
        int total = mat[r2][c2]; //bottom right of each rect will have sum of all elements from (0,0) to (r2,c2)
        int topExtra = r1 == 0 ? 0 : mat[r1-1][c2]; //sum of all elements above the rect is stored in (r1-1, c2)
        int leftExtra = c1 == 0 ? 0 : mat[r2][c1-1]; //sum of all elements on LHS of rect is stored in (r2, c1-1)
        int overlapping = c1 != 0 && r1 != 0 ? mat[r1-1][c1-1] : 0; //as we consider both above & left elements, some part is counted twice
        return total - (topExtra + leftExtra - overlapping);
    }
};