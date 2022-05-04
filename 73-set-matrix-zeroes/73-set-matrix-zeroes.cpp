class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        setZeroes_1(matrix);
    }
    
    //TC: O(2N) = O(N)
    //SC: O(1)
    void setZeroes_1(vector<vector<int>>& matrix) {
        bool col0 = false; //using variable for column state, as matrix[0][0] can only be used for rows or cols (using it for rows)
        for(int i = 0; i < matrix.size(); i++)
        {
            if(matrix[i][0] == 0) //if any cell in 0th row is 0, mark as true;
                col0 = true;
            for(int j = 1; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0)
                    matrix[0][j] = matrix[i][0] = 0; //use 0th row and 0th col to save states instead of using new arrays
            }
        }
        
        for(int i = matrix.size()-1; i >= 0; i--)
        {
            for(int j = matrix[0].size()-1; j > 0; j--)
            {
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            } 
            if(col0)
                matrix[i][0] = 0;
        }
    }
    
    //TC: O(2N) = O(N)
    //SC: O(rows+cols)
    void setZeroes_2(vector<vector<int>>& matrix) {
        vector<bool> rows(matrix.size(), true);
        vector<bool> cols(matrix[0].size(), true);
        
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0)
                {
                    if(rows[i]) rows[i] = false;
                    if(cols[j]) cols[j] = false;

                }
            }
        }
        
        for(int i = 0; i < matrix.size(); i++)
        {
            if(!rows[i])
            {
                for(int j = 0; j < matrix[0].size(); j++)
                    matrix[i][j] = 0;
            }
            else
            {
                for(int j = 0; j < matrix[0].size(); j++)
                {
                    if(!cols[j])
                        matrix[i][j] = 0;
                } 
            }
        }
    }
};