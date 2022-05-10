class Solution {
public:
    vector<vector<int>> res;
    
    //similar to Combination Sum 1
    vector<vector<int>> combinationSum3(int k, int n) {
        res.clear();
        vector<int> temp;
        solve(1, k, n, temp); //start with int 1
        return res;
    }
    
    void solve(int i, int k, int n, vector<int> &temp) {
        //if all 'k' numbers are used up and also the required sum is met, add to the result
        if(n == 0 & k == 0) {
            res.push_back(temp);
            return;
        }
        
        if(i > 9 || n == 0 || k == 0)
            return;

        //try adding all numbers from current i to 9
        for(int j = i; j <= 9; j++) 
        {
            temp.push_back(j);
            solve(j+1, k-1, n-j, temp);
            temp.pop_back();
        }
        
    }
};