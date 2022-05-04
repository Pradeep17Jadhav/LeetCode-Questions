class Solution {
public:
    //SIMILAR TO TWO SUMS
    int maxOperations(vector<int>& nums, int k) {
        return maxOperations_1(nums, k);
        // return maxOperations_2(nums, k);
    }

    //TC: O(N)
    //SC: O(N)
    int maxOperations_1(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int res = 0;
        for(int &i: nums)
        {
            if(hash[k-i] && hash[k-i] > 0)
            {
                res++;
                hash[k-i]--;
            }
            else {
                hash[i]++;
            }
        }
        return res;
    }

    //TC: O(NlogN)
    //SC: O(1)    
    int maxOperations_2(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;
        int res = 0;
        while(i < j)
        {
            int sum = nums[i] + nums[j];
            if(sum == k)
            {
                i++;
                j--;
                res++;
            }
            else if(sum < k)
                i++;
            else
                j--;
        }
        return res;
    }
};
