class Solution {
public:
    //Imagine Pascal's Triangle like a pattern
    // 1
    // 1    1
    // 1    2    1
    // 1    3    3     1
    // 1    4    6     4    1
    // 1    5    10    10   5   1
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;       
        
        for(int i = 0; i < numRows; i++)
        {
            vector<int> row(i+1, 1); //create array of i+1 length, fill with 1's
            
            //Use previous row of res to find current row's jth element
            for(int j = 1; j < i; j++)
                row[j] = res[i-1][j-1] + res[i-1][j];
            
            res.push_back(row);
        }

        return res;
    }
};