class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;
        
        for(int i: prices)
        {
            minPrice = min(i, minPrice);
            maxProfit = max(i - minPrice, maxProfit);
        }
        return maxProfit;
    }
};