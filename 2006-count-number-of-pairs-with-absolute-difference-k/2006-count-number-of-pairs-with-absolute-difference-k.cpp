class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        //since constraints are 1 <= nums[i] <= 100 we can use vector
        vector<int> hash(101);
        int res = 0;
        for(int &i: nums)
            hash[i]++;
        
        for(int i = 0; i + k < hash.size(); i++)
        {
            //assume [4,4,4,5,6,6] and k=2
            //we have ans [(4,5),(4,5),(4,5),(4,5),(4,5),(4,5)];
            //which is equal to (3 * "4") * (2 * "6")
            //so we use 3 * 2
            res += hash[i] * hash[i + k];
        }

        return res;
    }
};