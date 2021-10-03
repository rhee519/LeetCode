class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n);
        dp[n-1] = true;
        for(int i = n-2; i >= 0; i--) {
            if(i + nums[i] >= n-1) dp[i] = true;
            else { // i + nums[i] < n-1
                dp[i] = false;
                for(int j = i+1; j <= i+nums[i]; j++) {
                    if(dp[j]) {
                        dp[i] = true; break;
                    }
                }
            }
        }
        
        return dp[0];
    }
};