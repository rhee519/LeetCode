class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell = 0, buy = -prices[0], pre_sell, pre_buy;
        
        for(int price: prices) {
            pre_sell = sell;
            pre_buy = buy;
            sell = max(pre_sell, pre_buy + price);
            buy = max(pre_buy, pre_sell - price);
        }
        
        return sell;
    }
};