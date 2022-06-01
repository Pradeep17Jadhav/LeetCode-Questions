class Solution {
public:
    //Moore's Voting Algorithm
    //TC: O(N)
    //SC: O(1)
    int majorityElement(vector<int>& nums) {
        int major = nums[0]; // consider first number as major
        int count = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == major) //increment counter for all numbers equal to major
                count++;
            else // decrement counter for all number unequal to major
                count--; 
            
            if(count == 0) {
                major = nums[i]; // when counter becomes zero, change the major to current element.
                count = 1; // reset count to 1 for new major;
            }   
        }
        return major;
    }
};