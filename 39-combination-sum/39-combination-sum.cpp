class Solution {
public:
    vector<vector<int>> res; // 2D vector to store answer
    void solve(int i, vector<int>& arr, vector<int>& temp, int target)
    {
        // if target becomes zero at any point, we have find a possible combination
        if(target == 0) 
        {
            res.push_back(temp);
            return;
        }

        // if target becomes < 0 or >size, then it is not possible to have ans
        if(target < 0 || i == arr.size())
            return;

        
        //for every element we have two choices either to include in answer or not to include in answer. 
        //first we do not take the ith element
        //so without decreasing sum we will move to next index because it will not contribute in making our sum
        solve(i + 1, arr, temp, target);
        
        // we are taking the ith element and not moving onto the next element because
        //it may be possible that this element again contribute in making our sum. 
        temp.push_back(arr[i]); // including ith element
        
        //we should decrease our target sum as we are considering that this will help us in
        //making our target sum, and call again function
        solve(i, arr, temp, target - arr[i]); 
        temp.pop_back(); // backtrack - remove the added element as not required anymore
        
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        res.clear(); // clear global array, make to sure that no garbage value is present in it
        
        vector<int> temp; // temporary vector that tries all possible combination
        
        solve(0, arr, temp, target); // calling function, and see we start from index zero
        
        return res; // finally return the answer array
    }
};