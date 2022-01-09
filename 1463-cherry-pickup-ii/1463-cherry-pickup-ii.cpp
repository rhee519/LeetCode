class Solution {
public:
    int d[3] = {-1, 0, 1};
    bool check(int n, int j) {
        return 0 <= j and j < n;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n, vector<int>(n)));
        // dp[i][j][k] == max profit on ith row
        // where #1 on (i, j) && #2 on (i, k)
        // bottom-up approach
        for(int i = m-1; i >= 0; i--) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    int pick = (j == k)? grid[i][j] : grid[i][j]+grid[i][k];
                    for(int d1 = 0; d1 < 3; d1++) {
                        int from1 = j+d[d1];
                        if(!check(n, from1)) continue;
                        for(int d2 = 0; d2 < 3; d2++) {
                            int from2 = k+d[d2];
                            if(!check(n, from2)) continue;
                            dp[i][j][k] = max(dp[i][j][k], dp[i+1][from1][from2]);
                        }
                    }
                    dp[i][j][k] += pick;
                }
            }
        }
        return dp[0][0][n-1];
    }
};