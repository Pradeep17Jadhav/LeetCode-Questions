class Solution {
public:
    int k = 0;
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int mid;
        
        //Consider example [0,1,2,3,4,5,6,7], target = 2

        while(l <= r)
        {
            mid = (l + r) / 2;
            if(nums[mid] == target)
                return true;
    
            //The main intuition is, there are 2 cases for this problem
            //either left part is sorted, or right part is sorted
            
            //Case 1 - left part is sorted, ex - [3,4,5,6,7,0,1,2]
            //Note - mid element is always ignored as it is already matched at the start of iteration
            //As duplication allowed, we cannot rely on <= (exmaple case - [1,0,1,1,1], target=0)
            if(nums[l] < nums[mid]) 
            {
                //check if target lies within the left sorted part
                //if yes, then remove all the right part
                if(nums[l] <= target && target <= nums[mid])
                    r = mid;
                
                //if no, then remove the whole left part
                else
                    l = mid+1;
            }
            //Case 2 - right part is sorted, ex- [5,6,7,0,1,2,3,4]
            else if(nums[l] > nums[mid])
            {
                //check if target lies in right part
                //if yes, remove the left part
                if(nums[mid] <= target && target <= nums[r])
                    l = mid;
                
                //if no, remove the right part
                else
                    r = mid-1;
            }
            else
                l++;
        }
        return false;
    }
};