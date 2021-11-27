class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), zero = 0;
        long long product = 1;
        vector<int> ans(n);
        for(int& num: nums) {
            if(num == 0) {
                zero++;
                if(zero >= 2) break;
            } else {
                product *= num;
            }
        }
        if(zero == 0) {
            for(int i = 0; i < n; i++) {
                ans[i] = product/nums[i];
            }
        } else if(zero == 1) {
            for(int i = 0; i < n; i++) {
                if(nums[i] == 0) ans[i] = product;
            }
        }
        return ans;
    }
};