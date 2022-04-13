class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {  
        return generateMatrixSolution1(n);
        // return generateMatrixSolution2(n);
    }
        
    vector<vector<int>> generateMatrixSolution1(int n) {
        int rs = 0; //row start
        int re = n-1; //row end
        int cs = 0; //column start
        int ce = n-1; //column end
        int curr = 1;
        vector<vector<int>> res(n, vector<int>(n, 0)); //create n*n matrix with initial value 0

        while(rs <= re && cs <= ce)
        {
            for(int j = cs; j <= ce; j++) //from column start to column end
                res[rs][j] = curr++;
            
            for(int i = rs+1; i <= re; i++) //from row start to row end
                res[i][ce] = curr++;
            
            for(int j = ce-1; j >= cs; j--) //from column end to column start
                res[re][j] = curr++;
            
            for(int i = re-1; i > rs; i--) //from row end to row start
                res[i][cs] = curr++;
            
            cs++;
            ce--;
            rs++;
            re--;
        }
        return res;
    }

    vector<vector<int>> generateMatrixSolution2(int n) {
        if(n == 1) return {{1}};
        int curr = 1;
        int i = 0;
        int j = 0;
        vector<vector<int>> res(n, vector<int>(n, 0)); //create n*n matrix with initial value 0
        int dir = 1; //1-right, 2-down, 3-left and 4-up
        
        while(res[i][j] == 0)
        {
            //left to right
            while(res[i][j] == 0){
                res[i][j] = curr++;
                if(j < n-1 && res[i][j+1] == 0)
                    j++;
                else
                    dir = 2;
            }
            i++; //move to next row

            //top to bottom
            while(res[i][j] == 0){
                res[i][j] = curr++;
                if(i < n-1 && res[i+1][j] == 0)
                    i++;
                else
                    dir = 3;
            }
            j--; //move to prev column

            //right to left
            while(res[i][j] == 0){
                res[i][j] = curr++;
                if(j > 0 && res[i][j-1] == 0)
                    j--;
                else
                    dir = 4;
            }
            i--; //move to prev row

            //bottom to top
            while(res[i][j] == 0){
                res[i][j] = curr++;
                if(i > 0 && res[i-1][j] == 0)
                    i--;
                else
                    dir = 1;
            }
            j++; //move to next column
        }
        return res;
    }
};