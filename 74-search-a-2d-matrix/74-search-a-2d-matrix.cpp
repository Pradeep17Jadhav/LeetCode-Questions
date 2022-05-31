class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return searchMatrix1(matrix, target);
        // return searchMatrix2(matrix, target);
    }
    
    //TC: O(logn)
    //Since all rows are sorted and last element of each row is less than first element of next row,
    //it can be treated as a single sorted array. So binary search over the array is possible.
    bool searchMatrix1(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int left = 0;
        int right = rows * cols - 1; //it may overflow for very large values of m and n
        int mid, element;

        while(left <= right)
        {
            mid = (left+right)/2;
            element = matrix[mid / cols][mid % cols]; //check note at bottom for explanation
            if(target == element)
                return true;
            else if(target < element)
                right = mid-1;
            else
                left = mid+1;
        }
        return false;
        
        //Meaning of matrix[mid / cols][mid % cols] ::
        //Let there are total 500 elements: 1 2 3 .... 249 250 251 .... 499 500
        //Mid is 250, to find row in which mid lies, we can divide it by number of elements each row has
        //Suppose each row has 70 elements, then it must be in 4th row, i.e. 250/70=3. Here 3 is index (4th row)
        //Now, to find the column, we can take mod of mid with number of elements in a row,
        //250%70=40, so answer is on 40th index of the row
    }
    
    //TC: O(rows * logn)
    //O(row.size()) for rows - checking last element of each row 
    //O(logn) for column - if a row having match is found, using binary search
    bool searchMatrix2(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix[0].size()-1;
        int mid;
        for(auto &arr: matrix)
        {
            if(target <= arr[r])
            {
                while(l <= r)
                {
                    mid = (l+r)/2;
                    if(target == arr[mid])
                        return true;
                    else if(target < arr[mid])
                        r = mid-1;
                    else
                        l = mid+1;
                }
                return false;
            }
        }
        return false;
    }
};