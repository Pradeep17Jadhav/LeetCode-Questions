class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // return searchRange_1(nums, target);
        return searchRange_2(nums, target);
    }

    vector<int> searchRange_2(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> res(2, -1);
        if(!size)
            return res;
        int start = 0;
        int end = size-1;
        
        // Search for the left end position
        while(start < end)
        {
            int mid = (start + end) /2;
            if (nums[mid] < target)
                start = mid + 1;
            else 
                end = mid;
        }
        
        if(nums[start] != target) //left end not found 
            return res;
        else 
            res[0] = start;

        // Search for the right end position
        end = size-1;  // We don not have to set 'left' to 0 the second time.
        while (start < end)
        {
            int mid = (start + end)/2 + 1;	// make mid biased to the right
            if (nums[mid] > target) 
                end = mid - 1;  
            else 
                start = mid;
        }
        res[1] = end;
        
        return res; 
    }
    
//     vector<int> searchRange_1(vector<int>& nums, int target) {
//         int start = 0;
//         int end = nums.size() - 1;
//         int mid;
        
//         while(start <= end)
//         {
//             mid = (start + end) / 2;
//             if(nums[mid] == target)
//             {
//                 start = end = mid;
//                 while(start >=0 && start < nums.size() && nums[start] == target)
//                     start--;
//                 while(end >=0 && end < nums.size() && nums[end] == target)
//                     end++;

//                 return {start+1, end-1};
//             }
//             else if(nums[mid] < target)
//             {
//                 start = mid+1;
//             }
//             else if(nums[mid] > target)
//             {
//                 end = mid-1;
//             }
//         }
        
//         return {-1,-1};
//     }

};