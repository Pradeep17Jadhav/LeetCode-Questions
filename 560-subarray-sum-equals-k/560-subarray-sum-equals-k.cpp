class Solution {
public:
    //reference - https://www.youtube.com/watch?v=HbbYPQc-Oo4
    //TC: O(N^2)
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>hash;
        int res = 0;
        int cumm = 0; //to store cummilative/prefix sum
        int i = 0;
        hash[0]++; // to count subarrays which starts at index 0;
        while(i < nums.size())
        {
            cumm += nums[i];
            if(hash.find(cumm - k) != hash.end()) //can work without this but also, but space complexity will increase
                res += hash[cumm - k];
            hash[cumm]++;
            i++;
        }
        return res;
    } 
};

//try this test case:
//[3,4,7,2,-3,1,4,2]
//k = 7
