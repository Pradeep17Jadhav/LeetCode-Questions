class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // return findDuplicateBySorting(nums);
        return findDuplicateByMarkingVisited(nums);
    }

    int findDuplicateBySorting(vector<int>&nums)
    {
        //O(NlogN) using sort
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 1; i++)
        {
            if(nums[i] == nums[i + 1])
                return nums[i];
        }
        return -1;
    }
    
    int findDuplicateByMarkingVisited(vector<int>&nums)
    {
        //O(N) using negative marking AND MODIFYING ORIGINAL ARRAY
        //since all the numbers in array is in range [1, n], then are guaranteed to be positive
        //so we will mark each visited index by multiplying by -1 so it will become less than 0;
        //then we will check if the number is less than 0 or not. 
        //if it is positive, it must be visited twice, and returned as an answer.
        int n = nums.size();
        int index = 0;

        for(int i = 0; i < n; i++)
        {
            index = abs(nums[i]);
            nums[index] *= -1;
            if(nums[index] > 0)
                return abs(nums[i]);
        }
        return -1;

    }
};
