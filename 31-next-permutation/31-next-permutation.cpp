class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //Ex - [1,2,4,3,3,2], Ans - [1,3,2,2,3,4]
        //Treat the array as a number 124332. We have to find the next number which is greater than current number
        //having all digits of current number. 
        //There can be multiple permutations possible, like 142332, 412332, etc.
        //but the answer is the one having smallest value as digit i.e. 132234 in this case
        
        int breakdown = -1;
        //find the first number from right, which is less than the number on its right
        for(int i = nums.size() - 1; i > 0; i--)
        {
            if(nums[i - 1] < nums[i])
            {
                breakdown = i - 1;
                break;
            }
        }
        
        if(breakdown == -1) //breakdown number not found, so the answer is reversed array
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        //if breakdown point is found
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            //for each point from right, check if its is greater than breakpoint because thats the point where 
            //the digit is not sorted and there only we can swap to find next permutation.
            //if the point is greater than the breakdown point, swap them.
            //After swapping, we reverse the part on RHS of breakdown to make is ascending sorted
            // [1,2,4,3,3,2] will be iterated as for breakdown at 1st index:
            // i=4, swap - [1,3,4,3,2,2], reverse - [1,3,2,2,3,4]
            if(nums[i] > nums[breakdown])
            {
                swap(nums[i], nums[breakdown]);
                reverse(nums.begin() + breakdown + 1, nums.end());
                break;
            }
        }
    }
};