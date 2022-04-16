class Solution {
public:
    //Same as house robbing problem
    int deleteAndEarn(vector<int>& nums) {        
        return deleteAndEarn_1(nums);
        // return deleteAndEarn_2(nums);
    }

    //TC: O(N)
    //SC: O(1) //constant sized array is used
    int deleteAndEarn_1(vector<int>& nums) {
        int n = 10001;
        vector<int> dp(n);
        for (int num : nums)
            dp[num] += num;

        int a = 0, b = 0, c;
        for (int i = 0; i < n; i++) {
            c = max(a + dp[i], b);
            a = b;
            b = c;
        }
        return max(a, b);
    }

    //TC: O(N)
    //SC: O(2*1) = O(1) //two constant sized arrays are used
    int deleteAndEarn_2(vector<int>& nums) {
        int n = 10001;
        vector<int> sum(n);
        vector<int> dp(n);
        for (int num : nums)
            sum[num] += num;

        dp[0] = sum[0];
        dp[1] = sum[1];
        for (int i = 2; i < n; i++) {
            dp[i] = max(sum[i] + dp[i-2], sum[i-1]);
        }
        
        return max(dp[n-1], dp[n-2]);
    }
};