//reference - https://www.youtube.com/watch?v=REOH22Xwdkk
//backtracking recursive solution ->

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        find(nums, 0, vector<int>{});
        return res;
    }

    //Time complexity - O(n.2^n)
    //For N numbers, we have 2^n possibilities
    void find(vector<int> &nums, int index, vector<int>temp)
    {
        if(index == nums.size())
        {
            res.push_back(temp);
            return;
        }
        
        find(nums, index + 1, temp); // not to include nums[i]
        temp.push_back(nums[index]);
        find(nums, index + 1, temp); // to include nums[i]
    }
};