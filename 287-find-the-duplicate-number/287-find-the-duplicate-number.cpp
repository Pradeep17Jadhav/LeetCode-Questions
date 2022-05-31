class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // return findDuplicateBySorting(nums);
        // return findDuplicateByMarkingVisited(nums);
        return findDuplicateByCycle(nums);
    }
    
    
    //Linked List Floyed Cycle Detection Method
    //Since there is a duplicate number, it will form a cycle at that duplicate number
    //So we can use floyed cycle detection algo to find the starting point of cycle
    //Ex ---- [2, 5, 8, 6, 9, 3, 8, 7, 1]
    //index - [0, 1, 2, 3, 4, 5, 6, 7, 8]
    //tranversal ->
    //--------[2, 8, 1, 5, 3, 6, 8, 1, 5, 3, 6, 8, 1, 5, 3, 6, 8,........]
    //A cycle is formed from the duplicate number, so we need to find the point from where cycle starts
    //TC: O(N)
    //SC: O(1)
    int findDuplicateByCycle(vector<int>&nums)
    {
        int slow = nums[0];
        int fast = nums[0];
        
        //move fast 2 steps, slow 1 step unit values of both are same
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);
        
        //start fast from initial point again
        fast = nums[0];
        
        //move both pointers by one step. they will collide at duplicate number
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
    
    
    //Cannot be used here as we need to modify the original array
    //TC: O(N)
    //SC: O(1)
    int findDuplicateByMarkingVisited(vector<int>&nums)
    {
        //using negative marking AND MODIFYING ORIGINAL ARRAY
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
    
    
    //Cannot be used here as sort will modify the original array
    //TC: O(NlogN) - Brute Force
    //SC: O(1)
    int findDuplicateBySorting(vector<int>&nums)
    {
        //
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 1; i++)
        {
            if(nums[i] == nums[i + 1])
                return nums[i];
        }
        return -1;
    }
};
