class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // return Solution_1(nums, x);
        return Solution_2(nums, x);
    }
    
    //Sliding Window
    //We need to remove left or right elements till we exhause X
    //At the end we will be left with (sum of total array - X)
    //So the sum of remaining subarray will be (total sum - x)
    //We need to minimize the number of removal, so, we have to maximize remaining subarray of sum (total sum - x)
    //We can find this subarray using sliding window
    //TC: O(N)
    //SC: O(1)
    int Solution_2(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        
        for(int &i: nums)
            sum += i;
        
        //find the sum of remaining subarray (total sum - x)
        int desiredSum = sum - x;
        if(desiredSum == 0) //whole array sums to x so need to remove all elements
            return nums.size();
        
        int left = 0;
        int right = 0;
        int currSum = 0;
        int length = 0;
        for(; right < n; right++) {
            currSum += nums[right];
            
            //if subarray exceeds desired sum, reduce the window
            while(currSum > desiredSum && left <= right) {
                currSum -= nums[left];
                left++;
            }
            
            if(currSum == desiredSum)
                length = max(length, right - left + 1);
        }
        
        return length == 0 ? -1 : n-length;
    }
    
    //TLE - Do Not Use
    int Solution_1(vector<int>& nums, int x) {
        int minCount = INT_MAX;
        bool find = recursion_solution1(nums, x, 0, minCount, 0, nums.size()-1);
        return find ? minCount : -1;
    }
    
    bool recursion_solution1(vector<int>& nums, int x, int count, int &minCount, int left, int right) {        
        if(x == 0) {
            minCount = min(minCount, count);
            return true;
        }
        
        if(x < 0 || left > right)
            return false;

        int travLeft = recursion_solution1(nums, x-nums[left], count+1, minCount, left+1, right);
        bool travRight = recursion_solution1(nums, x-nums[right], count+1, minCount, left, right-1);
        return travLeft || travRight;     
    }
};