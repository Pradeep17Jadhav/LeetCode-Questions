class Solution {
public:
    //reference - https://www.youtube.com/watch?v=HbbYPQc-Oo4
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>hash;
        int res = 0;
        int cumm = 0;
        int i = 0;
        while(i < nums.size())
        {
            cumm += nums[i];
            if(cumm == k)
                res++;
            
            res += hash[cumm - k];
            hash[cumm]++;
            i++;
        }
        return res;
    } 
};
