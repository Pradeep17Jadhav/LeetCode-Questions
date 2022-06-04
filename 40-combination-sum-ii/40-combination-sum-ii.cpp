class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        findCombination(candidates, res, temp, target, 0);
        return res;
    }
    
    void findCombination(vector<int>& candidates, vector<vector<int>> &res, vector<int> &temp, int target, int i) {
        if(target == 0) {
            res.push_back(temp);
            return;
        }
        
        //in this loop, we will one by one pick numbers from candidates[i] to candidates[n-1]
        //add them to the temp array and recursively follow procedure to the next i
        for(int j = i; j < candidates.size(); j++) {
            //since array is sorted, if curr becomes > target, all next elements will also be greater than target
            if(candidates[j] > target) break;
            
            //if value of j is equal to value of j-1, it means its a duplicate. 
            //we already processed jth number at ith index
            //ex - [0,1,2,3,3,3,4], i = 3, j = 3
            //Here we will find combination [0,1,2,3,x,x,x....] in a next recursive call
            //but when we make j=4, it will again make current array as [0,1,2,3,x,x,x,...]
            //same for j=5, curr array may become [0,1,2,3,x,x,x...]
            //so we skip the duplicates in loop
            //then for j=6, array will become [0,1,2,4,x,x,x,...]
            //for j==i, its a brand new ith index so here duplicates in 'candidates' array are acceptable
            if(j > i && candidates[j] == candidates[j-1]) continue;
            
            temp.push_back(candidates[j]);
            
            //cannot repeat same index so increment j, also update target
            findCombination(candidates, res, temp, target-candidates[j], j+1); 
            
            //backtrack
            temp.pop_back();
        }
    }
};