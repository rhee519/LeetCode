class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int num: nums) {
            sum += num;
        }
        vector<vector<bool>> dp(n, vector<bool>(sum+1));
        // dp[i][j] := nums[0:i]로 j를 만들 수 있는지 여부
        if(sum%2) return false;
        dp[0][nums[0]] = true;
        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= sum; j++) {
                dp[i][j] = dp[i-1][j];
                if(j-nums[i] > 0)
                    dp[i][j] = dp[i][j] or dp[i-1][j-nums[i]];
            }
        }
        return dp[n-1][sum/2];
    }
};