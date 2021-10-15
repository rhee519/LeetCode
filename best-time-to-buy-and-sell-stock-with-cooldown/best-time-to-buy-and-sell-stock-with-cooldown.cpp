class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = INT_MIN, sell = 0, prev_buy = 0, prev_sell = 0;
        int cnt = 0;
        for(int price: prices) {
            prev_buy = buy;
            buy = max(prev_sell-price, buy);
            // prev_sell-price: 오늘 구매, buy: 오늘 구매 안 함
            prev_sell = sell;
            sell = max(prev_buy+price, sell);
            // prev_buy+price: 오늘 판매, sell: 오늘 판매 안 함
            printf("day %d - prev_buy: %d, buy: %d, pre_sell: %d, sell: %d\n", cnt++, prev_buy, buy, prev_sell, sell);
        }
        
        return sell;
    }
};