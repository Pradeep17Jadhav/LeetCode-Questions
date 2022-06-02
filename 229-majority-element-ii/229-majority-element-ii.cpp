class Solution {
public:    
    //Sol 1 - BruteForce
    //TC: O(N^2)
    //SC: O(1)
    //Start iterating all elements on by one. for each element,
    //iterate the whole array again and check how many time the number has occured.
    //at max there can be 2 majority elements. make sure that they are unique
       
    //Sol 2 - Hashmap
    //TC: O(N)
    //SC: O(N)
    //Start iterating all elements on by one.
    //Check the num is in hashmap, if yes then increment count. if no then init it with count 1
    //at the end, from the hashmap check which numbers appear more than floor(n/3) times 

    //Sol 3 - Boyer-Moore Majority Vote algorithm - VVIMP
    //Take 2 variables and their counters. Init them with first two unique numbers while traversing.
    //Increment count if same numbers are repeated while traversing.
    //Decrement count if number is not repeated
    //If count becomes 0, reinitialized the variable with current number. repeat for whole array.
    //TC: O(N)
    //SC: O(1)
    vector<int> majorityElement(vector<int>& nums) {
        int n1, n2, count1, count2;
        n1 = n2 = -1;
        count1 = count2 = 0;
        int size = nums.size();
        
        for(int i = 0; i < size; i++) {
            if(n1 == nums[i])
                count1++;
            else if(n2 == nums[i])
                count2++;
            else if(count1 == 0) {
                n1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0) {
                n2 = nums[i];
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }
        
        //It is not guaranteed that there are exactly 2 elements are repeated more than n/3 times
        //There may be only one number which satisfies the given condition
        //So we need to verify that both the numbers are repeated 1/3 times
        vector<int> res;
        count1 = count2 = 0;
        for(int i = 0; i < size; i++) {
            if(nums[i] == n1)
                count1++;
            else if(nums[i] == n2)
                count2++;
        }
        if(count1 > size/3)
            res.push_back(n1);
        if(count2 > size/3)
            res.push_back(n2);
        
        return res;
    }
};