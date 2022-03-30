class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0; //pointer for current row
        int col = matrix[0].size()-1; //pointer for current col

        //we take advantage of both rows and columns are sorted.
        //we will start from top right corner as current position
        //this can also be done by starting at bottom right
        //TC: O(m+n) as we move by one row or one column at a time till the end
        while(row < matrix.size() && col >= 0)
        {
            //if target>curr element, it cannot be present in current row as row is sorted so move to next row
            if(target > matrix[row][col]) 
                row++;
            
            //if target<curr element, it cannot be present in current colmn as col is sorted, so go to col on left
            else if(target < matrix[row][col])
                col--;
            else
                return true;
        }
        return false;
    }
};