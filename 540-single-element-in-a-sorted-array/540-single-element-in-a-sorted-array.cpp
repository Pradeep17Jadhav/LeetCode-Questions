class Solution {
public:
    //Binary Search
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while(left < right) {
            //we will imagine pair of 2 elements to solve this problem
            //i.e. indices = [(0,1),(2,3),(4,5),(6,7).....]
            //so mid should always be at even place
            int mid = (left+right) / 2;
            if(mid % 2 == 1)
                mid--;
            
            //if current pair is equal, then answer must be in the right part bcz left part have pairs of 
            //eg - values = [(1,1), (3,3), (4,8) ,8)]
            if(nums[mid] == nums[mid+1])
                left = mid+2;
            
            //if current pair is NOT equal, then answer must be in the left part
            //eg - values = [(1,2), (2,3), (3,4), (4,8), 8]
            else
                right = mid-1;
            
        }
        
        //for us, left is always at the beginning of a pair.
        // When 'left >= right', start must be the single element which is at 'left' index.
        return nums[left];
    }
};

// [1,1,2,3,3,4,4,8,8]
// [3,3,7,7,10,11,11]
// [1,2,2,3,3,4,4]
// [1,1,2,2,3,4,4,5,5]
// [1,1,2,2,3,3,4]
// [1,1,2,2,3,4,4]