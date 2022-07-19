class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> s(nums.begin(),nums.end());
        int res = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            //skip finding the consecutive elements if previous number in consecutive sequence exists in set
            //example - for [100,2,200,1,4,3], we start from left
            //when we reach 2, its useless to find 2,3,4 sequence as when we reach 1, we will find bigger sequence 1,2,3,4 
            //so to reduce TC, we will consider only the starting element of each consecutive sequence
            if(s.find(nums[i]-1) != s.end())
                continue;
            else
            {
                int count = 0;
                int curr = nums[i];
                
                //starting at current element in loop, check how many next consecutive numbers are present in the set
                while(s.find(curr) != s.end())
                {
                    count++;
                    curr++;
                }
                
                res = max(res, count);
            }
        }
        
        return res;
    }
};