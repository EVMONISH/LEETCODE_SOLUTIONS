class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int lowest_price = INT_MAX;
        int max_profit = 0;

        for(int price: prices)
        {
            if(price < lowest_price)
            {
                lowest_price = price;
            }
            else{
                max_profit = max(max_profit, price - lowest_price);
            }
        }
        return max_profit;
    }
};