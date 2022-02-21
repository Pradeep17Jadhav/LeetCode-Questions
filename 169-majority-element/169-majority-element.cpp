class Solution {
public:
    //Moore's Voting Algorithm
    int majorityElement(vector<int>& nums) {
        int major = nums[0]; // consider first number as major
        int count = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == major) //increment counter for all numbers equal to major
                count++;
            else if(!--count) // decrement counter for all number unequal to major
            {
                major = nums[i]; // when counter becomes zero, change the major to current.
                count++; // reset count to 1 for new major;
            }   
        }
        return major;
    }
};