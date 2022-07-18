class Solution {
public:
    //reference - https://www.youtube.com/watch?v=HbbYPQc-Oo4
    //Use prefix sum and hashmap
    //Traverse from left to right and keep finding prefix sum
    //Use hashmap to store the (diff betweek prefix sum - k) and its occurrences 
    //While traversing, for each element, check the diff between current prefix sum and K.
    //If this diff is already in hashmap, it means their exists a subarray from last position in hashmap, which equals K
    //If there are multiple occurrences in hashmap, it means there are same multiple subarrays possible
    //TC: O(N)
    //SC: O(N)
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>hash;
        int res = 0;
        int cumm = 0; //to store cummulative/prefix sum
        int i = 0;
        while(i < nums.size())
        {
            cumm += nums[i];
            
            if(cumm == k) //handle subarray starting from index 0
                res += 1;
            
            if(hash.find(cumm - k) != hash.end()) //can work without this but also, but space complexity will increase
                res += hash[cumm - k]; //add total occurences in result
            hash[cumm]++;
            i++;
        }
        return res;
    } 
};

//try this test case:
//[3,4,7,2,-3,1,4,2]
//k = 7
