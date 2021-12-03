class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN, prod = 1, neg = 1;
        for(int num: nums) {
            prod *= num;
            ans = max(ans, max(prod, prod/neg));
            if(num == 0) {
                prod = neg = 1;
            } else if(neg > 0) {
                neg *= num;
            }
        }
        return ans;
    }
};