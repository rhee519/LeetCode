class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, min_buy = prices[0];
        for(int price: prices) {
            ans = max(ans, price-min_buy);
            min_buy = min(min_buy, price);
        }
        return ans;
    }
};