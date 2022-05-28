class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;
        
        for(int i: prices)
        {
            //keep on finding min price. We are finding minPrice before calculating profit, so buy is guaranteed to be before sell.
            minPrice = min(i, minPrice); //keep on finding minimum value element in the array
            maxProfit = max(maxProfit, i - minPrice);
        }
        return maxProfit;
    }
};