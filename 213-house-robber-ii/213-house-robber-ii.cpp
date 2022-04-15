class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        
        //since the last element and first element are always connected,
        //the answer either considers first element or the last elements
        //so we find max value considering both case, i.e. with 1st element and with last element and return the max of both
        //to consider first element, find ans from 0th index to (n-1)th index
        //to consider last element, find ans from 1st index to nth index
        
        return max(rob_1(nums, 0, n-1), rob_1(nums, 1, n));
    }
    
    //TC: O(N)
    //SC: O(1)
    int rob_1(vector<int>& nums, int start, int end) {
        int a, b, c;
        a = b = 0;
        
        for(int i = start; i < end; i++) {
            c = max(a + nums[i], b);
            a = b;
            b = c;
        }
        return b;
    }
};