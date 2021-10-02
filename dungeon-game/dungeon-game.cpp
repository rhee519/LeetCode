class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m, (vector<int>(n)));
        // dp[i][j] = lost HP from (i,j) to (m-1, n-1)
        dp[m-1][n-1] = min(dungeon[m-1][n-1], 0);
        for(int i = m-2; i >= 0; i--) {
            dp[i][n-1] = min(dp[i+1][n-1]+dungeon[i][n-1], 0);
        }
        for(int j = n-2; j >= 0; j--) {
            dp[m-1][j] = min(dp[m-1][j+1]+dungeon[m-1][j], 0);
        }
        
        for(int i = m-2; i >= 0; i--) {
            for(int j = n-2; j >= 0; j--) {
                dp[i][j] = min(max(dp[i+1][j], dp[i][j+1]) + dungeon[i][j], 0);
            }
        }
        
        return -dp[0][0]+1;
    }
};