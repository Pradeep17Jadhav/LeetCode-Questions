class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int res = 0;
        int cur = INT_MIN; 
        for(int i:prices) 
        {
            int temp = res;
            res = max(res, i+cur);
            cur = max(cur, temp-i-fee);
        }
        return res;
    }
};