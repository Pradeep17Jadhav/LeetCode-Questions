class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4)
            return {};

        return fourSum_2(nums, target);
        // return fourSum_1(nums, target);
    }
    
    //Naive approach is to use 4 nested for loops for each digit and then remove duplicates using hast
    //This approach will have TC: O(N^4)
    
    
    //Solution 1 - Brute Force
    //TC: nlogn (sorting) * n^3 (traversing 3 ptrs) * logn (binary search) = HORRIBLE
    //SC: O(N + 1) = O(N) (for hash to remove duplicates and ignoring space used by res)
    vector<vector<int>> fourSum_1(vector<int>& nums, int target) {
        int remaining;
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end()); //sort the array so that we can traverse left to right
        
        //create 3 pointers i, j, k to carry values of 3 numbers
        //since a, b, c, and d are distinct as per constraints, start - j=i+1 and k=j+1
        for(int i = 0; i < nums.size(); i++)
        {    
            for(int j = i+1; j < nums.size(); j++)
            {
                for(int k = j+1; k < nums.size(); k++)
                {
                    //once we have 3 numbers, we have to find 4th number which make total sum==target
                    //since the RHS is also sorted, we can use binary search to find the 4th required number
                    remaining = target - nums[i] - nums[j] - nums[k];
                    int start = k+1;
                    int end = nums.size() - 1;
                    while(start <= end) {
                        int mid = (start + end)/2;

                        //when 4th num is found, add it to result and break loop to continue with next k
                        if(nums[mid] == remaining) {
                            res.push_back({nums[i], nums[j], nums[k], nums[mid]});
                            break;
                        }
                        else if(nums[mid] > remaining) 
                            end = mid-1;
                        else 
                            start = mid+1;
                    }
                    
                }
            }
        }
        
        //since the res vector can have duplicate vectors quadraplets, we can use set or hash to find unique quadraplets
        set<vector<int>> hash;
        for(auto &v: res)
            hash.insert(v);
        
        res.clear();
        for(auto &v: hash)
            res.push_back(v);

        return res;
    }

    //Optimisation of Solution 1
    //TC is reduced and SC will be O(1)
    //TC: O(NlogN * N^2 * N) (sorting + 2 pointer loops + traverse RHS using left-right ptrs)
    //SC: O(1) (ignoring space used by res)
    vector<vector<int>> fourSum_2(vector<int>& nums, int target) {
        int left, right, oldLeft, oldRight, remaining;
        int n = nums.size();
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end()); //sort the array so that we can traverse left to right

        //Use only 2 ptrs i and j for first and second element resp.
        //Then on RHS, we can make use of sorted array 
        //Use left and right ptrs as 3rd and 4th number ptrs
        //On finding each quadraple, we skip the index having same number so duplicates are avoided
        
        //End i at <size-3 as those 3 numbers should be used by j,left,right
        for(int i = 0; i < n-3; i++)
        {
            //skip duplicate i
            if(i > 0 && nums[i] == nums[i-1]) continue;

            //skip unncessary traversal if first 4 elements from curr i equals greater than target
            // if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break; //overflow int - so use like below
            if(nums[i] + nums[i+1] > target - nums[i+2] - nums[i+3]) break;
            
            //skip current i if (last 3 elements + curr i) is less than target as curr i is too small for answer
            // if(nums[i] + nums[n-3] + nums[n-2] + nums[n-1] < target) continue; //overflow int - so use like below
            if(nums[i] + nums[n-3] < target - nums[n-2] - nums[n-1]) continue;

            //End j at <size-2 as those 2 numbers should be used by left,right
            for(int j = i+1; j < n-2; j++) //change j at end of loop
            {
                if(j > i+1 && nums[j] == nums[j-1]) continue; //skip duplicate j
                if(nums[i] + nums[j] > target - nums[j+1] - nums[j+2]) break;
                if(nums[i] + nums[j] < target - nums[n-2] - nums[n-1]) continue;
                
                remaining = target - nums[i] - nums[j];
                left = j+1;
                right = nums.size() - 1;
                
                while(left < right) //note that <= cant be used as we should have distinct left and right ptrs
                {
                    int LRsum = nums[left] + nums[right];
                    
                    //if LRSum < remaining, we cant reduce right as it will also reduce LRSum
                    //if we increase right, since the array is sorted, LRSum will increase
                    if(LRsum < remaining) 
                        left++;
                    else if(LRsum > remaining) //similar to above note, we should reduce right ptr
                        right--;
                    else //LR sum matches to remaining
                    {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        oldLeft = left;
                        oldRight = right;
                        
                        while(left < right && nums[left] == nums[oldLeft]) //incr left ptr while skipping duplicates
                            left++;

                        while(left < right && nums[right] == nums[oldRight]) //decr right ptr while skipping duplicates
                            right--;
                    }
                }
            }
        }
        
        return res;
    }
};