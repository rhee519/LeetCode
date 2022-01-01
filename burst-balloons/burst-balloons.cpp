class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size(); // 원래 nums의 원소의 개수
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
        // dp[l][r] == nums[l]부터 nums[r-1]까지를 제거하여 얻을 수 있는 최대 coin
        return dnc(nums, dp, 1, n+1);
    }
    
    int dnc(vector<int>& nums, vector<vector<int>>& dp, int l, int r) {
        if(l >= r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        int ans = 0;
        for(int i = l; i < r; i++) {
            ans = max(ans, dnc(nums, dp, l, i) + dnc(nums, dp, i+1, r) + nums[l-1]*nums[i]*nums[r]);
        }
        return dp[l][r] = ans;
    }
};