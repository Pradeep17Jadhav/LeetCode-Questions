class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, int> map;
        int res = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < arr.size(); i++)
        {
            res = (res + map[target - arr[i]]) % mod;
            for (int j = 0; j < i; j++)
            {
                map[arr[i] + arr[j]]++;
            }
        }
        return res;
    }
};