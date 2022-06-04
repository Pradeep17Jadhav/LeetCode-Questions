class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        return permute_1(nums);
        // return permute_2(nums);
    }
    
    vector<vector<int>> permute_1(vector<int>& nums) {
        vector<vector<int>> res;
        permutation(res, nums, 0);
        return res;
    }
    
    void permutation(vector<vector<int>> &res, vector<int> &nums, int i) {
        if(i == nums.size()) {
            res.push_back(nums);
            return;
        }
        for(int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]); //for each element on RHS, swap it with curr ith element to keep it ith position
            permutation(res, nums, i+1);
            swap(nums[j], nums[i]); //backtrack
        }
    }
    
    vector<vector<int>> permute_2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> curr = nums;
        int n = nums.size();

        int fact = 1;
        //O(N)
        for(int i = n; i > 0; i--)
        {
            fact *= i;
        }
        
        for(int x = 0; x < fact; x++)
        {
            res.push_back(curr);
            if(res.size() == fact)
            {
                break;
            }

            int breakdown = -1;
            for(int i = n - 1; i > 0; i--)
            {
                if(curr[i - 1] < curr[i])
                {
                    breakdown = i - 1;
                    break;
                }
            }

            for(int i = n - 1; i >= 0; i--)
            {
                if(curr[i] > curr[breakdown])
                {
                    swap(curr[i], curr[breakdown]);
                    reverse(curr.begin() + breakdown + 1, curr.end());
                    break;
                }
            }
        }
        return res;
    }
};