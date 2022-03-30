class Solution {
public:
    //TC: O(nlogn)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
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