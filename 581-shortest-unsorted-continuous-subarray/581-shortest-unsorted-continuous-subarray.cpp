class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = nums.size() - 1;
        int end = -1;
        int temp = 0;
        
        //check from left, the smaller number which are  placed after a greater number
        //then find the actual position of that element 
        //repeat for all and find the minimum index which needs to be updated
        for (int i = 1; i < nums.size(); i++)
        {
            if(nums[i] < nums[i-1])
            {
                if(start != nums.size() - 1 && nums[i] >= nums[start]) //if current num is not less than curr num[start], ignore it
                    continue;
    
                //reduce time complexity by starting the new start from current start iff start is already set atleast once
                int j = (start == nums.size() - 1) ? i-1 : start; 
                while(j >= 0 && nums[j] > nums[i]) //find actual position when incorrect placement is found
                    j--;
                start = min(start, j+1);
                cout << "Start: " << start << endl;
            }
        }

        //check from right, the larger number which is placed before a smaller number
        //then find the actual position of that element 
        //repeat for all and find the maximum index which needs to be updated
        for (int i = nums.size() - 1; i > 0; i--)
        {
            if(nums[i] < nums[i-1])
            {
                if(end != -1 && nums[i-1] <= nums[end]) //if current num is not greater than curr num[end], ignore it
                    continue;

                //reduce time complexity by starting the new end from current end iff end is already set atleast once
                int j = end == -1 ? i : end;
                while(j < nums.size() && nums[j] < nums[i-1])  //find actual position when incorrect placement is found
                    j++;
                end = max(end, j-1);               
                cout << "End: " << end << endl; 
            }
        }
        if(start == nums.size() - 1 && end == -1)
            return 0;
        return end - start + 1;
    }
};

// Test Cases:
// [2,6,4,8,10,9,15]
// [5,4,3,2,1,0]
// [1,2,3,4]
// [1]
// [1,2,3,4,5,9,6,7,8]
// [4,6,7,8,3]
// [4,7,8,12,11,1,13,16,19,18,22,21,25,26,28,30]
// [4,7,8,12,11,1,13,16,19,18,29,22,21,25,26,28,30]
