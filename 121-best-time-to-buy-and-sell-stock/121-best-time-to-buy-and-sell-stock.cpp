class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, min_buy = prices[0];
        for(int price: prices) {
            min_buy = min(min_buy, price);
            ans = max(ans, price-min_buy);
        }
        return ans;
    }
};