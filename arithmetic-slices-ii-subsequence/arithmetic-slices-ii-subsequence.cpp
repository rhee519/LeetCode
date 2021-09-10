class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<unordered_map<long, int>> dp(nums.size());
        // dp[i][diff] == # of arithmetic sequences [... nums[i]] with difference diff
        int cnt = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                long diff = (long)nums[i] - nums[j];
                dp[i][diff]++;
                if(dp[j].find(diff) != dp[j].end()) {
                    // there exists k < j < i s.t. [... nums[k], nums[j], nums[i]] is arith seq
                    // we found new arith seq [... nums[j]]
                    dp[i][diff] += dp[j][diff];
                    cnt += dp[j][diff];
                }
            }
        }
        
        return cnt;
    }
};