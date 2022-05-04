class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
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