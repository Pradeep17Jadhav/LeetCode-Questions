class NumMatrix {
public:
    vector<vector<int>> mat;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        mat = vector<vector<int>>(m+1, vector<int>(n+1)); 
        
        //Set mat[i][j] as a sum of all elements inside the rectangle [0,0,i,j]
        for(int i = 1; i <= m; i++) 
        {
            for (int j = 1; j <= n; j++) 
            {
                mat[i][j] = mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1] + matrix[i - 1][j - 1];
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
    int sumRegion(int r1, int c1, int r2, int c2) {
		// Since our 'mat' starts by 1 so we need to increase r1, c1, r2, c2 by 1
        r1++; c1++; r2++; c2++; 
        return mat[r2][c2] - mat[r2][c1 - 1] - mat[r1 - 1][c2] + mat[r1 - 1][c1 - 1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */