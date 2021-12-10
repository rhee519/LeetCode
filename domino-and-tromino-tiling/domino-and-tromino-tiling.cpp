class Solution {
public:
    int mod = 1e9+7;
    int numTilings(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        long long ans = 2, prev = 1, upper = 1, lower = 1;
        for(int i = 3; i <= n; i++) {
            long long ans_temp = ans, prev_temp = prev, upper_temp = upper, lower_temp = lower;
            // ans_temp: dp[i-1]
            // prev_temp: dp[i-2]            
            ans = ans + prev + upper + lower;
            ans %= mod;
            upper = prev + lower_temp;
            lower = prev + upper_temp;
            prev = ans_temp;
        }
        return ans;
    }
};