class Solution {
public:
    //Similar to Permutations I
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); //sort to bring duplicates in adjecent position
        vector<vector<int>> res;
        permute(res, nums, 0);
        return res;
    }

    void permute(vector<vector<int>> &res, vector<int> &nums, int pos) {
        if(pos == nums.size()) {
            res.push_back(nums);
            return;
        }
        for(int i = pos; i < nums.size(); i++) {
            if(i > pos && nums[i] == nums[pos]) //ignore duplicates by checking previous value
                continue;
            swap(nums[pos], nums[i]);
            permute(res, nums, pos+1);
        }
        //backtrack (cannot backtrack immediately to maintain the sorted ordered for the rest of the array)
        for (int i = nums.size() - 1; i > pos; --i) 
            swap(nums[pos], nums[i]);
    }
};


// [1,1,2]
// [1,2,3]
// [1]
// [-6,-5,0,4,-10,8,6]
// [1,1,1]
// [1,2,3,1,2,3]
// [-1,-2,-5,-8,-5,1,-10]
// [-1,-1,5,0,0,8,5,-1]