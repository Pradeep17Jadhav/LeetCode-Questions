class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        // return usingSort(nums);
        return usingSearch(nums);
    }
    
    //time complexity - O(nlogn)
    int usingSort(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        return (nums[nums.size() - 1] * nums[nums.size() - 2]) - (nums[0] * nums[1]);
    }
    
    //time complexity - O(N)
    int usingSearch(vector<int>& nums)
    {
        int minlow, minhigh, maxlow, maxhigh;
        minlow = minhigh = INT_MAX;
        maxlow = maxhigh = INT_MIN;
        
        for(int i:nums)
        {
            if(i < minlow)
            {
                minhigh = minlow;
                minlow = i;
            }
            else if(i < minhigh)
            {
                minhigh = i;
            }
            
            if(i > maxhigh)
            {
                maxlow = maxhigh;
                maxhigh = i;
            }
            else if(i > maxlow)
            {
                maxlow = i;
            }
        }

        return ((maxhigh * maxlow) - (minlow * minhigh));
    }
};