class Solution {
public:
    // Intuition -
    // "Buy on first day, sell it on second day, then buy it on second, sell it on third day"
    // Above line equals "buy it on first and sell it on third day"
    // Ex - [1,2,4,5] = Ans Profit = 4 ... [Buy for 1, sell for 5]
    // Which eqals - [2-1]=1 + [4-2]=2 + [5-4]=1 = 1+2+1 = 4
    int maxProfit(vector<int> &prices) {
        int ret = 0;
        for (int i = 1;i < prices.size(); i++)
        {
            ret += max(prices[i] - prices[i - 1], 0);    
        }
        return ret;
    }
};