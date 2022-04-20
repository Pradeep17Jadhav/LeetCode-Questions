class Solution {
public:
    //Referance - https://www.youtube.com/watch?v=-OxZTJtn8Vs
    int maxProfit(vector<int>& prices) {
        int sold = INT_MIN; 
        int held = INT_MIN; 
        int reset = 0;
        for (int i = 0; i < prices.size(); i++) 
        { 
            int prevSold = sold; 
            sold = held + prices[i]; //if stock is sold, we will have amount (previously held + the price at which we sell the stock)
            held = max(held, reset - prices[i]); //cooldown for a day or buy a stock paying current price
            reset = max(reset, prevSold); //rest period, the maximum of last rest period and the previous sold value
        }
        return max(sold, reset); 
    }
};